/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:07:35 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/29 11:41:07 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "constants.h"
# include <unistd.h>

int		print_error_and_exit(void);
int		check_vertical_visibility(int grid[SIZE][SIZE], int clues[4][SIZE]);
int		check_horizontal_visibility(int grid[SIZE][SIZE], int clues[4][SIZE]);
void	initialize_grid(int grid[SIZE][SIZE]);

#endif