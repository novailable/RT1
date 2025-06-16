#ifndef RT1_H
#define RT1_H

#include "libft.h"
#include "gnl.h"
#include <mlx.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

typedef	struct s_image
{
	void	*mlx_img;
	char	*mlx_img_data;
	int		width;
	int		height;
	int		bpp;
	int		bypp;
	int		size_line;
	int		endian;
}	t_image;

typedef	struct	s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct	s_rt1
{
	void		*mlx;
	void		*mlx_win;
	t_image		img;
	t_vector	vec3;
}	t_rt1;

// control
int		key_handle(int keycode, void *param);
int		close_win(t_rt1 *rt1);

// data
void	put_image_back(t_rt1 *rt1);
void	create_image(t_rt1 *rt1, int (*func)(t_rt1 *));
void	img_pixel_put(t_rt1 *rt1, int x, int y, int color);
	// color
	int	ft_color(int r, int g, int b);

// free
void	free_all(t_rt1 *rt1);

#endif