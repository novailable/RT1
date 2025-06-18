#ifndef RT1_H
#define RT1_H

#include "libft.h"
#include "gnl.h"
#include <mlx.h>
#include <math.h>

#define WIN_RATIO    (16.0f / 9.0f)
#define WIN_WIDTH    800
#define WIN_HEIGHT   (int)(WIN_WIDTH / WIN_RATIO)

#define vec_init(x) _Generic((x), float:)


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

typedef	struct s_ray
{
	t_vector	origin;
	t_vector	dir;
}	t_ray;

// control
int		key_handle(int keycode, void *param);
int		close_win(t_rt1 *rt1);

// data
void	put_image_back(t_rt1 *rt1);
void	create_image(t_rt1 *rt1, int (*func)());
void	img_pixel_put(t_rt1 *rt1, int x, int y, int color);
	// color
	int	ft_color(t_vector color);

// vector
void		print_vec3(t_vector vec3);
t_vector	vec3_init(float x, float y, float z);
t_vector	_vec3(t_vector vec3);
t_vector	vec3_scale(t_vector vec3, float value);
float		vec3_len_sq(t_vector vec3);
float		vec3_length(t_vector vec3);
t_vector	vec3_add(t_vector a, t_vector b);
t_vector	vec3_sub(t_vector dst, t_vector src);
t_vector	vec3_multi(t_vector a, t_vector b);
float		vec3_dot(t_vector a, t_vector b);
t_vector	vec3_cross(t_vector a, t_vector b);
t_vector	vec3_unit(t_vector vec3);

// ray
void	print_ray(t_ray ray);
t_ray		ray_init(t_vector origin, t_vector dir);
t_vector	ray_pos(t_ray ray, float t);

// free
void	free_all(t_rt1 *rt1);

#endif