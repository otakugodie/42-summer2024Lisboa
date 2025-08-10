/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 12:20:00 by diegfern          #+#    #+#             */
/*   Updated: 2025/08/10 12:44:03 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Funcion para apertura segura de archivos*/
int	open_map_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (-1);
	}
	return (fd);
}

/*Libera memoria de un array de strings (como el resultado de ft_split)*/
void	cleanup_split_array(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/*Libera memoria del array split (cada string individual y el array),
	libera memoria de la línea leída y maneja casos donde split 
	o line puedan ser NULL*/
void	cleanup_line_resources(char **split, char *line)
{
	cleanup_split_array(split);
	if (line)
		free(line);
}

/*Crea y reserva memoria para una matriz bidimensional de estructuras 
t_map de tamaño height x width. Primero asigna memoria para un array 
de punteros (filas), luego para cada fila asigna memoria para width 
estructuras t_map (columnas).*/
t_map	**allocate_map(int height, int width)
{
	t_map	**map;
	int		i;

	map = malloc(sizeof(t_map *) * height);
	i = 0;
	while (i < height)
	{
		map[i] = malloc(sizeof(t_map) * width);
		i++;
	}
	return (map);
}
