/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:08:21 by diegfern          #+#    #+#             */
/*   Updated: 2024/12/09 22:23:11 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 3

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);

#endif