/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:07:48 by diegfern          #+#    #+#             */
/*   Updated: 2024/12/10 20:56:05 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

int	main(void)
{
	char	*line;
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	num_bytes;

	line = get_next_line(fd);
	printf("line: %s", line);
	/*
	fd = open("testfile", O_RDONLY | O_CREAT);
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
	*/
	return (0);
}

char	*get_next_line(int fd)
{
	static char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
}