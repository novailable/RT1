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
	return (ray);
}

t_vector	ray_pos(t_ray ray, float t)
{
	return (vec3_add(ray.origin, vec3_scale(ray.dir, t)));
}
t_vector ray_color(t_ray ray)
{
	float		t;
	t_vector	N;
	t_vector	color;
	t_vector	unit_direction;
	float		positive_y;
	t_vector	temp;

	// print_ray(ray);
	t = hit_sphere(init_sphere(vec3_init(0, 0, -1), 0.5), ray, );
	if (t > 0.0)
	{
		N = vec3_unit(vec3_sub(ray_pos(ray, t), vec3_init(0, 0, -1)));
		color = vec3_scale(vec3_init(N.x + 1, N.y + 1, N.z + 1), 0.5);
		return (color);
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