#include "rt1.h"

t_vector	get_color(t_rt1 *rt1, t_vector pixel_x, t_vector pixel_y)
{
	t_vector	pixel_center;
	t_camera	camera;
	t_vector	ray_direction;

	camera = rt1->camera;
	pixel_center = vec3_add(vec3_add(camera.pixel_00, pixel_x), pixel_y);
	ray_direction = vec3_sub(pixel_center, camera.center);
	return (ray_color(ray_init(camera.center, ray_direction)));
}

int		paint(t_rt1 *rt1)
{
	t_image		img;
	float		r;
	float		g;
	float		b;
	t_vector	color;
	float		pixel_center;

	img = rt1->img;
	for (int y = 0; y < img.height; y++)
	{
		for (int x = 0; x < img.width; x++)
		{
			color = get_color(rt1, vec3_scale(rt1->camera.pixel_x, x), 
								vec3_scale(rt1->camera.pixel_y, y));
			img_pixel_put(rt1, x, y, ft_color(color));
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
	rt1.mlx = mlx_init();
	rt1.mlx_win = mlx_new_window(rt1.mlx, WIN_WIDTH, WIN_HEIGHT, "RayTracingInOneWeekend");
	create_image(&rt1);
	rt1.camera = camera_init(rt1, vec3_init(0, 0, 0), 2.0, 1.0);
	print_camera(rt1.camera);
	paint(&rt1);
	put_image_back(&rt1);
	mlx_hook(rt1.mlx_win, 17, 0, close_win, &rt1);
	mlx_key_hook(rt1.mlx_win, key_handle, &rt1);
	mlx_loop(rt1.mlx);
}
