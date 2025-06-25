#include "rt1.h"

float	hit_sphere(t_vector	sp_center, float radius, t_ray r)
{
	t_vector	oc;
	float		abc[3];
	float		delta;

	oc = vec3_sub(sp_center, r.origin);
	abc[0] = vec3_dot(r.dir, r.dir);
	abc[1] = -2.0 * vec3_dot(r.dir, oc);
	abc[2] = vec3_dot(oc, oc) - radius * radius;
	delta = abc[1] * abc[1] - 4 * abc[0] * abc[2];

	if (delta < 0)
		return (-1.0);
	else
		return ((- abc[1] - sqrt(delta)) / (2.0 * abc[0]));
}
