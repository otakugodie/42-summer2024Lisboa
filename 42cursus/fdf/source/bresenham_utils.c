/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 12:10:52 by diegfern          #+#    #+#             */
/*   Updated: 2025/08/10 12:16:25 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Función auxiliar para obtener el valor absoluto
int	absolute_value(int value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}

// Funciones para dibujar linea
void	init_bresenham(t_map p1, t_map p2, t_bresenham *vars_bres)
{
	vars_bres->dx = absolute_value(p2.screen_x - p1.screen_x);
	vars_bres->dy = absolute_value(p2.screen_y - p1.screen_y);
	if (p1.screen_x < p2.screen_x)
		vars_bres->sx = 1;
	else
		vars_bres->sx = -1;
	if (p1.screen_y < p2.screen_y)
		vars_bres->sy = 1;
	else
		vars_bres->sy = -1;
	vars_bres->err = vars_bres->dx - vars_bres->dy;
	vars_bres->total_distance = vars_bres->dx + vars_bres->dy;
}

void	update_position(t_bresenham *vars_bres, t_line_pos *pos)
{
	int	e2;

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
