/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:51:48 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/07 15:52:03 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Borra completamente todo el contenido visual de la ventana. Llena la
ventana con el color de fondo (negro). Prepara la ventana para nuevo contenido*/
void	clear_window(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
}

char	*clear_var(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
/*
Libera recursos gráficos y memoria del mapa.
Destruye la imagen, la ventana y el display de MLX si existen.
*/
void	free_map_and_resources(t_vars *vars)
{
	int	i;

	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	if (vars->map)
	{
		i = 0;
		while (i < vars->height)
		{
			if (vars->map[i])
			{
				free(vars->map[i]);
				vars->map[i] = NULL;
			}
			i++;
		}
		free(vars->map);
	}
}
