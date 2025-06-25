#include "rt1.h"

float	hit_sphere(t_vector	sp_center, float radius, t_ray r)
{
	t_vector	oc;
	float		ahc[3];
	float		delta;

	oc = vec3_sub(sp_center, r.origin);
	ahc[0] = vec3_len_sq(r.dir);
	ahc[1] = vec3_dot(r.dir, oc);
	ahc[2] = vec3_len_sq(oc) - radius * radius;
	delta = ahc[1] * ahc[1] - ahc[0] * ahc[2];

	if (delta < 0)
		return (-1.0);
	else
		return ((ahc[1] - sqrt(delta)) / ahc[0]);
}
