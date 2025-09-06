/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:18:45 by diegfern          #+#    #+#             */
/*   Updated: 2025/08/10 12:28:28 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Bucle principal de procesamiento*/
static int	process_map_file(int fd, t_map **map, int width)
{
	char	*line;
	char	**split;
	int		y;
	int		result;

	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
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
		line = get_next_line(fd);
	}
	return (0);
}

/*Función principal que lee un archivo de mapa y llena la matriz bidimensional*/
int	fill_map(const char *filename, t_map **map, int width)
{
	int	fd;
	int	result;

	fd = open_map_file(filename);
	if (fd < 0)
		return (-1);
	result = process_map_file(fd, map, width);
	close(fd);
	return (result);
}

/*Lee un archivo para determinar las dimensiones del mapa (alto y ancho)*/
int	parse_map_dimensions(const char *filename, int *height, int *width)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (-1);
	}
	*height = 0;
	*width = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		process_dimension_line(line, height, width);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
