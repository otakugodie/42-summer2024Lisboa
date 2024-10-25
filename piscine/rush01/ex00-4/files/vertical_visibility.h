/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_visibility.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:33:42 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/29 10:59:12 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTICAL_VISIBILITY_H
# define VERTICAL_VISIBILITY_H

# include "constants.h"

int	check_top_visibility(int grid[SIZE][SIZE], int col, int clues[4][SIZE]);
int	check_bottom_visibility(int grid[SIZE][SIZE], int col, int clues[4][SIZE]);
int	check_vertical_visibility(int grid[SIZE][SIZE], int clues[4][SIZE]);

#endif