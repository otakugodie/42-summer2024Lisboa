#include "mlx.h"
#include "libft/libft.h"
#include <math.h>


char	*clear_var(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}


int main(int argc, char **argv)
{
	char *line;
	char	**split;
	int fd;

	int height;
	int width;	

	// Si se pasa un archivo como argumento, abrirlo
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror("Error opening file");
			return 1;
		}
		
		height = 0;
		width = 0;
		while ((line = get_next_line(fd)) != NULL)
		{
			height++;
			if (height == 1){
				split = ft_split(line, ' ');
				while (split[width])
					width++;
				clear_var(split);
			}
			printf("%s", line);
			free(line);
		}
		printf("\nNumero de filas es: %d\n", height);
		printf("Numero de columnas es: %d\n", width);
		close(fd);
		printf("\n");
		return 0;
	}
	else
	{
		// Test lectura desde stdin
		printf("\nReading from stdin (press Ctrl+D to end):\n");
	}

    return 0;
}

/*

typedef struct s_map
{
	int		**values;
	int		width;
	int		height;
}	t_map;

t_map	*read_map(const char *filename)
{
	int		fd = open(filename, O_RDONLY);
	char	*line;
	char	**split;
	int		i, j;
	t_map	*map = malloc(sizeof(t_map));
	int		**values = NULL;
	int		height = 0, width = 0;

	// Primer pasada: contar height y width
	while ((line = get_next_line(fd)))
	{
		height++;
		if (height == 1)
		{
			split = ft_split(line, ' ');
			while (split[width])
				width++;
			// liberar split
			for (i = 0; split[i]; i++)
				free(split[i]);
			free(split);
		}
		free(line);
	}
	close(fd);

	// Reservar memoria para el array 2D
	values = malloc(sizeof(int *) * height);
	for (i = 0; i < height; i++)
		values[i] = malloc(sizeof(int) * width);

	// Segunda pasada: guardar los valores
	fd = open(filename, O_RDONLY);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		split = ft_split(line, ' ');
		for (j = 0; j < width; j++)
			values[i][j] = ft_atoi(split[j]);
		for (j = 0; split[j]; j++)
			free(split[j]);
		free(split);
		free(line);
		i++;
	}
	close(fd);

	map->values = values;
	map->width = width;
	map->height = height;
	return map;
}

int main(void)
{
	t_map *map = read_map("42.fdf");
	// Aquí puedes usar map->values, map->width y map->height

	// Liberar memoria
	for (int i = 0; i < map->height; i++)
		free(map->values[i]);
	free(map->values);
	free(map);

	return 0;
}

*/