/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:07:24 by diegfern          #+#    #+#             */
/*   Updated: 2025/07/20 17:15:27 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include "libft/libft.h"
#include <math.h>

#include <fcntl.h>

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

/* ****************** Prototipos de funciones **************** */
// Map parsing
int		parse_map_dimensions(const char *filename, int *height, int *width);
int		fill_map(const char *filename, t_map **map, int width);
t_map	**allocate_map(int height, int width);
void    parse_point_value(char *element, t_map *point, int x, int y);

int		open_map_file(const char *filename);

// Drawing
void	draw_line(t_vars *vars, t_map point1, t_map point2);
void	draw_wireframe(t_vars *vars);
void	render_map(t_vars *vars);

// Colors
unsigned int	interp_color(unsigned int color1, unsigned int color2, float t);

// Projections
int		isometric_projection(t_map **map, int height, int width, t_projection *projection);
float	calculate_auto_zoom(int width, int height, int window_width, int window_height);
void	calculate_window_size(int width, int height, int *window_width, int *window_height);

// Hooks
int		key_hook(int keycode, void *param);
int		close_window(void *param);
void	setup_hooks(t_vars *vars);

// Memory
void	free_map(t_map **map, int height);
void	cleanup_split_array(char **split);

// Utils
void	clear_window(t_vars *vars);
char	*clear_var(char **str);




/*
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

//Funciones para trazar la linea (draw_line) con algoritmo de Bresenham
static void init_bresenham(t_map p1, t_map p2, t_bresenham *vars_bres);
static void init_line_position(t_map point, t_line_pos *pos);
static unsigned int get_interp_color(unsigned int c1, unsigned int c2, int current_dist, int total_dist);
static void update_position(t_bresenham *vars_bres, t_line_pos *pos);

//Funciones para la extrapolacion de colores
static unsigned int interp_color(unsigned int color1, unsigned int color2, float t);
static void extract_rgb_comp(unsigned int color, t_rgb *rgb);
static void interp_rgb_comp(t_rgb rgb1, t_rgb rgb2, float t, t_rgb *result);

*/


#endif