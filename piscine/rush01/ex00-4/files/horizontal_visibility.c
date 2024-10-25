/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_visibility.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:20:40 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/29 10:22:21 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "horizontal_visibility.h"

int	check_left_visibility(int grid[SIZE][SIZE], int row, int clues[4][SIZE])
{
	int	visible;
	int	max_height;
	int	col;

	visible = 1;
	max_height = grid[row][0];
	col = 1;
	while (col < SIZE)
	{
		if (grid[row][col] > max_height)
		{
			visible++;
			max_height = grid[row][col];
		}
		col++;
	}
	if (clues[2][row] != 0 && visible != clues[2][row])
		return (0);
	return (1);
}

int	check_right_visibility(int grid[SIZE][SIZE], int row, int clues[4][SIZE])
{
	int	visible;
	int	max_height;
	int	col;

	visible = 1;
	max_height = grid[row][SIZE - 1];
	col = SIZE - 2;
	while (col >= 0)
	{
		if (grid[row][col] > max_height)
		{
			visible++;
			max_height = grid[row][col];
		}
		col--;
	}
	if (clues[3][row] != 0 && visible != clues[3][row])
		return (0);
	return (1);
}

int	check_horizontal_visibility(int grid[SIZE][SIZE], int clues[4][SIZE])
{
	int	row;

	row = 0;
	while (row < SIZE)
	{
		if (!check_left_visibility(grid, row, clues))
			return (0);
		if (!check_right_visibility(grid, row, clues))
			return (0);
		row++;
	}
	return (1);
}
