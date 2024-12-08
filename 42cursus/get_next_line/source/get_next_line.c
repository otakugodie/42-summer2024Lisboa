/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:07:48 by diegfern          #+#    #+#             */
/*   Updated: 2024/12/08 15:10:48 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	buffer[10];
	ssize_t	num_bytes;

	fd = open("/home/otakugodie/projects42/42cursus/get_next_line/source/testfile",
			O_RDONLY);
	if (fd == -1)
		printf("Error trying open file \n");
	else
	{
		num_bytes = read(fd, buffer, 5);
		close(fd);
		if (num_bytes==0)
			printf("File is empty\n");
		else
			printf("Number of characters is: %ld, and his contents is: %s\n",
				num_bytes, buffer);
	}
	return (0);
}
