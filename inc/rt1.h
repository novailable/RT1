#ifndef RT1_H
#define RT1_H

#include "libft.h"
#include "gnl.h"
#include <mlx.h>
#include <math.h>

#define WIN_RATIO    (16.0f / 9.0f)
#define WIN_WIDTH    800
#define WIN_HEIGHT   (int)(WIN_WIDTH / WIN_RATIO)

// #define vec_init(x) _Generic((x), float:)

typedef	struct	s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;


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


// auto aspect_ratio = 16.0 / 9.0;
// int image_width = 400;

// // Calculate the image height, and ensure that it's at least 1.
// int image_height = int(image_width / aspect_ratio);
// image_height = (image_height < 1) ? 1 : image_height;

// // Camera

// auto focal_length = 1.0;
// auto viewport_height = 2.0;
// auto viewport_width = viewport_height * (double(image_width)/image_height);
// auto camera_center = point3(0, 0, 0);

// // Calculate the vectors across the horizontal and down the vertical viewport edges.
// auto viewport_u = vec3(viewport_width, 0, 0);
// auto viewport_v = vec3(0, -viewport_height, 0);

// // Calculate the horizontal and vertical delta vectors from pixel to pixel.
// auto pixel_delta_u = viewport_u / image_width;
// auto pixel_delta_v = viewport_v / image_height;

// // Calculate the location of the upper left pixel.
// auto viewport_upper_left = camera_center
// 						 - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
// auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);


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

typedef struct	s_rt1
{
	void		*mlx;
	void		*mlx_win;
	t_image		img;
	t_vector	vec3;
	t_camera	camera;
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
	// image
	void	put_image_back(t_rt1 *rt1);
	void	create_image(t_rt1 *rt1);
	void	img_pixel_put(t_rt1 *rt1, int x, int y, int color);
	void	print_image(t_image img);

	// color
	int	ft_color(t_vector color);

	// ray
	t_vector	ray_color(t_ray ray);

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

// components
int	hit_sphere(t_vector	sp_center, float radius, t_ray r);


// free
void	free_all(t_rt1 *rt1);

#endif