/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:38:47 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/29 11:39:52 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

void	initialize_grid(int grid[SIZE][SIZE])
{
	int	row;
	int	col;

	row = 0;
	while (row < SIZE)
	{
		col = 0;
		while (col < SIZE)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}
