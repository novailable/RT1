#include "rt1.h"

void	free_all(t_rt1 *rt1)
{
	if (rt1->mlx)
		free(rt1->mlx);
}
