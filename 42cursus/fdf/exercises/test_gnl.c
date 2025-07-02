#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("testfile.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return 1;
	}
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return 0;
}
