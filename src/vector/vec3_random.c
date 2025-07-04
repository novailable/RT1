#include "rt1.h"

t_vector	vec3_random()
{
	return (vec3_init(random_float(), random_float(), random_float()));
}

t_vector	vec3_random_range(float min, float max)
{
	return (vec3_init(random_range(min, max), random_range(min, max), random_range(min, max)));
}

t_vector	vec3_random_unit()
{
	t_vector	point;
	float		len_sq;
	while (1)
	{
		point = vec3_random_range(1, -1);
		len_sq = vec3_len_sq(point);
		if (1e-160 <= len_sq && len_sq <= 1)
			return (vec3_scale(point , 1 / sqrt(len_sq)));
	}
}

t_vector	vec3_random_hemisphere(t_vector normal)
{
	t_vector	random_ray;
	
	random_ray = vec3_random_unit();
	if (vec3_dot(random_ray, normal) > 0.0)
		return (random_ray);
	return (_vec3(random_ray));
}
