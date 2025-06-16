#include "rt1.h"

int	close_win(t_rt1 *rt1)
{
	if (rt1->mlx && rt1->mlx_win)
	{
		mlx_destroy_window(rt1->mlx, rt1->mlx_win);
		rt1->mlx_win = NULL;
		ft_putstr_fd("Window closed!\n", 1);
		free_all(rt1);
		exit(0);
	}
	return (0);
}
