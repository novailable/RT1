#include "rt1.h"

void	print_sphere(void *data)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)data;
	printf("sphere - center: "); 
	print_vec3(sphere->center);
	printf(", radius - %f\n", sphere->radius);
}

t_sphere	*init_sphere(t_vector center, float radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	ft_bzero(sphere, sizeof(sphere));
	sphere->center = center;
	sphere->radius = radius;
	return	(sphere);
}

int	hit_sphere(void *data, t_ray ray, t_hit *hit)
{
	t_vector	oc;
	float		ahc[3];
	float		delta;
	float		sq_delta;
	float		root;
	t_sphere	*sphere;

	sphere = (t_sphere *)data;
	// printf("hit_sphere\n");
	oc = vec3_sub(sphere->center, ray.origin);
	ahc[0] = vec3_len_sq(ray.dir);
	ahc[1] = vec3_dot(ray.dir, oc);
	ahc[2] = vec3_len_sq(oc) - sphere->radius * sphere->radius;
	delta = ahc[1] * ahc[1] - ahc[0] * ahc[2];
	if (delta < 0)
		return (0);
	sq_delta = sqrt(delta);
	root = (ahc[1] - sq_delta) / ahc[0];
	if (!surrond(ray.range, root))
	{
		root = (ahc[1] + sq_delta) / ahc[0];
		if (!surrond(ray.range, root))
			return (0);
	}
	hit->t = root;
	hit->P = ray_pos(ray, hit->t);
	hit->normal = vec3_scale(vec3_sub(hit->P, sphere->center), 1 / sphere->radius);
	set_face_normal(ray, hit);
	return (1);
}

void	free_sphere(void *sphere)
{
	if (sphere)
		free(sphere);
}