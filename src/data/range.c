#include "rt1.h"

t_range	init_range(float min, float max)
{
	t_range	range;

	range.min = min;
	range.max = max;
	return (range);
}

float	range_size(t_range range)
{
	return (range.max - range.max);
}

int	contain(t_range range, float x)
{
	return (range.min <= x && x <= range.max);
}

int	surrond(t_range range, float x)
{
	return (range.min < x && x < range.max);
}

float	clamp(t_range range, float x)
{
	if (x < range.min)
		return (range.min);
	if (x > range.max)
		return (range.max);
	return (x);
}
