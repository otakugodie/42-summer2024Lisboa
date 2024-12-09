/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:07:48 by diegfern          #+#    #+#             */
/*   Updated: 2024/12/09 22:41:10 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	num_bytes;

	fd = open("testfile", O_RDONLY);
	if (fd == -1)
	{
		printf("Error trying open file \n");
		return (1);
	}
	num_bytes = read(fd, buffer, BUFFER_SIZE);
	while (num_bytes > 0)
	{
		buffer[num_bytes] = '\0';
		printf("Bytes read: %ld, Content: \"%s\"\n", num_bytes, buffer);
		num_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (num_bytes == -1)
		printf("Error: Unable to read file\n");
	close(fd);
	return (0);
}
