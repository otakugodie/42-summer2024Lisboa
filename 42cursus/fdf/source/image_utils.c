/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:22:26 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/06 13:39:04 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Escribe directamente al buffer ********************************
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < vars->img_width && y < vars->img_height)
	{
		dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

int	init_image(t_vars *vars, int width, int height)
{
	vars->img_width = width;
	vars->img_height = height;
	vars->img = mlx_new_image(vars->mlx, width, height);
	if (!vars->img)
		return (-1);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	return (0);
}

void	clear_image_buffer(t_vars *vars)
{
	int	total_bytes;

	total_bytes = vars->img_height * vars->line_length;
	ft_bzero(vars->addr, total_bytes);
}
