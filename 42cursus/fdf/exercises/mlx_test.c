#include "mlx.h"
#include "libft.h"

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

int main(void)
{
    void *mlx;
    void *win;
	int i;

    mlx = mlx_init();
	win = mlx_new_window(mlx, 950, 540, "Hello world!");
	
	
	//mlx_pixel_put(mlx, win, 200, 150, 0xFF0000);
	//mlx_pixel_put(mlx, win, 200, 151, 0x00FF00);
	//mlx_pixel_put(mlx, win, 200, 152, 0x0000FF);

	//Dibuja linea horizontal
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
	
	//mlx_pixel_put(mlx, win, 200, 151, 0xFFFF00);
	//mlx_pixel_put(mlx, win, 200, 152, 0xFFFFFF);	//Blanco
	//mlx_pixel_put(mlx, win, 200, 153, 0x000000);	//Negro

	mlx_hook(win, 17, 0, close_window, NULL);      // Cerrar con la X
    mlx_hook(win, 2, 1L<<0, key_hook, NULL);       // Cerrar con ESC

    mlx_loop(mlx);
    return (0);
}