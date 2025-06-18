#include "rt1.h"

int	ft_color(t_vector color)
{
	color = vec3_scale(color, 255.9);
	return (((int) color.x  << 16 ) | ((int) color.y << 8) | (int) color.z);
}
