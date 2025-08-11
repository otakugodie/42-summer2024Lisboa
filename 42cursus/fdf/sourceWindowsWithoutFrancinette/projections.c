/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:42:29 by diegfern          #+#    #+#             */
/*   Updated: 2025/07/20 17:15:36 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Recorre el map para calcular los screen_x y los screen_y correspondientes a cada relacion x,y,z para convertirlos a 2D isometricos*/
int	isometric_projection (t_map **map, int height, int width, t_projection *projection)
{
	int x;
	int y;
	double angle_radians; 
	angle_radians = (30 * M_PI) / 180.0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			map[y][x].screen_x = (((map[y][x].x - map[y][x].y) * cos(angle_radians)) *  projection->zoom) + projection->offset_x;

			map[y][x].screen_y = (((map[y][x].x + map[y][x].y) * sin(angle_radians) - map[y][x].z * projection->elevation) * projection->zoom) + projection->offset_y;
			x++;
		}
		y++;
	}
	return (0);
}

/*Estima el tamaño que ocupará el mapa en proyección isométrica, calcula el zoom necesario para que quepa en el 80% de la ventana (dejando 20% de margen), y devuelve el menor de los dos zooms (horizontal/vertical) para garantizar que quepa completamente.*/
float calculate_auto_zoom(int width, int height, int window_width, int window_height)
{
	float map_screen_width;
	float map_screen_height;
	float zoom_x;
	float zoom_y;

	map_screen_width = (width + height) * cos(30 * M_PI / 180.0);
	map_screen_height = (width + height) * sin(30 * M_PI / 180.0);

	zoom_x = (window_width * 0.8) / map_screen_width;
	zoom_y = (window_height * 0.8) / map_screen_height;

	return (zoom_x < zoom_y) ? zoom_x : zoom_y;
}

/*
Calcula las dimensiones óptimas de ventana basándose en el tamaño del mapa.
Usa un tamaño mínimo predefinido o calcula uno proporcional al mapa con margen, seleccionando siempre el mayor para garantizar que el contenido sea visible.
*/
void	calculate_window_size(int width, int height, int *window_width, int *window_height)
{

	int min_width;
	int min_height;
	int recommended_width;
	int recommended_height;

	min_width = WINDOW_WIDTH;
	min_height = WINDOW_HEIGHT;

	recommended_width = (width + height) * 20 + 200;
	recommended_height = (width + height) * 15 + 200;

	*window_width = (recommended_width > min_width) ? recommended_width : min_width;
	*window_height = (recommended_height > min_height) ? recommended_height : min_height;
}
