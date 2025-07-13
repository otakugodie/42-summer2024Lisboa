#include "mlx.h"
#include "libft/libft.h"
#include <math.h>

#define	DEFAULT_COLOR	0xFFFFFF
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE  "FdF - diegfern"

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

typedef struct s_vars {
    void			*mlx;
    void			*win;
    t_map			**map;
    int				height;
    int				width;
    t_projection	projection;
}	t_vars;

// Declaraciones de funciones
void draw_map_points(t_vars *vars);
int redraw(void *param);
void free_map(t_map **map, int height);

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

/* int redraw(void *param)
{
	t_vars *vars = (t_vars *)param;
	draw_iso_rect(vars->mlx, vars->win, 450, 300);
	return (0);
} */

int	key_hook(int keycode, void *param)
{
	t_vars *vars = (t_vars *)param;

	if (keycode == 65307) // ESC en Linux
		exit(0);
	else if (keycode == 61 || keycode == 43 || keycode == 65451) // Tecla + (zoom in)
	{
		vars->projection.zoom *= 1.1;
		redraw(vars); // Redibujar con nuevo zoom
	}
	else if (keycode == 45 || keycode == 95 || keycode == 65453) // Tecla - (zoom out)
	{
		vars->projection.zoom *= 0.9;
		redraw(vars); // Redibujar con nuevo zoom
	}
	else if (keycode == 122) // Tecla 'z' para zoom in
	{
		vars->projection.zoom *= 1.1;
		redraw(vars);
	}
	else if (keycode == 120) // Tecla 'x' para zoom out
	{
		vars->projection.zoom *= 0.9;
		redraw(vars);
	}
	else if (keycode == 65362) // Flecha arriba
	{
		vars->projection.offset_y -= 10;
		redraw(vars); // Redibujar con nuevo offset
	}
	else if (keycode == 65364) // Flecha abajo
	{
		vars->projection.offset_y += 10;
		redraw(vars); // Redibujar con nuevo offset
	}
	else if (keycode == 65361) // Flecha izquierda
	{
		vars->projection.offset_x -= 10;
		redraw(vars);
	}
	else if (keycode == 65363) // Flecha derecha
	{
		vars->projection.offset_x += 10;
		redraw(vars);
	}
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

float calculate_auto_zoom(int width, int height, int window_width, int window_height)
{
	float map_screen_width = (width + height) * cos(30 * M_PI / 180.0);
	float map_screen_height = (width + height) * sin(30 * M_PI / 180.0);
    
	// Calculo zoom para que quepa en la ventana (con márgenes)
	float zoom_x = (window_width * 0.8) / map_screen_width;
	float zoom_y = (window_height * 0.8) / map_screen_height;

	// Uso el menor para que quepa completamente
	return (zoom_x < zoom_y) ? zoom_x : zoom_y;
}

void calculate_window_size(int width, int height, int *window_width, int *window_height)
{
	// Tamaño mínimo
	int min_width = WINDOW_WIDTH;
	int min_height = WINDOW_HEIGHT;

	// Calculo tamaño basado en el mapa
	int recommended_width = (width + height) * 20 + 200; // 200 de margen
	int recommended_height = (width + height) * 15 + 200;

	*window_width = (recommended_width > min_width) ? recommended_width : min_width;
	*window_height = (recommended_height > min_height) ? recommended_height : min_height;
}

void test_draw_points(t_vars *vars)
{
	// Dibujar el mapa usando la función modularizada
	draw_map_points(vars);

	// Hooks básicos para cerrar
	mlx_hook(vars->win, 17, 0, close_window, vars);      // Cerrar con X
	mlx_hook(vars->win, 2, 1L<<0, key_hook, vars);       // Teclas
	mlx_expose_hook(vars->win, redraw, vars);             // Hook de redraw

	// Mostrar ventana
	mlx_loop(vars->mlx);
}

void free_map(t_map **map, int height)
{
	int i;

	if (!map)
		return;
	
	// Liberar cada fila
	i = 0;
	while (i < height)
	{
		if (map[i])
		{
			free(map[i]);
			map[i] = NULL;
		}
		i++;
	}
	
	// Liberar el array principal de punteros
	free(map);
}

// Función para dibujar solo los puntos del mapa (sin hooks ni inicialización MLX)
void draw_map_points(t_vars *vars)
{
	int x, y;

	// Limpiar la ventana
	mlx_clear_window(vars->mlx, vars->win);
	
	// Recorrer el mapa y dibujar cada punto
	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			// Dibujar el punto en las coordenadas calculadas
			mlx_pixel_put(vars->mlx, vars->win, vars->map[y][x].screen_x, vars->map[y][x].screen_y, vars->map[y][x].color);
			
			// Opcional: dibujar un punto más grande (3x3 píxeles)
			mlx_pixel_put(vars->mlx, vars->win, vars->map[y][x].screen_x + 1, vars->map[y][x].screen_y, vars->map[y][x].color);
			mlx_pixel_put(vars->mlx, vars->win, vars->map[y][x].screen_x, vars->map[y][x].screen_y + 1, vars->map[y][x].color);
			mlx_pixel_put(vars->mlx, vars->win, vars->map[y][x].screen_x + 1, vars->map[y][x].screen_y + 1, vars->map[y][x].color);
			
			x++;
		}
		y++;
	}
}

// Hook de redraw que se ejecuta cuando la ventana necesita ser redibujada
int redraw(void *param)
{
	t_vars *vars = (t_vars *)param;
	
	// Recalcular proyección con parámetros actuales
	isometric_projection(vars->map, vars->height, vars->width, &vars->projection);
	
	// Redibujar el mapa
	draw_map_points(vars);
	
	return (0);
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
		if ( isometric_projection(map, height, width, &projection) == 0){
			printf ("Coordenadas isometricas OK\n");
			//test_draw_points(map, height, width);
			//test_draw_points()

			// Inicializo estructura t_vars para MLX
			t_vars vars;

			vars.mlx = mlx_init();
			if (!vars.mlx)
			{
				printf("Error: No se pudo inicializar MLX\n");
				free_map(map, height);
				return 1;
			}

			// Calculo tamaño de ventana y zoom automático
			int win_width;
			int win_height;
			
			calculate_window_size(width, height, &win_width, &win_height);
			float auto_zoom = calculate_auto_zoom(width, height, win_width, win_height);
			
			// Actualizo proyección con zoom automático y centro en ventana
			projection.zoom = auto_zoom;
			
			projection.offset_x = win_width / 2.5;
			projection.offset_y = win_height / 2.5;

			projection.elevation = 0.5; // zoom, offset_x, offset_y, elevation
			
			// Recalculo proyección con nuevos parámetros
			isometric_projection(map, height, width, &projection);
			
			vars.win = mlx_new_window(vars.mlx, win_width, win_height, WINDOW_TITLE);
			if (!vars.win)
			{
				printf("Error: No se pudo crear la ventana\n");
				free_map(map, height);
				return 1;
			}
			
			// Asigno datos del mapa y proyección a vars
			vars.map = map;
			vars.height = height;
			vars.width = width;
			vars.projection = projection;
			
			// Dibujar puntos y configurar hooks
			test_draw_points(&vars);
		}

		return 0;
	}else {
		printf("\nReading from stdin (press Ctrl+D to end):\n");
	}
}
