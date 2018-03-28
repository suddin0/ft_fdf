#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# include <unistd.h>		// For read


int main(int argc, char **argv)
{
	t_root root;

	if(pre_check(argc, argv) == 0)
		return (0);
	root_init(&root, argv);
	init_menu(&root, &(root.menu));
	init_prev(&root, &(root.prev));
	init_foot(&root, &(root.foot));
	if(!(root.map = get_map(argv[1], &(root.prev))))
	{
		printf("[!] Get map sent NULL.\n");
		free_root(&root, -1);
	}
	modmatrix(root.map, rotate_x, 120);
	modmatrix(root.map, rotate_y, 120);
	draw_map(&root, root.mlx, root.map);
	mlx_put_image_to_window(root.mlx, root.win, root.menu.img_ptr, root.menu.o_x, root.menu.o_y);
	mlx_put_image_to_window(root.mlx, root.win, root.prev.img_ptr, root.prev.o_x, root.prev.o_y);
	mlx_put_image_to_window(root.mlx, root.win, root.foot.img_ptr, root.foot.o_x, root.foot.o_y);
	event_func_init(&root);
	event_handler(&root);
	mlx_loop(root.mlx);
	return (0);
}
