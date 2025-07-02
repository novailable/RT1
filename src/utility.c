#include "rt1.h"

float	to_radians(float degree)
{
	return (degree * M_PI / 180.0);
}

float	random_float()
{
	return (rand() / (RAND_MAX + 1.0));
}

float	random_range(float min, float max)
{
	return (min + (max - min) * random_float());
}
