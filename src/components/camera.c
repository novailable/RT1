#include "rt1.h"

void	print_camera(t_camera camera)
{
	printf("viewport width\t- %f, viewport height:%f\n", camera.vp_width, camera.vp_height);
	printf("focal length\t- %f\n", camera.fl);
	printf("vec3_x\t\t- "), print_vec3(camera.vec3_x);
	printf("vec3_y\t\t- "), print_vec3(camera.vec3_y);
	printf("pixel_x\t\t- "), print_vec3(camera.pixel_x);
	printf("pixel_y\t\t- "), print_vec3(camera.pixel_y);
	printf("vp_00\t\t- "), print_vec3(camera.vp_00);
	printf("pixel_00\t- "), print_vec3(camera.pixel_00);
}

t_camera	camera_init(t_rt1 rt1, t_vector center, float vp_height, float fl)
{
	t_camera	camera;
	t_image		img;
	t_vector	vp_offset;
	t_vector	pixel_offset;

	camera = rt1.camera;
	img = rt1.img;
	camera.vp_height = vp_height;
	camera.vp_width = camera.vp_height * ((float)img.width / img.height);
	camera.fl = fl;
	camera.center = center;
	camera.vec3_x = vec3_init(camera.vp_width, 0, 0);
	camera.vec3_y = vec3_init(0, -camera.vp_height, 0);
	camera.pixel_x = vec3_scale(camera.vec3_x, 1 / (float)img.width); 
	camera.pixel_y = vec3_scale(camera.vec3_y, 1 / (float)img.height);
	camera.vp_center = vec3_sub(camera.center, vec3_init(0, 0, camera.fl));
	vp_offset = vec3_scale(vec3_add(camera.vec3_x, camera.vec3_y), 0.5);
	camera.vp_00 = vec3_sub(camera.vp_center, vp_offset);
	pixel_offset = vec3_scale(vec3_add(camera.pixel_x, camera.pixel_y), 0.5);
	camera.pixel_00 = vec3_add(camera.vp_00, pixel_offset);
	return (camera);
}
