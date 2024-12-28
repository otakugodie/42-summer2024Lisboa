/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:07:48 by diegfern          #+#    #+#             */
/*   Updated: 2024/12/28 17:51:22 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_next_line(int fd);
static char	*ft_read_line(int fd, char *buffer, char *previous_line);
static char	*ft_extract_chars(char *line);

static char	*ft_clear(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

static char	*ft_read_line(int fd, char *buffer, char *previous_line)
{
	int		num_bytes;
	char	*line_temp;

	num_bytes = 1;
	while (num_bytes > 0)
	{
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_bytes < 0)
		{
			//ft_clear(&previous_line);
			return (NULL);
		}
		if (num_bytes == 0)
			break ;
		buffer[num_bytes] = '\0';
		if (!previous_line)
			previous_line = ft_strdup("");
		line_temp = previous_line;
		previous_line = ft_strjoin(previous_line, buffer);
		ft_clear(&line_temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (previous_line);
}

static char	*ft_extract_chars(char *line)
{
	size_t	i;
	char	*previous_line;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	previous_line = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*previous_line == '\0')
		ft_clear(&previous_line);
	line[i + 1] = '\0';
	return (previous_line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*previous_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_read_line(fd, buffer, previous_line);
	ft_clear(&buffer);
	if (!line)
		return (NULL);
	previous_line = ft_extract_chars(line);
	if (!previous_line || *previous_line == '\0')
	{
		ft_clear(&previous_line);
	}
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 1;
	fd = open("testfile", O_RDONLY);
	if (fd < 0)
	{
		printf("Error: No se pudo abrir el archivo\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linea %d: %s", line_count++, line);
		free(line);
	}
	close(fd);
	return (0);
}
 */