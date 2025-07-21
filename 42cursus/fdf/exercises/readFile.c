/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readFile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:29:15 by diegfern          #+#    #+#             */
/*   Updated: 2025/07/20 14:28:24 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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
	float zoom;
	int offset_x;
	int offset_y;
	float elevation;
} t_projection;

typedef struct s_vars {
    void			*mlx;
    void			*win;
    t_map			**map;
    int				height;
    int				width;
    t_projection	projection;
}	t_vars;

typedef struct s_bresenham {
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int total_distance;
} t_bresenham;

// Estructura para posición actual para dibujar la linea
typedef struct s_line_pos {
    int x;
    int y;
    int current_distance;
} t_line_pos;

//Estructura para RGB
typedef struct s_rgb {
    int r;
    int g;
    int b;
} t_rgb;

// Prototipos de funciones
void render_map(t_vars *vars);
int redraw(void *param);
void free_map(t_map **map, int height);
void setup_hooks(t_vars *vars);
void clear_window(t_vars *vars);
void draw_line(t_vars *vars, t_map point1, t_map point2);
void draw_wireframe(t_vars *vars);
void draw_map_points(t_vars *vars);
int open_map_file(const char *filename);

//Procesamiento para llenar el maps (fill_map)
static int process_line_data(char **split, t_map *map_row, int width, int y);
static int validate_line_width(char **split, int expected_width, int line_num);
void parse_point_value(char *element, t_map *point, int x, int y);
static int process_map_file(int fd, t_map **map, int width);

//Funciones de limpieza
void cleanup_line_resources(char **split, char *line);
void cleanup_split_array(char **split);

//Funciones para la refactorizacion de main
static int parse_map_dimensions(const char *filename, int *height, int *width);
static int initialize_mlx_system(t_vars *vars, t_map **map, int height);
static int setup_window_and_projection(t_vars *vars, int width, int height, t_projection *projection);
static void launch_fdf(t_vars *vars);


/*Funciones para trazar la linea (draw_line) con algoritmo de Bresenham*/
static void init_bresenham(t_map p1, t_map p2, t_bresenham *vars_bres);
static void init_line_position(t_map point, t_line_pos *pos);
static unsigned int get_interp_color(unsigned int c1, unsigned int c2, int current_dist, int total_dist);
static void update_position(t_bresenham *vars_bres, t_line_pos *pos);

//Funciones para la extrapolacion de colores
static unsigned int interp_color(unsigned int color1, unsigned int color2, float t);
static void extract_rgb_comp(unsigned int color, t_rgb *rgb);
static void interp_rgb_comp(t_rgb rgb1, t_rgb rgb2, float t, t_rgb *result);


int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

/*Funcion de detección de teclas mediante hook: ESC, '+' o 'z' (zoom in), '-' o 'x' (zoom out), Flechas arriba, abajo, izquierda, derecha*/
int	key_hook(int keycode, void *param)
{
	t_vars *vars = (t_vars *)param;

	if (keycode == 65307) // ESC en Linux
		exit(0);
	else if (keycode == 61 || keycode == 43 || keycode == 65451 || keycode == 122)
		vars->projection.zoom *= 1.1;
	else if (keycode == 45 || keycode == 95 || keycode == 65453 || keycode == 120)
		vars->projection.zoom *= 0.9;
	else if (keycode == 65362)
		vars->projection.offset_y -= 10;
	else if (keycode == 65364) 
		vars->projection.offset_y += 10;
	else if (keycode == 65361)
		vars->projection.offset_x -= 10;
	else if (keycode == 65363)
		vars->projection.offset_x += 10;
	redraw(vars);
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
/*Funcion para apertura segura de archivos*/
int open_map_file(const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (-1);
	}
	return (fd);
}

