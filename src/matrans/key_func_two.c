#include "main.h"


void k_minus(t_root *root)
{
	zoom(root->map, -5);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
}

void k_x(t_root *root)
{
	modmatrix(root->map, rotate_x, 0.10);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
}

void k_s(t_root *root)
{
	modmatrix(root->map, rotate_x, -0.10);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
}

void k_y(t_root *root)
{
	modmatrix(root->map, rotate_y, 0.10);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
	// root->map->origine_x -= 5;
}

void k_u(t_root *root)
{
	modmatrix(root->map, rotate_y, -0.10);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
}
