#include "mlx.h"
#include "libft/libft.h"
#include <math.h>

#define	DEFAULT_COLOR	0xFFFFFF

typedef struct s_map
{
	int	x;
	int	y;
	int	z;
	unsigned int color;

	int screen_x;
	int screen_y;

} t_map ;

typedef struct s_projection
{
	float zoom;			// Factor de escala (1.0 = tamaño normal)
	int offset_x;		// Desplazamiento horizontal
	int offset_y;		// Desplazamiento vertical
	float elevation;	// Factor de elevación para z (1.0 = normal)
} t_projection;

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	if (keycode == 65307) // ESC en Linux
		exit(0);
	return (0);
}


char	*clear_var(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}


t_map **allocate_map (int height, int width){

	// Creo la el array 2D t_map
	t_map **map;
	int i;

	// Reservo la memoria para el mapa en sus filas
	map = malloc (sizeof(t_map *) * height);
	i = 0;
	// Reservo la memoria para el mapa en cada una de sus columnas
	while (i < height){
		map[i] = malloc (sizeof(t_map) * width);
		i++;
	}
	return (map);

}

int	fill_map (const char *filename, t_map **map, int height, int width){
	char *line;
	char **split;
	char *z_sep;
	int fd;
	int x;
	int y;
	int count;

	fd = open(filename, O_RDONLY);

	if (fd < 0)
	{
		perror("Error opening file in fill_map");
		return -1;
	}
	y = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		//printf("\nLine:  %s", line);
		split = ft_split(line, ' ');
		
		/* Cuento el # de elementos del split para validar que hay suficientes columnas según el width que debería tener*/
		count = 0;
		while (split[count])
			count++;
		if (count > width)
		{
			// Muestro mensaje de error
			//***************************************************************************************/
			//* Ver como terminar mejor el error */
			fprintf(stderr, "Error: La línea %d tiene más columnas (%d) que el ancho esperado (%d)\n", y + 1, count, width);
			// Libero memoria de split y line
			for (x = 0; split[x]; x++)
				free(split[x]);
			free(split);
			free(line);
			// Libero el mapa si es necesario
			// for (int k = 0; k < y; k++) free(map[k]);
			// free(map);
			close(fd);
			// Terminar el programa con error
			exit(EXIT_FAILURE); // o return -1;
		}
		else {
			x = 0;
			//printf("Split: ");
			while (split[x] && x < width){
				map[y][x].x = x;
				map[y][x].y = y;
				// Si no encuentra la ',' en el elemento, almacena la z y deja el color por defecto
				if (!ft_strchr(split[x], ',') ){
					//printf("%s ", split[x]);
					map[y][x].z = ft_atoi(split[x]);
					map[y][x].color = DEFAULT_COLOR;
					//Luego de almacenar el valor en map limpia el elemento de split
					free(split[x]);
					x++;
				}
				else {
					// Si encuentra la ',' en el elemento, separo la z del color
					z_sep = ft_strchr(split[x], ',');
					*z_sep = '\0'; // Termina el string en la coma para obtener solo z
					map[y][x].z = ft_atoi(split[x]);
					// Si el color empieza con "0x", usa ft_atoi_base; si no, se convierte con ft_atoi en base 10 o se ignora
					if (*(z_sep + 1) == '0' && (*(z_sep + 2) == 'x' || *(z_sep + 2) == 'X'))
						map[y][x].color = ft_atoi_base(z_sep + 1);
					else
						map[y][x].color = ft_atoi(z_sep + 1); // Si no tiene el formato con 0x o 0X solo lo convierte a decimal
					//Luego de almacenar el valor en map limpia el elemento de split
					free(split[x]);
					x++;
				}
			}
			x = 0;
			y++;
			free (split);
			free(line);
		}
	}
	close(fd);
	printf("\n");
	return (0);
}

//Recorre el map para calcular los screen_x y los screen_y correspondientes a cada relacion x,y,z para convertirlos a 2D isometricos
int	isometric_projection (t_map **map, int height, int width, t_projection *projection)
{
	int x;
	int y;
	double angle_radians; 
	angle_radians = (30 * M_PI) / 180.0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			map[y][x].screen_x = (((map[y][x].x - map[y][x].y) * cos(angle_radians)) *  projection->zoom ) + projection->offset_x;

			map[y][x].screen_y = (((map[y][x].x + map[y][x].y) * sin(angle_radians) - map[y][x].z * projection->elevation) * projection->zoom) + projection->offset_y;
			x++;
		}
		y++;
	}
	return (0);
}

void test_draw_points(t_map **map, int height, int width)
{
	void *mlx;
	void *win;
	int x, y;
	// Inicializar MLX y crear ventana
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 600, "FdF - Test Points");
	// Recorrer el mapa y dibujar cada punto
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			// Dibujar el punto en las coordenadas calculadas
			mlx_pixel_put(mlx, win, map[y][x].screen_x, 	map[y][x].screen_y, 	map[y][x].color);
			
			// Opcional: dibujar un punto más grande (3x3 píxeles)
			mlx_pixel_put(mlx, win, map[y][x].screen_x + 1, map[y][x].screen_y,     map[y][x].color);
			mlx_pixel_put(mlx, win, map[y][x].screen_x,     map[y][x].screen_y + 1, map[y][x].color);
			mlx_pixel_put(mlx, win, map[y][x].screen_x + 1, map[y][x].screen_y + 1, map[y][x].color);
			
			x++;
		}
		y++;
	}

	// Hooks básicos para cerrar
	mlx_hook(win, 17, 0, close_window, NULL);      // Cerrar con X
	mlx_hook(win, 2, 1L<<0, key_hook, NULL);       // Cerrar con ESC

	// Mostrar ventana
	mlx_loop(mlx);
}

int main (int argc, char **argv)
{
	char *line;
	char	**split;
	int fd;
	int height;
	int width;
	t_map **map;
	int i;
	t_projection projection;

	// Si se pasa un archivo como argumento, abrirlo
	if (argc > 1){
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
			//printf("%s", line);
			free(line);
		}
		//printf("\nNumero de filas es: %d\n", height);
		//printf("Numero de columnas es: %d\n", width);
		map = allocate_map (height, width);	//No olvidar que luego se debe liberar la memoria del map
		close(fd);
		//printf("\n");

		if (fill_map(argv[1], map, height, width) == 0){
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					//printf("(%d, %d): z=%d color=%#X\t", x, y, map[y][x].z, map[y][x].color);
				}
				//printf("\n\n");
			}
			//printf ("Llenado exitoso\n");
		}
		//Llamo funcion para calcular las posiciones isometricas
		projection.zoom = 20.0;
		projection.offset_x = 400;
		projection.offset_y = 300;
		projection.elevation = 1.0; // zoom, offset_x, offset_y, elevation

		if ( isometric_projection(map, height, width, &projection) == 0){
			printf ("Coordenadas isometricas OK\n");
			test_draw_points(map, height, width);
		}

		return 0;
	}else {
		printf("\nReading from stdin (press Ctrl+D to end):\n");
	}
}
