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
