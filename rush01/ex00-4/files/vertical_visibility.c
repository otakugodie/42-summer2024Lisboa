/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_visibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:15:31 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/29 10:57:24 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vertical_visibility.h"
#include "constants.h"

int	check_top_visibility(int grid[SIZE][SIZE], int col, int clues[4][SIZE])
{
	int	visible;
	int	max_height;
	int	row;

	visible = 1;
	max_height = grid[0][col];
	row = 1;
	while (row < SIZE)
	{
		if (grid[row][col] > max_height)
		{
			visible++;
			max_height = grid[row][col];
		}
		row++;
	}
	if (clues[0][col] != 0 && visible != clues[0][col])
		return (0);
	return (1);
}

int	check_bottom_visibility(int grid[SIZE][SIZE], int col, int clues[4][SIZE])
{
	int	visible;
	int	max_height;
	int	row;

	visible = 1;
	max_height = grid[SIZE - 1][col];
	row = SIZE - 2;
	while (row >= 0)
	{
		if (grid[row][col] > max_height)
		{
			visible++;
			max_height = grid[row][col];
		}
		row--;
	}
	if (clues[1][col] != 0 && visible != clues[1][col])
		return (0);
	return (1);
}

int	check_vertical_visibility(int grid[SIZE][SIZE], int clues[4][SIZE])
{
	int	col;

	col = 0;
	while (col < SIZE)
	{
		if (!check_top_visibility(grid, col, clues))
			return (0);
		if (!check_bottom_visibility(grid, col, clues))
			return (0);
		col++;
	}
	return (1);
}
