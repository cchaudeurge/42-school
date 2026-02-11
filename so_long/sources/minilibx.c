#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	closew(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int handle_key(int keycode, void *param)
{
    (void)param;
    printf("keycode: %d\n", keycode);
    return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
    {
        perror("mlx_init failed");
        return (1);
    }
	vars.win = mlx_new_window(vars.mlx, 100, 100, "Hello world!");
	if (!vars.win)
    {
        perror("mlx_new_window failed");
        return (1);
    }
	mlx_key_hook(vars.win, handle_key, &vars);
	//mlx_hook(vars.win, 2, 1L<<0, closew, &vars);
	mlx_loop(vars.mlx);
}

/*typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int	main(void)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;
	int		x;
	int		y;
	int		temp;
	int		step;
	int red;
	int green;
	int blue;
	int color;
	int		width = 1000;
	int		height = 1000;
	
	x = 25;
	y = 25;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "Hello world!");
	img.img = mlx_new_image(mlx, width, height);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while(x < width)
	{
		red = x % 255;
		green = y % 255;
		blue = (93) % 255;
		color = (red << 16) | (green << 8) | blue;
		my_mlx_pixel_put(&img, x, y, color);
		temp = y;
		while(y < height - 25)
		{
			red = x % 255;
			green = y % 255;
			blue = (x * y) % 255;
			color = (red << 16) | (green << 8) | blue;
			my_mlx_pixel_put(&img, x, y, color);
			y++;
		}
		y = temp++;
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);	
	mlx_loop(mlx);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/
