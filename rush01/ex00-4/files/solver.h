/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:35:04 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/29 12:04:10 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "constants.h"
# include "visibility_check.h"

typedef struct s_position
{
	int	row;
	int	col;
}		t_position;

int		is_valid(int grid[SIZE][SIZE], int row, int col, int num);
int		move_to_next_cell(int *row, int *col);
int		try_number(int grid[SIZE][SIZE], t_position pos, int num,
			int clues[4][SIZE]);
int		solve_skyscrapers(int grid[SIZE][SIZE], int row, int col,
			int clues[4][SIZE]);

#endif