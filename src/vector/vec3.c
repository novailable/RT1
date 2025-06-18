#include "rt1.h"

void	print_vec3(t_vector vec3)
{
	printf("x : %f, y : %f, z : %f\n", vec3.x, vec3.y, vec3.z);
}

t_vector	vec3_init(float x, float y, float z)
{
	t_vector	vec3;

	vec3.x = x;
	vec3.y = y;
	vec3.z = z;
	return (vec3);
}

void	_vec3(t_vector *vec3)
{
	if (vec3)
	{
		vec3->x = -vec3->x;
		vec3->y = -vec3->y;
		vec3->z = -vec3->z;
	}
}

t_vector	vec3_scale(t_vector *vec3, float value)
{
	if (!vec3)
		return (*vec3);
	vec3->x *= value;
	vec3->y *= value;
	vec3->z *= value;
	return (*vec3);
}

void	vec3_scale_down(t_vector *vec3, float value)
{
	if (!vec3 || value == 0.0f)
		return; 
	vec3_scale(vec3, 1/value);
}

float	vec3_len_square(t_vector *vec3)
{
	return ((vec3->x * vec3->x) + (vec3->y * vec3->y) + (vec3->z * vec3->z));
}

float	vec3_length(t_vector *a)
{
	return (sqrt(vec3_len_square(a)));
}

t_vector	vec3_add(t_vector *dst, t_vector *src)
{
	if (!dst || !src)
		return (*dst);
	dst->x += src->x;
	dst->y += src->y;
	dst->z += src->z;
	return (*dst);
}

t_vector	vec3_sub(t_vector *dst, t_vector *src)
{
	if (!dst || !src)
		return (*dst);
	dst->x -= src->x;
	dst->y -= src->y;
	dst->z -= src->z;
	return (*dst);
}

t_vector	vec3_multi(t_vector *dst, t_vector *src)
{
	if (!dst || !src)
		return (*dst);
	dst->x *= src->x;
	dst->y *= src->y;
	dst->z *= src->z;
	return (*dst);
}

float	vec3_dot(t_vector *a, t_vector *b)
{
	if (!a || !b)
		return (0);
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vector	vec3_cross(t_vector *a, t_vector *b)
{
	t_vector	result;

	if (!a || !b)
		return (*a);
	result = vec3_init(a->y * b->z - a->z * b->y, \
					a->z * b->x - a->x * b->z, \
					a->x * b->y - a->y * b->x);
	return (result);
}

t_vector	vec3_unit(t_vector *vec3)
{
	float len = vec3_length(vec3);
	if (len == 0)
		return *vec3;
	return (vec3_scale(vec3, 1 / len));
}
