#include "rt1.h"

int		paint(t_rt1 *rt1)
{
	t_image	img;
	float	r;
	float	g;
	float	b;

	img = rt1->img;
	for (int y = 0; y < img.height; y++)
	{
		printf("\rScanlines remaining: %d\n", img.height - y);
		for (int x = 0; x < img.width; x++)
		{
			r = (float) x / (img.width - 1);
			g = (float) y / (img.height - 1);
			b = 0.0;
			img_pixel_put(rt1, x, y, ft_color(255.9 * r, 255.9 * g, 255.9 * b));
		}
	}
	printf("Done\n");
	return (0);
}

void	vector_test()
{
	t_vector	a;
	t_vector	b;

	a = vec3_init(1, 2, 3);
	b = vec3_init(4, 5, 6);

	printf("%f, %f\n", vec3_len_square(&a, &b), vec3_length(&a, &b));
	print_vec3(a);
}

int	main()
{
	t_rt1		rt1;
	t_image 	img;
	t_vector	vec3;

	ft_bzero(&rt1, sizeof(rt1));
	rt1.mlx = mlx_init();
	rt1.mlx_win = mlx_new_window(rt1.mlx, WIN_WIDTH, WIN_HEIGHT, "RayTracingInOneWeekend");
	create_image(&rt1, paint);
	img = rt1.img;
	// vector_test();
	mlx_hook(rt1.mlx_win, 17, 0, close_win, &rt1);
	mlx_key_hook(rt1.mlx_win, key_handle, &rt1);
	mlx_loop(rt1.mlx);
}