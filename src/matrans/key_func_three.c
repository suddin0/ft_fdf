#include "main.h"

int k_z(t_root *root)
{
	if(!(root->map))
		return (-1);
	modmatrix(root->map, rotate_z, 0.10);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
	return (0);
}

int k_a(t_root *root)
{
	if(!(root->map))
		return (-1);
	modmatrix(root->map, rotate_z, -0.10);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
	return (0);
}

int k_esc(t_root *root)
{
	// int i;
	//
	// i = 0;
	// mlx_destroy_image(root->mlx, root->prev.img_ptr);
	// mlx_destroy_window(root->mlx,root->win);
	// free_map(root->map);
	// while(i != root->men.list.total_map)
	// 	free(root->men.list.map_name[i++]);
	// free(root->men.list.map_name);
	// free(root->font_24);
	// free(root->font_18);
	// free(root->font_11);
	// printf("[!] Exiting the programme\n");
	free_root(root, EXIT_SUCCESS);
	// exit(EXIT_SUCCESS);
	return (0);
}
