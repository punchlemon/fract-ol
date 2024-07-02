#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "../mlx/mlx.h"
#include "fract-ol.h"

#define ESC 65307

int	event_handler(int key, void *mlx)
{
	printf("key: %d\n", key);
	if (key == ESC)
		mlx_destroy_window(mlx, mlx);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_rectangle(t_data *data, int x, int y, int a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a)
	{
		j = 0;
		while (j < a)
		{
			my_mlx_pixel_put(data, x + i, y + j, 0x00FF33FF);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_data *data, int x, int y, int r)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1920)
		{
			if (i * i + j * j < r * r)
				my_mlx_pixel_put(data, x + i, y + j, 0x00AACCBB);
			j++;
		}
		i++;
	}
}

int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	draw_circle(&img, 100, 100, 50);
	draw_rectangle(&img, 200, 200, 30);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_key_hook(win, event_handler, mlx);
	mlx_loop(mlx);
	return (0);
}
