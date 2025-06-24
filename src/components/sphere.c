#include "rt1.h"

int	hit_sphere(t_vector	sp_center, float radius, t_ray r)
{
	t_vector	oc;
	float		a;
	float		b;
	float		c;

	oc = vec3_sub(sp_center, r.origin);
	a = vec3_dot(r.dir, r.dir);
	b = -2.0 * vec3_dot(r.dir, oc);
	c = vec3_dot(oc, oc) - radius * radius;
	return ((b * b - 4 * a * c) >= 0);
}
