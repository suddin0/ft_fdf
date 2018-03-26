#include "main.h"

void free_root(t_root *root, int exit_code)
{
	int i;

	i = 0;
	mlx_destroy_image(root->mlx, root->prev.img_ptr);
	mlx_destroy_image(root->mlx, root->menu.img_ptr);
	mlx_destroy_image(root->mlx, root->foot.img_ptr);
	mlx_destroy_window(root->mlx,root->win);
	free_map(root->map);
	while(i != root->men.list.total_map)
		free(root->men.list.map_name[i++]);
	free(root->men.list.map_name);
	free(root->font_24);
	free(root->font_18);
	free(root->font_11);
	exit(EXIT_SUCCESS);
	ft_printf("[!] Root has been freed\n");
}
