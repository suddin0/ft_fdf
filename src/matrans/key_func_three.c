#include "main.h"

int k_z(t_root *root)
{
	modmatrix(root->map, rotate_z, 0.10);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
	return (0);
}

int k_a(t_root *root)
{
	modmatrix(root->map, rotate_z, -0.10);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
	return (0);
}

int k_esc(t_root *root)
{
	mlx_destroy_image(root->mlx, root->prev.img_ptr);
	mlx_destroy_window(root->mlx,root->win);
	free_map(root->map);
	printf("[!] Exiting the programme\n");
	exit(EXIT_SUCCESS);
	return (0);
}
