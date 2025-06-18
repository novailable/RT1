#include "rt1.h"

int	ft_color(t_vector color)
{
	int	r;
	int	g;
	int	b;

	r = color.x * 255.999;
	g = color.y * 255.999;
	b = color.z * 255.999;
	return ((r  << 16 ) | (g << 8) | b);
}
