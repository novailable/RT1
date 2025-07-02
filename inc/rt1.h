#ifndef RT1_H
#define RT1_H

#include "libft.h"
#include "gnl.h"
#include <mlx.h>
#include <math.h>
#include <float.h>

#define WIN_RATIO    (16.0f / 9.0f)
#define WIN_WIDTH    800
#define WIN_HEIGHT   (int)(WIN_WIDTH / WIN_RATIO)
#define	LIGHT_SOURCE	((t_vector){1, 1, 1})
#define	SAMPLE	1
// #define vec_init(x) _Generic((x), float:)

typedef	struct	s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct	s_range
{
	float	min;
	float	max;
}	t_range;

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

typedef	struct s_camera
{
	float		vp_width;	// view_port
	float		vp_height;
	float		fl;			// focal length
	t_vector	center;
	t_vector	vp_center;
	t_vector	vec3_x;		// u
	t_vector	vec3_y;		// v
	t_vector	pixel_x;
	t_vector	pixel_y;
	t_vector	vp_00;
	t_vector	pixel_00;
}	t_camera;

typedef struct	s_sphere
{
	t_vector	center;
	float		radius;
}	t_sphere;

typedef struct	s_rt1
{
	void		*mlx;
	void		*mlx_win;
	t_list		*world;
	t_image		img;
	t_camera	camera;
}	t_rt1;

typedef struct s_hit
{
	t_vector	P;
	t_vector	normal;
	float		t;
	int			front_face;
}	t_hit;

typedef	struct s_ray
{
	t_vector	origin;
	t_vector	dir;
	float		t_min;
	float		t_max;
	t_range		range;
	t_hit		hit;
	int			hit_anything;
}	t_ray;

typedef enum e_obj_type 
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
}	t_obj_type;

typedef struct s_objs
{
	void	*data;
	int		(*hit)(void *, t_ray, t_hit *);
	void	(*destory)(void *);
	void	(*print)(void *);
}	t_objs;


// control
int		key_handle(int keycode, void *param);
int		close_win(t_rt1 *rt1);

// data
	// image
	void	put_image_back(t_rt1 *rt1);
	void	create_image(t_rt1 *rt1);
	void	img_pixel_put(t_rt1 *rt1, int x, int y, int color);
	void	print_image(t_image img);

	// color
	int	ft_color(t_vector color);

	// ray
	t_vector	ray_color(t_ray ray, t_list *world);

	// range
		t_range	init_range(float min, float max);
		float	range_size(t_range range);
		int		contain(t_range range, float x);
		int		surrond(t_range range, float x);
		float	clamp(t_range range, float x);


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

// camera
void	print_camera(t_camera camera);
t_camera	camera_init(t_rt1 rt1, t_vector center, float vp_height, float fl);

// ray
void	print_ray(t_ray ray);
t_ray		ray_init(t_vector origin, t_vector dir);
t_vector	ray_pos(t_ray ray, float t);
void	set_face_normal(t_ray ray, t_hit *hit);


// components
	// world
	void	print_world(void *data);
	void	add_w_item(t_list **world, void *data, int (*hit)(), void (*destory)(void *), void (*print)(void *));
	void	world_hit(void *data, void *param);

	// sphere
	void	print_sphere(void *data);
	t_sphere	*init_sphere(t_vector center, float radius);
	int	hit_sphere(void	*sphere, t_ray ray, t_hit *hit);


// free
void	free_all(t_rt1 *rt1);
void	free_sphere(void *sphere);

// utility
float	random_float();
float	random_range(float, float);

#endif