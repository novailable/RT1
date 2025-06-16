#include "rt1.h"

int	ft_color(int r, int g, int b)
{
	return ((r << 16 ) | (g << 8) | b);
}
