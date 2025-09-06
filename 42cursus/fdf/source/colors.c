/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:13:50 by diegfern          #+#    #+#             */
/*   Updated: 2025/08/10 11:38:08 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Funcion Interpolar RGB*/
static void	interp_rgb_comp(t_rgb rgb1, t_rgb rgb2, float t, t_rgb *result)
{
	result->r = lerp_int(rgb1.r, rgb2.r, t);
	result->g = lerp_int(rgb1.g, rgb2.g, t);
	result->b = lerp_int(rgb1.b, rgb2.b, t);
}

/*Funcion para interpolar RGB*/
static void	extract_rgb_comp(unsigned int color, t_rgb *rgb)
{
	rgb->r = get_red(color);
	rgb->g = get_green(color);
	rgb->b = get_blue(color);
}

// Interpolación del color entre dos colores
unsigned int	interp_color(unsigned int color1, unsigned int color2, float t)
{
	t_rgb	rgb1;
	t_rgb	rgb2;
	t_rgb	result;

	if (t <= 0.0)
		return (color1);
	if (t >= 1.0)
		return (color2);
	extract_rgb_comp(color1, &rgb1);
	extract_rgb_comp(color2, &rgb2);
	interp_rgb_comp(rgb1, rgb2, t, &result);
	return (create_color(result.r, result.g, result.b));
}
