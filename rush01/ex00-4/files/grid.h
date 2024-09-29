/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:37:08 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/29 10:58:49 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

# include <unistd.h>
# include "constants.h"

void	print_grid(int grid[SIZE][SIZE]);
int		print_error_and_exit(void);

#endif