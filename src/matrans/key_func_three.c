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
	int i;

	i = 0;
	mlx_destroy_image(root->mlx, root->prev.img_ptr);
	mlx_destroy_window(root->mlx,root->win);
	free_map(root->map);
	while(i != root->men.list.total_map)
		free(root->men.list.map_name[i++]);
	free(root->men.list.map_name);
	printf("[!] Exiting the programme\n");
	exit(EXIT_SUCCESS);
	return (0);
}
