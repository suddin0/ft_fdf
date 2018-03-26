#include "main.h"


int k_minus(t_root *root)
{
	if(!(root->map))
		return (-1);
	zoom(root->map, -2);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
	return (0);
}

int k_x(t_root *root)
{
	if(!(root->map))
		return (-1);
	modmatrix(root->map, rotate_x, 0.10);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
	return (0);
}

int k_s(t_root *root)
{
	if(!(root->map))
		return (-1);
	modmatrix(root->map, rotate_x, -0.10);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
	return (0);
}

int k_y(t_root *root)
{
	if(!(root->map))
		return (-1);
	modmatrix(root->map, rotate_y, 0.10);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
	return (0);
	// root->map->origine_x -= 5;
}

int k_u(t_root *root)
{
	if(!(root->map))
		return (-1);
	modmatrix(root->map, rotate_y, -0.10);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
	return (0);
}
