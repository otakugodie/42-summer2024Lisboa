/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:01:17 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/29 11:42:51 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clue_parser.h"
#include "constants.h"
#include "grid.h"
#include "solver.h"
#include "utils.h"
#include <unistd.h>

int	print_error_and_exit(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	int	clues[4][SIZE];
	int	grid[SIZE][SIZE];

	initialize_grid(grid);
	if (argc <= 2)
	{
		parse_clues(argv[1], clues);
		if (solve_skyscrapers(grid, 0, 0, clues))
		{
			print_grid(grid);
		}
		else
		{
			write(1, "Error\n", 6);
		}
	}
	else
	{
		print_error_and_exit();
	}
	return (0);
}
