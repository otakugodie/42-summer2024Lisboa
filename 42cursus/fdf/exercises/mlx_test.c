/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 22:16:45 by diegfern          #+#    #+#             */
/*   Updated: 2025/06/27 22:16:46 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main(void)
{
    void *mlx;
    void *win;
	int i;

    mlx = mlx_init();
	win = mlx_new_window(mlx, 950, 540, "Hello world!");
	mlx_pixel_put(mlx, win, 200, 150, 0xFF0000);
	mlx_pixel_put(mlx, win, 200, 151, 0x00FF00);
	mlx_pixel_put(mlx, win, 200, 152, 0x0000FF);

	for (i = 0; i < 100; i++)
        mlx_pixel_put(mlx, win, 100 + i, 100, 0x0000FF);

	//mlx_pixel_put(mlx, win, 200, 151, 0xFFFF00);
	//mlx_pixel_put(mlx, win, 200, 152, 0xFFFFFF);	//Blanco
	//mlx_pixel_put(mlx, win, 200, 153, 0x000000);	//Negro
    mlx_loop(mlx);
    return (0);
}