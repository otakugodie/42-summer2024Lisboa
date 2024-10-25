/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_visibility.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:32:38 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/29 10:58:58 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HORIZONTAL_VISIBILITY_H
# define HORIZONTAL_VISIBILITY_H

# include "constants.h"

int	check_left_visibility(int grid[SIZE][SIZE], int row, int clues[4][SIZE]);
int	check_right_visibility(int grid[SIZE][SIZE], int row, int clues[4][SIZE]);
int	check_horizontal_visibility(int grid[SIZE][SIZE], int clues[4][SIZE]);

#endif