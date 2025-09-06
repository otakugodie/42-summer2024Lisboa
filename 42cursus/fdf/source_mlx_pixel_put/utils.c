/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:51:48 by diegfern          #+#    #+#             */
/*   Updated: 2025/08/10 11:14:36 by diegfern         ###   ########.fr       */
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
