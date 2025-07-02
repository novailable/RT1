#include "rt1.h"

// t_vector	get_color(t_camera camera, t_list *world, float x, float y)
// {
// 	// t_vector	pixel_center;
// 	t_vector	ray_direction;
// 	t_vector	sample_center;
// 	t_vector	pixel_color;
// 	t_vector	offset_xy[2];

// 	pixel_color = vec3_init(0, 0, 0);
// 	for (int sample = 0; sample < SAMPLE; sample++)
// 	{
// 		int	sx = sample % SAMPLE;
// 		int	sy = sample / SAMPLE;

// 		x = x + (sx + 0.5f) / SAMPLE;
// 		y = y + (sy + 0.5f) / SAMPLE;

// 		offset_xy[0] = vec3_scale(camera.pixel_x, x);
// 		offset_xy[1] = vec3_scale(camera.pixel_y, y);
// 		sample_center = vec3_add(camera.pixel_00, vec3_add(offset_xy[0], offset_xy[1]));
// 		ray_direction = vec3_sub(sample_center, camera.center);
// 		pixel_color = vec3_add(pixel_color, ray_color(ray_init(camera.center, ray_direction), world));
// 	}
// 	return (vec3_scale(pixel_color, (float)1 / SAMPLE));
// }

/* random sampling */
t_vector	get_color(t_camera camera, t_list *world, float x, float y)
{
	// t_vector	pixel_center;
	t_vector	ray_direction;
	t_vector	sample_center;
	t_vector	pixel_color;
	t_vector	offset_xy[2];

	pixel_color = vec3_init(0, 0, 0);
	for (int sample = 0; sample < SAMPLE; sample++)
	{
		t_vector	offset = vec3_init(random_float() - 0.5, random_float() - 0.5, 0);
		sample_center = vec3_add(vec3_scale(camera.pixel_x, x + offset.x), vec3_scale(camera.pixel_y, y + offset.y));
		sample_center = vec3_add(camera.pixel_00, sample_center);
		ray_direction = vec3_sub(sample_center, camera.center);
		pixel_color = vec3_add(pixel_color, ray_color(ray_init(camera.center, ray_direction), world));
	}
	return (vec3_scale(pixel_color, (float)1 / SAMPLE));
}

int		paint(t_rt1 *rt1)
{
	t_image		img;
	t_vector	color;
	float		pixel_center;
	t_vector	sample_offset;

	img = rt1->img;
	for (int y = 0; y < img.height; y++)
	{
		for (int x = 0; x < img.width; x++)
		{
			color = get_color(rt1->camera, rt1->world, x, y);
			img_pixel_put(rt1, x, y, ft_color(color));
		}
	}
	printf("Done\n");
	return (0);
}

int	main()
{
	t_rt1		rt1;
	t_ray		ray;
	
	ft_bzero(&rt1, sizeof(rt1));
	add_w_item(&rt1.world, (void *)init_sphere(vec3_init(0, 0, -1), 0.5), hit_sphere, free_sphere, print_sphere);
	add_w_item(&rt1.world, (void *)init_sphere(vec3_init(0, -100.5, -1), 100), hit_sphere, free_sphere, print_sphere);
	// print_world(rt1.world->data);
	ray = ray_init(vec3_init(1, 2, 3), vec3_init(4, 5, 6));
	rt1.mlx = mlx_init();
	rt1.mlx_win = mlx_new_window(rt1.mlx, WIN_WIDTH, WIN_HEIGHT, "RayTracingInOneWeekend");
	create_image(&rt1);
	rt1.camera = camera_init(rt1, vec3_init(0, 0, 0), 2.0, 1.0);
	paint(&rt1);
	put_image_back(&rt1);
	mlx_hook(rt1.mlx_win, 17, 0, close_win, &rt1);
	mlx_key_hook(rt1.mlx_win, key_handle, &rt1);
	mlx_loop(rt1.mlx);
}
