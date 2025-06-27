#include "rt1.h"

void	print_world(void *data)
{
	t_objs	*obj;
	
	obj = (t_objs *)data;
	if (obj && obj->print)
		obj->print(obj->data);
	printf("hit : %p, destory : %p\n", obj->hit, obj->destory);
}

t_list	*add_w_item(void *data, int (*hit)(), void (*destory)(void *), void (*print)(void *))
{
	t_objs	*obj;

	obj = (t_objs *)malloc(sizeof(t_objs));
	obj->data = data;
	obj->hit = hit;
	obj->destory = destory;
	obj->print = print;
	return (ft_lst_new(obj));
}