/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 12:20:00 by diegfern          #+#    #+#             */
/*   Updated: 2025/08/10 12:44:03 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Cuenta elementos en el array split,
	valida que no exceda el ancho esperado y en caso de error,
	libera memoria y termina el programa*/
int	validate_line_width(char **split, int expected_width, int line_num)
{
	int	count;

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

/* toma un elemento individual del archivo (como un string) y lo 
	convierte en datos estructurados,sea un numero o numero con , 
	y el código del color (0x)*/
void	parse_point_value(char *element, t_map *point, int x, int y)
{
	char	*z_sep;

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

/*Procesa todos los puntos/elementos de una línea del archivo y los 
convierte en estructuras t_map con sus coordenadas (x,y,z) y color.*/
int	process_line_data(char **split, t_map *map_row, int width, int y)
{
	int	x;

	x = 0;
	while (split[x] && x < width)
	{
		parse_point_value(split[x], &map_row[x], x, y);
		x++;
	}
	return (0);
}

/*Procesa la primera línea para obtener el ancho del mapa*/
static void	process_first_line(char *line, int *width)
{
	char	**split;

	split = ft_split(line, ' ');
	while (split[*width])
		(*width)++;
	cleanup_split_array(split);
}

/*Procesa una línea del archivo para contar dimensiones*/
int	process_dimension_line(char *line, int *height, int *width)
{
	(*height)++;
	if (*height == 1)
		process_first_line(line, width);
	free(line);
	return (0);
}
