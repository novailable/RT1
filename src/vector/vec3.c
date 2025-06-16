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

void	vec3_add(t_vector *dst, t_vector *src)
{
	if (!dst || !src)
		return ;
	dst->x += src->x;
	dst->y += src->y;
	dst->z += src->z;
}

void	vec3_scale(t_vector *vec3, float value)
{
	if (!vec3)
		return ;
	vec3->x *= value;
	vec3->y *= value;
	vec3->z *= value;
}

void	vec3_scale_down(t_vector *vec3, float value)
{
	if (!vec3 || value == 0.0f)
		return; 
	vec3_scale(vec3, 1/value);
}


