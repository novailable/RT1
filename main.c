#include "rt1.h"

int		paint(t_rt1 *rt1)
{
	t_image		img;
	float		r;
	float		g;
	float		b;
	t_vector	color;

	img = rt1->img;
	for (int y = 0; y < img.height; y++)
	{
		printf("\rScanlines remaining: %d\n", img.height - y);
		for (int x = 0; x < img.width; x++)
		{
			img_pixel_put(rt1, x, y, ft_color(vec3_init((float) x / (img.width - 1), (float) y / (img.height - 1), 0)));
		}
	}
	printf("Done\n");
	return (0);
}

int	main()
{
	t_rt1		rt1;
	t_image 	img;
	t_vector	color;
	t_ray		ray;

	ft_bzero(&rt1, sizeof(rt1));
	ray = ray_init(vec3_init(1, 2, 3), vec3_init(4, 5, 6));
	// rt1.mlx = mlx_init();
	// rt1.mlx_win = mlx_new_window(rt1.mlx, WIN_WIDTH, WIN_HEIGHT, "RayTracingInOneWeekend");
	// create_image(&rt1, paint);
	// img = rt1.img;
	// mlx_hook(rt1.mlx_win, 17, 0, close_win, &rt1);
	// mlx_key_hook(rt1.mlx_win, key_handle, &rt1);
	// mlx_loop(rt1.mlx);
}