/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:07:48 by diegfern          #+#    #+#             */
/*   Updated: 2024/12/15 19:28:01 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("testfile", O_RDONLY);
	line = get_next_line(fd);
	printf("line: %s", line);
	free(line);
	close(fd);
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
	static char	*stack_line;
	ssize_t		num_bytes;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	num_bytes = read(fd, buffer, BUFFER_SIZE);
	if (num_bytes > 0)
	 


	
	while (num_bytes > 0)
	{
		buffer[num_bytes] = '\0';
		while (buffer[i] != '\n')
		{
			write(1, &buffer[i], 1);
			i++;
		}
		// printf("Bytes read: %ld, Content: \"%s\"\n", num_bytes, buffer);
		// num_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (num_bytes == -1)
		printf("Error: Unable to read file\n");
	return (line);
}
