/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:12:47 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/29 12:12:29 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "solver.h"

int	is_valid(int grid[SIZE][SIZE], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (grid[row][i] == num || grid[i][col] == num)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	move_to_next_cell(int *row, int *col)
{
	if (*col == SIZE)
	{
		(*row)++;
		*col = 0;
	}
	if (*row == SIZE)
	{
		return (1);
	}
	return (0);
}

int	try_number(int grid[SIZE][SIZE], t_position pos, int num,
		int clues[4][SIZE])
{
	if (is_valid(grid, pos.row, pos.col, num))
	{
		grid[pos.row][pos.col] = num;
		if (solve_skyscrapers(grid, pos.row, pos.col + 1, clues))
		{
			return (1);
		}
		grid[pos.row][pos.col] = 0;
	}
	return (0);
}

int	solve_skyscrapers(int grid[SIZE][SIZE], int row, int col,
		int clues[4][SIZE])
{
	int			num;
	t_position	pos;

	pos.row = row;
	pos.col = col;
	if (move_to_next_cell(&pos.row, &pos.col))
	{
		return (check_visibility(grid, clues));
	}
	num = 1;
	while (num <= SIZE)
	{
		if (try_number(grid, pos, num, clues))
		{
			return (1);
		}
		num++;
	}
	return (0);
}
