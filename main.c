#include "main.h"
#include <stdio.h>
#include <stdlib.h>


int	exit_esc(int key, t_root *root)
{
	//root->key_pressed = key;

	if(key == BTN_ESC || key == BTN_Q)
	{
		mlx_destroy_image(root->mlx,root->img_ptr);
		mlx_destroy_window(root->mlx,root->win);
		free_map(root->map);
		printf("Key pressed %d\n", key);
		printf("[!] Exiting the programme\n");
		exit(EXIT_SUCCESS);
	}
	else
		printf("Key pressed %d\n", key);
	return (0);
}



t_color	  get_color(int r, int g, int b, int a)
{
	t_color	col;

	col.b = b;
	col.g = g;
	col.r = r;
	col.a = a;
	return (col);
}

void set_color(char *img, int len, t_color col)
{
	int i;

	i = 0;
	while (i != len)
		((t_color *) img)[i++] = col;
}
int main(int argc, char **argv)
{
	t_root root;
	t_map *map;

	map = NULL;
	if(pre_check(argc, argv) == 0)
		return (0);
	root_init(&root, argv);

	if(!(map = get_map(argv[1])))
		return (-1);
	root.map = map;
	printf("******** END OF PERSING *********\n");
	print_map(map, 3);
	void *img_ptr = NULL;
	char *img	  = NULL;
	int i = 0;
	img_ptr = mlx_new_image(root.mlx, root.sz_x, root.sz_y);
	img		= mlx_get_data_addr(img_ptr, &i, &i, &i);
	root.img_ptr = img_ptr;
	set_color(img, root.sz_x * root.sz_y, get_color(44, 47, 51, 0));
	mlx_put_image_to_window(root.mlx, root.win, img_ptr, 0, 0);
	mlx_key_hook (root.win , exit_esc, &root);
	mlx_loop(root.mlx);
	return (0);
}






