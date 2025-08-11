/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:43:07 by diegfern          #+#    #+#             */
/*   Updated: 2025/07/20 17:23:44 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// Función auxiliar para obtener el valor absoluto
static int absolute_value(int value)
{
	return (value < 0) ? -value : value;
}

//Funciones para dibujar linea
static void init_bresenham(t_map p1, t_map p2, t_bresenham *vars_bres)
{
	vars_bres->dx = absolute_value(p2.screen_x - p1.screen_x);
	vars_bres->dy = absolute_value(p2.screen_y - p1.screen_y);
	vars_bres->sx = (p1.screen_x < p2.screen_x) ? 1 : -1;
	vars_bres->sy = (p1.screen_y < p2.screen_y) ? 1 : -1;
	vars_bres->err = vars_bres->dx - vars_bres->dy;
	vars_bres->total_distance = vars_bres->dx + vars_bres->dy;
}

static void init_line_position(t_map point, t_line_pos *pos)
{
	pos->x = point.screen_x;
	pos->y = point.screen_y;
	pos->current_distance = 0;
}

/*Calcul el color interpolado*/
static unsigned int get_interp_color(unsigned int c1, unsigned int c2, int current_dist, int total_dist)
{
	float t;

	if (total_dist > 0)
		t = (float)current_dist / (float)total_dist;
	else
		t = 0.0;
	return (interp_color(c1, c2, t));
}

static void update_position(t_bresenham *vars_bres, t_line_pos *pos)
{
	int e2;

	e2 = 2 * vars_bres->err;
	if (e2 > -vars_bres->dy)
	{
		vars_bres->err -= vars_bres->dy;
		pos->x += vars_bres->sx;
		pos->current_distance++;
	}
	if (e2 < vars_bres->dx)
	{
		vars_bres->err += vars_bres->dx;
		pos->y += vars_bres->sy;
		pos->current_distance++;
	}
}

// Función para dibujar una línea entre dos puntos usando el algoritmo de Bresenham con interpolación de color
void draw_line(t_vars *vars, t_map point1, t_map point2)
{
	t_bresenham vars_bres;
	t_line_pos pos;
	unsigned int cur_color;

	init_bresenham(point1, point2, &vars_bres);
	init_line_position(point1, &pos);

	while (1)
	{
		cur_color = get_interp_color(point1.color, point2.color, pos.current_distance, vars_bres.total_distance);
		mlx_pixel_put(vars->mlx, vars->win, pos.x, pos.y, cur_color);
		
		if (pos.x == point2.screen_x && pos.y == point2.screen_y)
			break;
			
		update_position(&vars_bres, &pos);
	}
}

// Función para dibujar el wireframe completo del mapa
void draw_wireframe(t_vars *vars)
{
	int x;
	int y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			// Dibujar línea hacia la derecha (si no es la última columna)
			if (x < vars->width - 1)
				draw_line(vars, vars->map[y][x], vars->map[y][x + 1]);

			// Dibujar línea hacia abajo (si no es la última fila)
			if (y < vars->height - 1)
				draw_line(vars, vars->map[y][x], vars->map[y + 1][x]);

			x++;
		}
		y++;
	}
}

// Función para dibujar el mapa completo (wireframe + puntos)
void render_map(t_vars *vars)
{
	clear_window(vars);
	draw_wireframe(vars);
}
