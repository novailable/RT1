#include "rt1.h"

int	ft_color(t_vector color)
{
	t_range	intensity;

	intensity = init_range(0.000, 0.999);
	color.x = clamp(intensity, color.x);
	color.y = clamp(intensity, color.y);
	color.z = clamp(intensity, color.z);
	color = vec3_scale(color, 256);
	return (((int) color.x  << 16 ) | ((int) color.y << 8) | (int) color.z);
}
