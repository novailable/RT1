#include "rt1.h"

void	put_image_back(t_rt1 *rt1)
{
	mlx_put_image_to_window(rt1->mlx, rt1->mlx_win, rt1->img.mlx_img, 0, 0);
}

void	create_image(t_rt1 *rt1, int (*func)())
{
	rt1->img.width = WIN_WIDTH;
	if (WIN_HEIGHT < 1)
		rt1->img.height = 1;
	else
		rt1->img.height = WIN_HEIGHT;
	rt1->img.mlx_img = mlx_new_image(rt1->mlx, rt1->img.width, rt1->img.height);
	rt1->img.mlx_img_data = mlx_get_data_addr(rt1->img.mlx_img, &rt1->img.bpp, &rt1->img.size_line, &rt1->img.endian);
	rt1->img.bypp = rt1->img.bpp / 8;
	printf("image created\n");
	if (func)
		func(rt1);
	put_image_back(rt1);
}

void	img_pixel_put(t_rt1 *rt1, int x, int y, int color)
{
	int	pos;

	if (x < 0 || x > rt1->img.width || y < 0 || y > rt1->img.height)
		return ;
    pos = y * rt1->img.size_line + x * rt1->img.bypp;
    *(unsigned int *)(rt1->img.mlx_img_data + pos) = color;
}