/*Crea y reserva memoria para una matriz bidimensional de estructuras t_map de tamaño height x width. Primero asigna memoria para un array de punteros (filas), luego para cada fila asigna memoria para width estructuras t_map (columnas).*/
t_map **allocate_map (int height, int width)
{
	t_map **map;
	int i;

	map = malloc (sizeof(t_map *) * height);
	i = 0;
	while (i < height)
	{
		map[i] = malloc (sizeof(t_map) * width);
		i++;
	}
	return (map);
}


/*Procesa todos los puntos/elementos de una línea del archivo y los convierte en estructuras t_map con sus coordenadas (x,y,z) y color.*/
static int process_line_data(char **split, t_map *map_row, int width, int y)
{
	int x;

	x = 0;
	while (split[x] && x < width)
	{
		parse_point_value(split[x], &map_row[x], x, y);
		x++;
	}
	return (0);
}
/*Cuenta elementos en el array split, valida que no exceda el ancho esperado y en caso de error, libera memoria y termina el programa*/
static int validate_line_width(char **split, int expected_width, int line_num)
{
	int count;

	count = 0;
	while (split[count])
		count++;

	if (count > expected_width)
	{
		write(2, "Error: Line ", 12);
		ft_putnbr_fd(line_num, 2);
		write(2, " has ", 5);
		ft_putnbr_fd(count, 2);
		write(2, " columns, expected ", 18);
		ft_putnbr_fd(expected_width, 2);
		write(2, "\n", 1);
		cleanup_split_array(split);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/*Libera memoria del array split (cada string individual y el array), libera memoria de la línea leída y maneja casos donde split o line puedan ser NULL*/
void cleanup_line_resources(char **split, char *line)
{
	cleanup_split_array(split);
	if (line)
		free(line);
}
/* toma un elemento individual del archivo (como un string) y lo convierte en datos estructurados, sea un numero o numero con , y el código del color (0x)*/
void parse_point_value(char *element, t_map *point, int x, int y)
{
	char *z_sep;
	point->x = x;
	point->y = y;
	if (!ft_strchr(element, ','))
	{
		point->z = ft_atoi(element);
		point->color = DEFAULT_COLOR;
	}
	else
	{
		z_sep = ft_strchr(element, ',');
		*z_sep = '\0';
		point->z = ft_atoi(element);
		if (*(z_sep + 1) == '0' && (*(z_sep + 2) == 'x' || *(z_sep + 2) == 'X'))
			point->color = ft_atoi_base(z_sep + 1);
		else
			point->color = ft_atoi(z_sep + 1);
	}
}
/*Bucle principal de procesamiento*/
static int process_map_file(int fd, t_map **map, int width)
{
	char *line;
	char **split;
	int y;
	int result;

	y = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		split = ft_split(line, ' ');
		if (validate_line_width(split, width, y + 1) != 0)
		{
			cleanup_line_resources(split, line);
			return (-1);
		}
		result = process_line_data(split, map[y], width, y);
		cleanup_line_resources(split, line);
		if (result != 0)
			return (-1);
		y++;
	}
	return (0);
}
/*Función principal que lee un archivo de mapa y llena la matriz bidimensional*/
int fill_map(const char *filename, t_map **map, int width)
{
    int fd;
    int result;
    
    fd = open_map_file(filename);
    if (fd < 0)
        return (-1);
    
    result = process_map_file(fd, map, width);
    close(fd);
    
    return (result);
}

/*Recorre el map para calcular los screen_x y los screen_y correspondientes a cada relacion x,y,z para convertirlos a 2D isometricos*/
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
			map[y][x].screen_x = (((map[y][x].x - map[y][x].y) * cos(angle_radians)) *  projection->zoom) + projection->offset_x;

			map[y][x].screen_y = (((map[y][x].x + map[y][x].y) * sin(angle_radians) - map[y][x].z * projection->elevation) * projection->zoom) + projection->offset_y;
			x++;
		}
		y++;
	}
	return (0);
}

