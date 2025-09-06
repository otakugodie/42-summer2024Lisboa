/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:13:50 by diegfern          #+#    #+#             */
/*   Updated: 2025/07/20 16:41:31 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// Interpolación lineal entre dos valores
static int lerp_int(int start, int end, float t)
{
	return (start + (int)((end - start) * t));
}

// Extraer componente rojo de un color
static int get_red(unsigned int color)
{
	return ((color >> 16) & 0xFF);
}

// Extraer componente verde de un color
static int get_green(unsigned int color)
{
	return ((color >> 8) & 0xFF);
}

// Extraer componente azul de un color
static int get_blue(unsigned int color)
{
	return (color & 0xFF);
}

/*Funcion Interpolar RGB*/
static void interp_rgb_comp(t_rgb rgb1, t_rgb rgb2, float t, t_rgb *result)
{
	result->r = lerp_int(rgb1.r, rgb2.r, t);
	result->g = lerp_int(rgb1.g, rgb2.g, t);
	result->b = lerp_int(rgb1.b, rgb2.b, t);
}

/*Funcion para interpolar RGB*/
static void extract_rgb_comp(unsigned int color, t_rgb *rgb)
{
	rgb->r = get_red(color);
	rgb->g = get_green(color);
	rgb->b = get_blue(color);
}

// Crear color a partir de componentes R, G, B
static unsigned int create_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

// Interpolación del color entre dos colores
unsigned int interp_color(unsigned int color1, unsigned int color2, float t)
{
	t_rgb rgb1;
	t_rgb rgb2;
	t_rgb result;

	if (t <= 0.0)
		return (color1);
	if (t >= 1.0)
		return (color2);

	extract_rgb_comp(color1, &rgb1);
	extract_rgb_comp(color2, &rgb2);
	interp_rgb_comp(rgb1, rgb2, t, &result);

	return (create_color(result.r, result.g, result.b));
}
