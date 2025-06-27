#include "rt1.h"

t_sphere	init_sphere(t_vector center, float radius)
{
	t_sphere	sphere;

	ft_bzero(&sphere, sizeof(sphere));
	sphere.center = center;
	sphere.radius = radius;
	return	(sphere);
}

int	hit_sphere(t_sphere sphere, t_ray ray, t_hits *hits)
{
	t_vector	oc;
	float		ahc[3];
	float		delta;
	float		sq_delta;
	float		root;

	oc = vec3_sub(sphere.center, ray.origin);
	ahc[0] = vec3_len_sq(ray.dir);
	ahc[1] = vec3_dot(ray.dir, oc);
	ahc[2] = vec3_len_sq(oc) - sphere.radius * sphere.radius;
	delta = ahc[1] * ahc[1] - ahc[0] * ahc[2];
	if (delta < 0)
		return (0);
	sq_delta = sqrt(delta);
	root = (ahc[1] - sq_delta) / ahc[0];
	if (root <= ray.t_min || ray.t_max <= root)
	{
		root = (ahc[1] + sq_delta) / ahc[0];
		if (root <= ray.t_min || ray.t_max <= root)
			return (0);
		hits->t = root;
		hits->P = ray_pos(ray, hits->t);
		hits->normal = vec3_scale(vec3_sub(hits->P, sphere.center), 1 / sphere.radius);
        return (1);
    }
}
