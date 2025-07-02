#include "mlx.h"
#include "libft/libft.h"
#include <math.h>

void draw_iso_rect(void *mlx, void *win, int x0, int y0);

#define ISO_ANGLE 0.523599 // 30 grados en radianes

typedef struct s_vars {
	void *mlx;
	void *win;
}	t_vars;

int redraw(void *param)
{
	t_vars *vars = (t_vars *)param;
	draw_iso_rect(vars->mlx, vars->win, 450, 300);
	return (0);
}

void render (void *param){
	//mlx_pixel_put(mlx, win, 200, 151, 0xFFFF00);
	//mlx_pixel_put(mlx, win, 200, 152, 0xFFFFFF);	//Blanco
	//mlx_pixel_put(mlx, win, 200, 153, 0x000000);	//Negro
}

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

void draw_iso_rect(void *mlx, void *win, int x0, int y0)
{
    int x[4] = {0, 120, 120, 0};
    int y[4] = {0, 0, 100, 100};
    int px[4], py[4];
    int i;

    // Proyectar cada punto a isométrico y trasladar al centro de la ventana
    for (i = 0; i < 4; i++) {
        px[i] = x0 + (int)((x[i] - y[i]) * cos(ISO_ANGLE));
        py[i] = y0 + (int)((x[i] + y[i]) * sin(ISO_ANGLE));
    }

	

    // Dibujar los 4 lados del rectángulo
   
   for (i = 0; i < 4; i++) {
        int j = (i + 1) % 4;
        int dx = px[j] - px[i];
        int dy = py[j] - py[i];
        int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        float x_inc = dx / (float)steps;
        float y_inc = dy / (float)steps;
        float x_draw = px[i];
        float y_draw = py[i];
        for (int k = 0; k <= steps; k++) {
            mlx_pixel_put(mlx, win, (int)x_draw, (int)y_draw, 0x00FFFF);
            x_draw += x_inc;
            y_draw += y_inc;
        }
    }

	// Dibuja solo los 4 vértices
    for (i = 0; i < 4; i++) {
        mlx_pixel_put(mlx, win, px[i], py[i]-10, 0xFF0000); // Rojo, por ejemplo
    }
	

}

int main(void)
{
	t_vars vars;
	void *mlx;
	void *win;
	int i;

    //mlx = mlx_init();
	//win = mlx_new_window(mlx, 950, 540, "Hello world!");
	vars.mlx = mlx_init(); // ¡Inicializa aquí!
	vars.win = mlx_new_window(vars.mlx, 950, 540, "Hello world!");
	
	
	//mlx_pixel_put(mlx, win, 200, 150, 0xFF0000);
	//mlx_pixel_put(mlx, win, 200, 151, 0x00FF00);
	//mlx_pixel_put(mlx, win, 200, 152, 0x0000FF);

	//Dibuja linea horizontal
	/* 
	for (i = 0; i < 100; i++)
        mlx_pixel_put(mlx, win, 100 + i, 100, 0x0000FF);

	
	//Dibuja linea vertical
	i = 0;
	for (i = 0; i < 100; i++)
        mlx_pixel_put(mlx, win, 200, 200+i, 0x00FF00);

	//Dibuja linea perpendicular
	i = 0;
	for (i = 0; i < 100; i++)
        mlx_pixel_put(mlx, win, 300+i, 300+i, 0xFF0000);
	
	
	mlx_pixel_put(mlx, win, 0, 0, 0xFF0000);
	mlx_pixel_put(mlx, win, 150, 150, 0xFFFFFF);
	mlx_pixel_put(mlx, win, 300, 300, 0xFFFFFF);
	
	*/
	
	//mlx_pixel_put(mlx, win, 200, 151, 0xFFFF00);
	//mlx_pixel_put(mlx, win, 200, 152, 0xFFFFFF);	//Blanco
	//mlx_pixel_put(mlx, win, 200, 153, 0x000000);	//Negro

	//draw_iso_rect(mlx, win, 450, 300);
	draw_iso_rect(vars.mlx, vars.win, 450, 300);

    mlx_hook(vars.win, 17, 0, close_window, NULL);      // Cerrar con la X
    mlx_hook(vars.win, 2, 1L<<0, key_hook, NULL);       // Cerrar con ESC


	//mlx_hook(win, 17, 0, close_window, NULL);      // Cerrar con la X
    //mlx_hook(win, 2, 1L<<0, key_hook, NULL);       // Cerrar con ESC

	mlx_expose_hook(vars.win, redraw, &vars);           // Redibujar al exponer ventana

    mlx_loop(vars.mlx);

    //mlx_loop(mlx);
    return (0);
}