/*Estima el tamaño que ocupará el mapa en proyección isométrica, calcula el zoom necesario para que quepa en el 80% de la ventana (dejando 20% de margen), y devuelve el menor de los dos zooms (horizontal/vertical) para garantizar que quepa completamente.*/
float calculate_auto_zoom(int width, int height, int window_width, int window_height)
{
	float map_screen_width;
	float map_screen_height;
	float zoom_x;
	float zoom_y;

	map_screen_width = (width + height) * cos(30 * M_PI / 180.0);
	map_screen_height = (width + height) * sin(30 * M_PI / 180.0);

	zoom_x = (window_width * 0.8) / map_screen_width;
	zoom_y = (window_height * 0.8) / map_screen_height;

	return (zoom_x < zoom_y) ? zoom_x : zoom_y;
}

/*
Calcula las dimensiones óptimas de ventana basándose en el tamaño del mapa.
Usa un tamaño mínimo predefinido o calcula uno proporcional al mapa con margen, seleccionando siempre el mayor para garantizar que el contenido sea visible.
*/
void calculate_window_size(int width, int height, int *window_width, int *window_height)
{

	int min_width;
	int min_height;
	int recommended_width;
	int recommended_height;

	min_width = WINDOW_WIDTH;
	min_height = WINDOW_HEIGHT;

	recommended_width = (width + height) * 20 + 200;
	recommended_height = (width + height) * 15 + 200;

	*window_width = (recommended_width > min_width) ? recommended_width : min_width;
	*window_height = (recommended_height > min_height) ? recommended_height : min_height;
}

/*
Libera la memoria de una matriz bidimensional de estructuras t_map.
 Primero libera cada fila individualmente, luego el array principal de punteros, evitando memory leaks 
 al finalizar el programa o en caso de error.
*/
void free_map(t_map **map, int height)
{
	int i;

	if (!map)
		return;

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

	free(map);
}

/*
Configura los hooks de eventos MLX para la interacción con la ventana.
Establece handlers para cerrar ventana (X), detección de teclas y redibujado de la ventana (redraw), permitiendo la interactividad básica del programa FdF.
*/
void setup_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_hook(vars->win, 2, 1L<<0, key_hook, vars);
	mlx_expose_hook(vars->win, redraw, vars);
}

/*Borra completamente todo el contenido visual de la ventana.
Llena la ventana con el color de fondo (negro).
Prepara la ventana para nuevo contenido*/
void clear_window(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
}

/*
Lanza la aplicación FdF iniciando el renderizado y la interactividad.
Dibuja el mapa inicial, configura los hooks de eventos y entra en el loop principal de MLX, manteniendo la ventana activa hasta que el usuario la cierre.
*/
static void launch_fdf(t_vars *vars)
{
	render_map(vars);
	setup_hooks(vars);
	mlx_loop(vars->mlx);
}

// Funciones auxiliares para interpolación de colores

// Extraer componente rojo de un color
static int get_red(unsigned int color)
{
	return ((color >> 16) & 0xFF);
}

// Extraer componente verde de un color
static int get_green(unsigned int color)
{
	return ((color >> 8) & 0xFF);
}

// Extraer componente azul de un color
static int get_blue(unsigned int color)
{
	return (color & 0xFF);
}

// Crear color a partir de componentes R, G, B
static unsigned int create_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

// Interpolación lineal entre dos valores
static int lerp_int(int start, int end, float t)
{
	return (start + (int)((end - start) * t));
}

/*Funcion para interpolar RGB*/
static void extract_rgb_comp(unsigned int color, t_rgb *rgb)
{
	rgb->r = get_red(color);
	rgb->g = get_green(color);
	rgb->b = get_blue(color);
}

/*Funcion Interpolar RGB*/
static void interp_rgb_comp(t_rgb rgb1, t_rgb rgb2, float t, t_rgb *result)
{
	result->r = lerp_int(rgb1.r, rgb2.r, t);
	result->g = lerp_int(rgb1.g, rgb2.g, t);
	result->b = lerp_int(rgb1.b, rgb2.b, t);
}

