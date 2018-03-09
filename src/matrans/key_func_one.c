#include "main.h"

void k_up(t_root *root)
{
	trans_y(root->map, -10.0);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
}

void k_down(t_root *root)
{
	trans_y(root->map, 10.0);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
}

void k_right(t_root *root)
{
	trans_x(root->map, 10.0);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
}

void k_left(t_root *root)
{
	trans_x(root->map, -10.0);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
}

void k_plus(t_root *root)
{
	zoom(root->map, 5);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
}

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
}

void k_u(t_root *root)
{
	modmatrix(root->map, rotate_y, -0.10);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
}

void k_z(t_root *root)
{
	modmatrix(root->map, rotate_z, 0.10);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
}

void k_a(t_root *root)
{
	modmatrix(root->map, rotate_z, -0.10);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
}
