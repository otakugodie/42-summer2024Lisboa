/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:47:31 by diegfern          #+#    #+#             */
/*   Updated: 2025/07/20 17:25:24 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

// Hook de redraw que se ejecuta cuando la ventana necesita ser redibujada, Recalculando la proyección con parámetros actuales y luego redibuja
int redraw(void *param)
{
	t_vars *vars = (t_vars *)param;

	isometric_projection(vars->map, vars->height, vars->width, &vars->projection);
	render_map(vars);

	return (0);
}

/*Funcion de detección de teclas mediante hook: ESC, '+' o 'z' (zoom in), '-' o 'x' (zoom out), Flechas arriba, abajo, izquierda, derecha*/
int	key_hook(int keycode, void *param)
{
	t_vars *vars = (t_vars *)param;

	if (keycode == 65307)
		exit(0);
	else if (keycode == 61 || keycode == 43 || keycode == 65451 || keycode == 122)
		vars->projection.zoom *= 1.1;
	else if (keycode == 45 || keycode == 95 || keycode == 65453 || keycode == 120)
		vars->projection.zoom *= 0.9;
	else if (keycode == 65362)
		vars->projection.offset_y -= 10;
	else if (keycode == 65364) 
		vars->projection.offset_y += 10;
	else if (keycode == 65361)
		vars->projection.offset_x -= 10;
	else if (keycode == 65363)
		vars->projection.offset_x += 10;
	redraw(vars);
	return (0);
}

/*Configura los hooks de eventos MLX para la interacción con la ventana.
Establece handlers para cerrar ventana (X), detección de teclas y redibujado de la ventana (redraw), permitiendo la interactividad básica del programa FdF*/
void setup_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_hook(vars->win, 2, 1L<<0, key_hook, vars);
	mlx_expose_hook(vars->win, redraw, vars);
}