// Interpolación del color entre dos colores
static unsigned int interp_color(unsigned int color1, unsigned int color2, float t)
{
	t_rgb rgb1;
	t_rgb rgb2;
	t_rgb result;

	if (t <= 0.0)
		return (color1);
	if (t >= 1.0)
		return (color2);

	extract_rgb_comp(color1, &rgb1);
	extract_rgb_comp(color2, &rgb2);
	interp_rgb_comp(rgb1, rgb2, t, &result);

	return (create_color(result.r, result.g, result.b));
}

// Función auxiliar para dibujar un punto grueso
static void draw_thick_point(t_vars *vars, int x, int y, unsigned int color, int size)
{
	int	i;
	int	j;
	int half_size;
	
	half_size = size / 2;	
	i = -half_size;

	while (i <= half_size)
	{
		j = -half_size;
		while (j <= half_size)
		{
			mlx_pixel_put(vars->mlx, vars->win, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

// Función auxiliar para obtener el valor absoluto
static int absolute_value(int value)
{
	return (value < 0) ? -value : value;
}

//Funciones para dibujar linea
static void init_bresenham(t_map p1, t_map p2, t_bresenham *vars_bres)
{
	vars_bres->dx = absolute_value(p2.screen_x - p1.screen_x);
	vars_bres->dy = absolute_value(p2.screen_y - p1.screen_y);
	vars_bres->sx = (p1.screen_x < p2.screen_x) ? 1 : -1;
	vars_bres->sy = (p1.screen_y < p2.screen_y) ? 1 : -1;
	vars_bres->err = vars_bres->dx - vars_bres->dy;
	vars_bres->total_distance = vars_bres->dx + vars_bres->dy;
}

static void init_line_position(t_map point, t_line_pos *pos)
{
	pos->x = point.screen_x;
	pos->y = point.screen_y;
	pos->current_distance = 0;
}

/*Calcul el color interpolado*/
static unsigned int get_interp_color(unsigned int c1, unsigned int c2, int current_dist, int total_dist)
{
	float t;

	if (total_dist > 0)
		t = (float)current_dist / (float)total_dist;
	else
		t = 0.0;
	return (interp_color(c1, c2, t));
}

static void update_position(t_bresenham *vars_bres, t_line_pos *pos)
{
	int e2;

	e2 = 2 * vars_bres->err;
	if (e2 > -vars_bres->dy)
	{
		vars_bres->err -= vars_bres->dy;
		pos->x += vars_bres->sx;
		pos->current_distance++;
	}
	if (e2 < vars_bres->dx)
	{
		vars_bres->err += vars_bres->dx;
		pos->y += vars_bres->sy;
		pos->current_distance++;
	}
}

// Función para dibujar una línea entre dos puntos usando el algoritmo de Bresenham con interpolación de color
void draw_line(t_vars *vars, t_map point1, t_map point2)
{
	t_bresenham vars_bres;
	t_line_pos pos;
	unsigned int cur_color;

	init_bresenham(point1, point2, &vars_bres);
	init_line_position(point1, &pos);

	while (1)
	{
		cur_color = get_interp_color(point1.color, point2.color, pos.current_distance, vars_bres.total_distance);
		mlx_pixel_put(vars->mlx, vars->win, pos.x, pos.y, cur_color);
		
		if (pos.x == point2.screen_x && pos.y == point2.screen_y)
			break;
			
		update_position(&vars_bres, &pos);
	}
}

// Función para dibujar el wireframe completo del mapa
void draw_wireframe(t_vars *vars)
{
	int x;
	int y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			// Dibujar línea hacia la derecha (si no es la última columna)
			if (x < vars->width - 1)
				draw_line(vars, vars->map[y][x], vars->map[y][x + 1]);

			// Dibujar línea hacia abajo (si no es la última fila)
			if (y < vars->height - 1)
				draw_line(vars, vars->map[y][x], vars->map[y + 1][x]);

			x++;
		}
		y++;
	}
}

// Función para dibujar solo los puntos del mapa
void draw_map_points(t_vars *vars)
{
	int x;
	int y;
	int px; 
	int py;
	
	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			px = vars->map[y][x].screen_x;
			py = vars->map[y][x].screen_y;
			
			// Dibujar punto más grueso (3x3 píxeles)
			draw_thick_point(vars, px, py, vars->map[y][x].color, 3);
			
			x++;
		}
		y++;
	}
}

