#include "rt1.h"

int	key_handle(int keycode, void *param)
{
	t_rt1	*rt1;

	rt1 = (t_rt1 *)param;
	printf("keycode : %d\n", keycode);
	if (keycode == 65307 || keycode == 53)
		close_win(rt1);
	return (0);
}
