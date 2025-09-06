/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:07:24 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/06 15:08:45 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define DEFAULT_COLOR 0xFFFFFF
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MAX_WINDOW_WIDTH 1920
# define MAX_WINDOW_HEIGHT 1080
# define WINDOW_TITLE "FdF - diegfern"

typedef struct s_map
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;

	int				screen_x;
	int				screen_y;

}					t_map;

typedef struct s_projection
{
	float			zoom;
	int				offset_x;
	int				offset_y;
	float			elevation;
}					t_projection;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
	t_map			**map;
	int				height;
	int				width;
	t_projection	projection;
}					t_vars;

typedef struct s_bresenham
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				total_distance;
}					t_bresenham;

// Estructura para posición actual para dibujar la linea
typedef struct s_line_pos
{
	int				x;
	int				y;
	int				current_distance;
}					t_line_pos;

// Estructura para RGB
typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_recommended_window
{
	int				width;
	int				height;
}					t_recommended_window;

/* ****************** Prototipos de funciones **************** */
// Map parsing
int					parse_map_dimensions(const char *filename, int *height,
						int *width);
int					fill_map(const char *filename, t_map **map, int width);
// Map parsing - Parsing utils
int					validate_line_width(char **split, int expected_width,
						int line_num);
void				parse_point_value(char *element, t_map *point, int x,
						int y);
int					process_line_data(char **split, t_map *map_row, int width,
						int y);
int					process_dimension_line(char *line, int *height, int *width);
// 		Map parsing - Memory utils
t_map				**allocate_map(int height, int width);
int					open_map_file(const char *filename);
void				cleanup_line_resources(char **split, char *line);

// Drawing
void				draw_line(t_vars *vars, t_map point1, t_map point2);
void				draw_wireframe(t_vars *vars);
void				render_map(t_vars *vars);

// 		Drawing -> Image utils
void				my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int					init_image(t_vars *vars, int width, int height);
void				clear_image_buffer(t_vars *vars);

// 		Drawing Bresenham
int					absolute_value(int value);
void				init_bresenham(t_map p1, t_map p2, t_bresenham *vars_bres);
void				update_position(t_bresenham *vars_bres, t_line_pos *pos);

// Colors
unsigned int		interp_color(unsigned int color1, unsigned int color2,
						float t);
unsigned int		create_color(int r, int g, int b);
int					get_red(unsigned int color);
int					get_green(unsigned int color);
int					get_blue(unsigned int color);
int					lerp_int(int start, int end, float t);

// Projections
int					isometric_projection(t_map **map, int height, int width,
						t_projection *projection);
float				calculate_auto_zoom(int width, int height, int window_width,
						int window_height);
void				calculate_window_size(int width, int height,
						int *window_width, int *window_height);

// Hooks
int					key_hook(int keycode, void *param);
int					close_window(void *param);
void				setup_hooks(t_vars *vars);

// Memory
void				free_map(t_map **map, int height);
void				cleanup_split_array(char **split);

// Utils
void				clear_window(t_vars *vars);
char				*clear_var(char **str);
void				free_map_and_resources(t_vars *vars);

#endif