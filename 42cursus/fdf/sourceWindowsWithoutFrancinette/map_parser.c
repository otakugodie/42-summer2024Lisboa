/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:18:45 by diegfern          #+#    #+#             */
/*   Updated: 2025/07/20 16:29:36 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Funcion para apertura segura de archivos*/
int open_map_file(const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (-1);
	}
	return (fd);
}

/*Libera memoria de un array de strings (como el resultado de ft_split)*/
void cleanup_split_array(char **split)
{
	int i;

	if (!split)
		return;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/*Libera memoria del array split (cada string individual y el array), libera memoria de la línea leída y maneja casos donde split o line puedan ser NULL*/
void cleanup_line_resources(char **split, char *line)
{
	cleanup_split_array(split);
	if (line)
		free(line);
}

/*Crea y reserva memoria para una matriz bidimensional de estructuras t_map de tamaño height x width. Primero asigna memoria para un array de punteros (filas), luego para cada fila asigna memoria para width estructuras t_map (columnas).*/
t_map **allocate_map (int height, int width)
{
	t_map **map;
	int i;

	map = malloc (sizeof(t_map *) * height);
	i = 0;
	while (i < height)
	{
		map[i] = malloc (sizeof(t_map) * width);
		i++;
	}
	return (map);
}

/*Procesa todos los puntos/elementos de una línea del archivo y los convierte en estructuras t_map con sus coordenadas (x,y,z) y color.*/
static int process_line_data(char **split, t_map *map_row, int width, int y)
{
	int x;

	x = 0;
	while (split[x] && x < width)
	{
		parse_point_value(split[x], &map_row[x], x, y);
		x++;
	}
	return (0);
}
/*Cuenta elementos en el array split, valida que no exceda el ancho esperado y en caso de error, libera memoria y termina el programa*/
static int validate_line_width(char **split, int expected_width, int line_num)
{
	int count;

	count = 0;
	while (split[count])
		count++;

	if (count > expected_width)
	{
		write(2, "Error: Line ", 12);
		ft_putnbr_fd(line_num, 2);
		write(2, " has ", 5);
		ft_putnbr_fd(count, 2);
		write(2, " columns, expected ", 18);
		ft_putnbr_fd(expected_width, 2);
		write(2, "\n", 1);
		cleanup_split_array(split);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/* toma un elemento individual del archivo (como un string) y lo convierte en datos estructurados, sea un numero o numero con , y el código del color (0x)*/
void parse_point_value(char *element, t_map *point, int x, int y)
{
	char *z_sep;
	point->x = x;
	point->y = y;
	if (!ft_strchr(element, ','))
	{
		point->z = ft_atoi(element);
		point->color = DEFAULT_COLOR;
	}
	else
	{
		z_sep = ft_strchr(element, ',');
		*z_sep = '\0';
		point->z = ft_atoi(element);
		if (*(z_sep + 1) == '0' && (*(z_sep + 2) == 'x' || *(z_sep + 2) == 'X'))
			point->color = ft_atoi_base(z_sep + 1);
		else
			point->color = ft_atoi(z_sep + 1);
	}
}
/*Bucle principal de procesamiento*/
static int process_map_file(int fd, t_map **map, int width)
{
	char *line;
	char **split;
	int y;
	int result;

	y = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		split = ft_split(line, ' ');
		if (validate_line_width(split, width, y + 1) != 0)
		{
			cleanup_line_resources(split, line);
			return (-1);
		}
		result = process_line_data(split, map[y], width, y);
		cleanup_line_resources(split, line);
		if (result != 0)
			return (-1);
		y++;
	}
	return (0);
}

/*Función principal que lee un archivo de mapa y llena la matriz bidimensional*/
int fill_map(const char *filename, t_map **map, int width)
{
	int fd;
	int result;

	fd = open_map_file(filename);
	if (fd < 0)
		return (-1);

	result = process_map_file(fd, map, width);
	close(fd);

	return (result);
}

/*Lee un archivo para determinar las dimensiones del mapa (alto y ancho)*/
int parse_map_dimensions(const char *filename, int *height, int *width)
{
	char *line;
	char **split;
	int fd;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (-1);
	}
	*height = 0;
	*width = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		(*height)++;
		if (*height == 1)
		{
			split = ft_split(line, ' ');
			while (split[*width])
				(*width)++;
			cleanup_split_array(split);
		}
		free(line);
	}
	close(fd);
	return (0);
}