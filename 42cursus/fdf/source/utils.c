/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:51:48 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/06 13:40:45 by diegfern         ###   ########.fr       */
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

void	free_map_and_resources(t_vars *vars)
{
	int	i;

	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
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