// Función para dibujar el mapa completo (wireframe + puntos)
void render_map(t_vars *vars)
{
	clear_window(vars);
	draw_wireframe(vars);
	//draw_map_points(vars);
}

// Hook de redraw que se ejecuta cuando la ventana necesita ser redibujada, Recalculando la proyección con parámetros actuales y luego redibuja
int redraw(void *param)
{
	t_vars *vars = (t_vars *)param;

	isometric_projection(vars->map, vars->height, vars->width, &vars->projection);
	render_map(vars);

	return (0);
}

/*Lee un archivo para determinar las dimensiones del mapa (alto y ancho)*/
static int parse_map_dimensions(const char *filename, int *height, int *width)
{
	char *line;
	char **split;
	int fd;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (-1);
	}
	*height = 0;
	*width = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		(*height)++;
		if (*height == 1)
		{
			split = ft_split(line, ' ');
			while (split[*width])
				(*width)++;
			cleanup_split_array(split);
		}
		free(line);
	}
	close(fd);
	return (0);
}

/*Inicializa el sistema MLX y configura la estructura base*/
static int initialize_mlx_system(t_vars *vars, t_map **map, int height)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		write(2, "Error: No se pudo inicializar MLX\n", 34);
		free_map(map, height);
		return (-1);
	}
	return (0);
}

/*Configura ventana, proyección y parámetros gráficos*/
static int setup_window_and_projection(t_vars *vars, int width, int height, t_projection *projection)
{
	int win_width;
	int win_height;
	float auto_zoom;

	calculate_window_size(width, height, &win_width, &win_height);
	auto_zoom = calculate_auto_zoom(width, height, win_width, win_height);

	projection->zoom = auto_zoom;
	projection->offset_x = win_width / 2.5;
	projection->offset_y = win_height / 2.5;
	projection->elevation = 0.5;

	isometric_projection(vars->map, vars->height, vars->width, projection);

	vars->win = mlx_new_window(vars->mlx, win_width, win_height, WINDOW_TITLE);
	if (!vars->win)
	{
		write(2, "Error: No se pudo crear la ventana\n", 35);
		free_map(vars->map, vars->height);
		return (-1);
	}
	return (0);
}

/*Libera memoria de un array de strings (como el resultado de ft_split)*/
void cleanup_split_array(char **split)
{
	int i;

	if (!split)
		return;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int main(int argc, char **argv)
{
	int height;
	int width;
	t_map **map;
	t_projection projection;
	t_vars vars;

	if (argc <= 1)
		return (write(1, "Usage: ./fdf <map_file>\n", 24), 1);
	if (parse_map_dimensions(argv[1], &height, &width) != 0)
		return (1);
	map = allocate_map(height, width);
	if (fill_map(argv[1], map, width) != 0)
		return (free_map(map, height), 1);
	if (initialize_mlx_system(&vars, map, height) != 0)
		return (1);
	vars.map = map;
	vars.height = height;
	vars.width = width;
	vars.projection = projection;
	if (setup_window_and_projection(&vars, width, height, &projection) != 0)
		return (1);
	vars.projection = projection;
	launch_fdf(&vars);
	return (0);
}
