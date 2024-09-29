/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clue_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:27:25 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/29 11:10:01 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clue_parser.h"
#include "utils.h"

int	is_valid_clue(char c)
{
	return (c >= '1' && c <= '4');
}

void	extract_clue_values(char *arg, int clue_values[16])
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (i < 31)
	{
		if (is_valid_clue(arg[i]))
		{
			clue_values[index] = arg[i] - '0';
			index++;
		}
		else if (arg[i] != ' ')
		{
			print_error_and_exit();
		}
		i += 2;
	}
	if (index != 16)
	{
		print_error_and_exit();
	}
}

void	assign_clues(int clue_values[16], int clues[4][SIZE])
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		clues[0][i] = clue_values[i];
		clues[1][i] = clue_values[i + SIZE];
		clues[2][i] = clue_values[i + 2 * SIZE];
		clues[3][i] = clue_values[i + 3 * SIZE];
		i++;
	}
}

void	parse_clues(char *arg, int clues[4][SIZE])
{
	int	clue_values[16];

	extract_clue_values(arg, clue_values);
	assign_clues(clue_values, clues);
}
