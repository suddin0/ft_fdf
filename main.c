#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# include <unistd.h>		// For read



// void put_text(char *str, t_root *root, int o_x, int o_y)
// void show_list(t_map_list *list, t_root *root)
// {
// 	int i;
// 	int curr_x; // current x
// 	int curr_y; // current y
//
// 	i = 0;
// 	curr_x = list->o_x;
// 	curr_y = list->o_y;
// 	while(i < list->total_map)
// 	{
// 		printf_text(root, &(root->menu),"%x%y%s", curr_x + 10, curr_y, &(list->map_name[i][strlen(MAP_PATH) + 1]));
// 		curr_y += 70;
// 		i++;
// 	}
// }

int main(int argc, char **argv)
{
	t_root root;
	t_map *map;

	map = NULL;
	if(pre_check(argc, argv) == 0)
		return (0);
	root_init(&root, argv);



	printf("******** END OF PARSING *********\n");
	//print_map(map, 3);

	init_menu(&root, &(root.menu));
	init_prev(&root, &(root.prev));
	init_foot(&root, &(root.foot));

	if(!(map = get_map(argv[1], &(root.prev))))
	{
		printf("[!] Get map sent NULL.\n");
		free_root(&root, -1);
	}
	root.map = map;

	modmatrix(map, rotate_x, 120);
	modmatrix(map, rotate_y, 120);
	draw_map(&root, root.mlx, root.map);

	printf("HEY, INSIDE MAIN AGAIN map.file_size[%d] map.lines[%d]\n", map->file_sz, map->lines);

	/* ------ Using an xpm image ----- */

	printf_text(&root, &(root.prev), "%f%x%y !\"#$%&'()*+~/E<-,F=-L.,_x./0:;<=>?@-37 CDE[\\]^_`mnopqrstuvwxyz{|}~", root.font_24, 20, 20);
	printf_text(&root, &(root.prev), "%f%x%y !\"#$%&'()*+~/E<-,F=-L.,_x./0:;<=>?@-37 CDE[\\]^_`mnopqrstuvwxyz{|}~", root.font_18, 20, 60);
	printf_text(&root, &(root.prev), "%f%x%y !\"#$%&'()*+~/E<-,F=-L.,_x./0:;<=>?@-37 CDE[\\]^_`mnopqrstuvwxyz{|}~", root.font_11, 20, 100);
	// printf_text(&root, &(root.prev), "%C%f%x%y [-] Error: directory mp might be empty (read 0 files)", COL_ERROR, root.font_11, 20, 140);
	printf_text(&root, &(root.prev), "%C%f%x%y%s", COL_ERROR, root.font_18, 10, 140 + 10 , "[-] Error: directory mp might be empty (read 0 files)");

	mlx_put_image_to_window(root.mlx, root.win, root.menu.img_ptr, root.menu.o_x, root.menu.o_y);
	mlx_put_image_to_window(root.mlx, root.win, root.prev.img_ptr, root.prev.o_x, root.prev.o_y);
	mlx_put_image_to_window(root.mlx, root.win, root.foot.img_ptr, root.foot.o_x, root.foot.o_y);



	// mlx_put_image_to_window(root.mlx, root.win, rr, 0,0);

	event_func_init(&root);
	event_handler(&root);


	// mlx_key_hook (root.win , exit_esc, &root);
	mlx_loop(root.mlx);
	return (0);
}
