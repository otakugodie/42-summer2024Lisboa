/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:17:12 by diegfern          #+#    #+#             */
/*   Updated: 2025/07/20 17:06:38 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Libera la memoria de una matriz bidimensional de estructuras t_map.
 Primero libera cada fila individualmente, luego el array principal de punteros, evitando memory leaks 
 al finalizar el programa o en caso de error.
*/
void free_map(t_map **map, int height)
{
	int i;

	if (!map)
		return;

	i = 0;
	while (i < height)
	{
		if (map[i])
		{
			free(map[i]);
			map[i] = NULL;
		}
		i++;
	}

	free(map);
}

/*Inicializa el sistema MLX y configura la estructura base*/
static int initialize_mlx_system(t_vars *vars, t_map **map, int height)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		write(2, "Error: No se pudo inicializar MLX\n", 34);
		free_map(map, height);
		return (-1);
	}
	return (0);
}

/*Configura ventana, proyección y parámetros gráficos*/
static int setup_window_and_projection(t_vars *vars, int width, int height, t_projection *projection)
{
	int win_width;
	int win_height;
	float auto_zoom;

	calculate_window_size(width, height, &win_width, &win_height);
	auto_zoom = calculate_auto_zoom(width, height, win_width, win_height);

	projection->zoom = auto_zoom;
	projection->offset_x = win_width / 2.5;
	projection->offset_y = win_height / 2.5;
	projection->elevation = 0.5;

	isometric_projection(vars->map, vars->height, vars->width, projection);

	vars->win = mlx_new_window(vars->mlx, win_width, win_height, WINDOW_TITLE);
	if (!vars->win)
	{
		write(2, "Error: No se pudo crear la ventana\n", 35);
		free_map(vars->map, vars->height);
		return (-1);
	}
	return (0);
}

/*Lanza la aplicación FdF iniciando el renderizado y la interactividad.
Dibuja el mapa inicial, configura los hooks de eventos y entra en el loop principal de MLX, manteniendo la ventana activa hasta que el usuario la cierre.
*/
static void launch_fdf(t_vars *vars)
{
	render_map(vars);
	setup_hooks(vars);
	mlx_loop(vars->mlx);
}

int main(int argc, char **argv)
{
	int height;
	int width;
	t_map **map;
	t_projection projection;
	t_vars vars;

	if (argc <= 1)
		return (write(1, "Usage: ./fdf <map_file>\n", 24), 1);
	if (parse_map_dimensions(argv[1], &height, &width) != 0)
		return (1);
	map = allocate_map(height, width);
	if (fill_map(argv[1], map, width) != 0)
		return (free_map(map, height), 1);
	if (initialize_mlx_system(&vars, map, height) != 0)
		return (1);
	vars.map = map;
	vars.height = height;
	vars.width = width;
	vars.projection = projection;
	if (setup_window_and_projection(&vars, width, height, &projection) != 0)
		return (1);
	vars.projection = projection;
	launch_fdf(&vars);
	return (0);
}
