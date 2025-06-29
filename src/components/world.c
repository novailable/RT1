#include "rt1.h"

void	print_world(void *data)
{
	t_objs	*obj;
	
	obj = (t_objs *)data;
	printf("obj : ");
	obj->print(obj->data);
	printf("\thit : %p, destory : %p\n", obj->hit, obj->destory);
}
void	add_w_item(t_list **world, void *data, int (*hit)(), void (*destory)(void *), void (*print)(void *))
{
	t_objs	*obj;

	obj = malloc(sizeof(t_objs));
	ft_bzero(obj, sizeof(t_objs));
	obj->data = data;
	obj->hit = hit;
	obj->destory = destory;
	obj->print = print;
	ft_lstadd_back(world, ft_lstnew(obj));
}

void	world_hit(void *data, void *param)
{
	t_objs	*obj;
	t_ray	*ray;
	t_hit	temp_hit;

	obj = (t_objs *)data;
	ray = (t_ray *)param;

	if (obj->hit && obj->hit(obj->data, *ray, &temp_hit))
	{
		if (!ray->hit_anything || temp_hit.t < ray->hit.t)
		{
			ray->hit = temp_hit;
			ray->t_max = temp_hit.t;
			ray->hit_anything = 1;
		}
	}
}


