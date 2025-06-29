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

	ft_bzero(&ray, sizeof(ray));
	ray.origin = origin;
	ray.dir = dir;
	ray.t_max = FLT_MAX;
	ray.t_min = 0;
	return (ray);
}

t_vector	ray_pos(t_ray ray, float t)
{
	return (vec3_add(ray.origin, vec3_scale(ray.dir, t)));
}
t_vector	ray_color(t_ray ray, t_list *world)
{
	t_vector	color;
	t_vector	unit_direction;
	float		positive_y;
	t_vector	temp;
	t_hit		hit;

	ft_bzero(&color, sizeof(t_vector));
	ft_lstiter_param(world, world_hit, &ray);
	if (ray.hit_anything)
	{
		return (vec3_scale(vec3_add(ray.hit.normal, LIGHT_SOURCE), 0.5));
	}
	unit_direction = vec3_unit(ray.dir);
	positive_y = 0.5 * (unit_direction.y + 1.0);
	temp = vec3_scale(vec3_init(1.0, 1.0, 1.0), (1 - positive_y));
	color = vec3_add(temp, vec3_scale(vec3_init(0.5, 0.7, 1.0), positive_y));
	return (color);
}

void	set_face_normal(t_ray ray, t_hit *hit)
{
	hit->front_face = vec3_dot(ray.dir, hit->normal) < 0;
	if (!hit->front_face)
		hit->normal = _vec3(hit->normal);
}