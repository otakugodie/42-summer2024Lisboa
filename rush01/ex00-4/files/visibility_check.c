/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:23:14 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/29 11:18:02 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "visibility_check.h"

int	check_visibility(int grid[SIZE][SIZE], int clues[4][SIZE])
{
	if (!check_vertical_visibility(grid, clues))
		return (0);
	if (!check_horizontal_visibility(grid, clues))
		return (0);
	return (1);
}
