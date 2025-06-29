#include "rt1.h"

void	print_vec3(t_vector vec3)
{
	printf("x : %f, y : %f, z : %f", vec3.x, vec3.y, vec3.z);
}

t_vector	vec3_init(float x, float y, float z)
{
	t_vector	vec3;

	vec3.x = x;
	vec3.y = y;
	vec3.z = z;
	return (vec3);
}

t_vector	vec3_scale(t_vector vec3, float value)
{
	return (vec3_init(vec3.x * value, vec3.y * value, vec3.z *value));
}

t_vector	_vec3(t_vector vec3)
{
	return (vec3_scale(vec3, -1));
}

float	vec3_len_sq(t_vector vec3)
{
	return ((vec3.x * vec3.x) + (vec3.y * vec3.y) + (vec3.z * vec3.z));
}

float	vec3_length(t_vector vec3)
{
	return (sqrt(vec3_len_sq(vec3)));
}

t_vector	vec3_add(t_vector a, t_vector b)
{
	return (vec3_init(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vector	vec3_sub(t_vector a, t_vector b)
{
	return (vec3_init(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vector	vec3_multi(t_vector a, t_vector b)
{
	return (vec3_init(a.x * b.x, a.y * b.y, a.z * b.z));
}

float	vec3_dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	vec3_cross(t_vector a, t_vector b)
{
	return (vec3_init(a.y * b.z - a.z * b.y, \
					a.z * b.x - a.x * b.z, \
					a.x * b.y - a.y * b.x));
}

t_vector	vec3_unit(t_vector vec3)
{
	float len;

	len = vec3_length(vec3);
	if (len == 0)
		return vec3;
	return (vec3_scale(vec3, 1 / len));
}
