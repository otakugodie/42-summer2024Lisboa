/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:43:07 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/06 13:43:48 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_line_position(t_map point, t_line_pos *pos)
{
	pos->x = point.screen_x;
	pos->y = point.screen_y;
	pos->current_distance = 0;
}

/*Calcula el color interpolado*/
static unsigned int	get_interp_color(unsigned int c1, unsigned int c2,
		int current_dist, int total_dist)
{
	float	t;

	if (total_dist > 0)
		t = (float)current_dist / (float)total_dist;
	else
		t = 0.0;
	return (interp_color(c1, c2, t));
}

/* Función para dibujar una línea entre dos puntos usando el algoritmo
de Bresenham con interpolación de color*/
void	draw_line(t_vars *vars, t_map point1, t_map point2)
{
	t_bresenham		vars_bres;
	t_line_pos		pos;
	unsigned int	cur_color;

	init_bresenham(point1, point2, &vars_bres);
	init_line_position(point1, &pos);
	while (1)
	{
		cur_color = get_interp_color(point1.color, point2.color,
				pos.current_distance, vars_bres.total_distance);
		my_mlx_pixel_put(vars, pos.x, pos.y, cur_color);
		if (pos.x == point2.screen_x && pos.y == point2.screen_y)
			break ;
		update_position(&vars_bres, &pos);
	}
}

// Función para dibujar el wireframe completo del mapa
void	draw_wireframe(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (x < vars->width - 1)
				draw_line(vars, vars->map[y][x], vars->map[y][x + 1]);
			if (y < vars->height - 1)
				draw_line(vars, vars->map[y][x], vars->map[y + 1][x]);
			x++;
		}
		y++;
	}
}

// Función para dibujar el mapa completo (wireframe + puntos)
// Con cambio a imagen, limpia el buffer,
// dibuja en el buffer no en la pantalla y hace un solo llamado 
// para poner la imagen en la pantalla
void	render_map(t_vars *vars)
{
	clear_image_buffer(vars);
	draw_wireframe(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
