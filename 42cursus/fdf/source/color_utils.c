/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:25:00 by diegfern          #+#    #+#             */
/*   Updated: 2025/08/10 11:38:39 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Interpolación lineal entre dos valores
int	lerp_int(int start, int end, float t)
{
	return (start + (int)((end - start) * t));
}

// Crear color a partir de componentes R, G, B
unsigned int	create_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

// Extraer componente rojo de un color
int	get_red(unsigned int color)
{
	return ((color >> 16) & 0xFF);
}

// Extraer componente verde de un color
int	get_green(unsigned int color)
{
	return ((color >> 8) & 0xFF);
}

// Extraer componente azul de un color
int	get_blue(unsigned int color)
{
	return (color & 0xFF);
}
