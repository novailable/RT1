#include "rt1.h"

// inline double linear_to_gamma(double linear_component)
// {
//     if (linear_component > 0)
//         return std::sqrt(linear_component);

//     return 0;
// }
float	linear_to_gamma(float linear_component)
{
	if (linear_component > 0)
		return (sqrt(linear_component));
	return (0);
}

int	ft_color(t_vector color)
{
	t_range	intensity;

	color = vec3_func(color, linear_to_gamma);
	intensity = init_range(0.000, 0.999);
	color.x = clamp(intensity, color.x);
	color.y = clamp(intensity, color.y);
	color.z = clamp(intensity, color.z);
	color = vec3_scale(color, 256);
	return (((int) color.x  << 16 ) | ((int) color.y << 8) | (int) color.z);
}
