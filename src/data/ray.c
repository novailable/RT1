#include "rt1.h"

void	print_ray(t_ray ray)
{
	printf("origin\t\t: ");
	print_vec3(ray.origin);
	printf("direction\t: ");
	print_vec3(ray.dir);
}

t_ray	ray_init(t_vector origin, t_vector dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = dir;
	return (ray);
}

t_vector	ray_pos(t_ray ray, float t)
{
	return (vec3_add(ray.origin, vec3_scale(ray.dir, t)));
}

t_vector	ray_color(t_ray ray)
{
	t_vector	unit_direction;
	t_vector	temp;
	t_vector	color;
	float		positive_y;

	if (hit_sphere(vec3_init(0, 0, -1), 0.5, ray))
		return (vec3_init(1, 0, 0));
	unit_direction = vec3_unit(ray.dir);
	positive_y = 0.5 * (unit_direction.y + 1.0);
	temp = vec3_scale(vec3_init(1.0, 1.0, 1.0), 1.0 - positive_y);
	color = vec3_add(temp, vec3_scale(vec3_init(0.5, 0.7, 1.0), positive_y));
	return (color);
}