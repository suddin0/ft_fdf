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
		return (-1);
	root.map = map;

	modmatrix(map, rotate_x, 120);
	modmatrix(map, rotate_y, 120);
	draw_map(root.mlx, root.map);

	printf("HEY, INSIDE MAIN AGAIN map.file_size[%d] map.lines[%d]\n", map->file_sz, map->lines);

	/* ------ Using an xpm image ----- */
	int ppp = 0;
	void *nn = NULL;
	void *rr = NULL;

	char *dt; // data
	int dt_x = 0, dt_y = 0;
	int none;



	int h = 0;
	int w = 0;

	int fd;
	// t_char chr[FCHAR_MAX];
	t_font *font;

	root.font_24 = (t_font *) malloc(sizeof(t_font) * (FCHAR_MAX + 1));

	fd = open(FONT_STRUCT_PATH, O_RDONLY);
	if(fd < 0)
	{
		printf("[-] Error: opening %s\n", FONT_STRUCT_PATH);
		perror("Reason");
		exit(-1);
	}
	read(fd, root.font_24, sizeof(t_font) * FCHAR_MAX);
	if(read <= 0)
	{
		printf("[-] Error: read %s\n", FONT_STRUCT_PATH);
		exit(-1);
	}
	font = root.font_24;



	// draw_font(font['A' - 32], &(root.menu), 50, 20, 0x7289da2a);
	// draw_font(chr[28], &(root.menu), 10, 10, 0xE6E6FA00);
	// draw_font(chr[29], &(root.menu), 10 + chr[19 ].x, 10, 0x00FF00DD);
	// draw_font(chr[16], &(root.menu), 10 + chr[0 ].x, 10 + chr[0 ].y);



	// mlx_put_image_to_window (root->mlx,root.window, t_img *img, int x, int y);


	// put_text("Coucou", &root, 10, 70);
	// put_text("^_`abcdefghijklmnopqrstuvwxyz{|}~", &root, 10, 200);
	// put_text("Are Th-e~r-=e_ A@ny Lo,cal Host_.+ 1 + 1 10023 X = 10", &root, 10, 200);
	// put_text("!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~", &root, 10, 70);

	// t_map_list list;
	// init_list(MAP_PATH, &list);
    //
	// int i = 0;
	// printf("total maps [%d]\n", list.total_map);
	// while(i < list.total_map )
	// 	printf("map[%s]\n", list.map_name[i++]);
	// printf("Error  [%d]\n", list.error);
	// printf("Error Message [%s]\n", list.error_msg);

	// show_list(&list, &root);

	ft_printf("me [% 3zi] \n", 0);
	   printf("vr [% 3zi] \n", 0);

	// printf_text(&root, &(root.menu), "%C%x%yHello there [%s] [%d]%", 0x99aab5aa, 10, 90, "Lol", 334);

	// ft_printf("-------------------ROTATION_START---------------");
	// rotat(root.map, rot);
	// ft_printf("-------------------ROTATION_END-----------------");

	// draw_map(root.map, &(root.prev));







	mlx_put_image_to_window(root.mlx, root.win, root.menu.img_ptr, root.menu.o_x, root.menu.o_y);
	mlx_put_image_to_window(root.mlx, root.win, root.prev.img_ptr, root.prev.o_x, root.prev.o_y);
	mlx_put_image_to_window(root.mlx, root.win, root.foot.img_ptr, root.foot.o_x, root.foot.o_y);



	// mlx_put_image_to_window(root.mlx, root.win, rr, 0,0);

	event_func_init(&root);
	event_handler(&root);


	// mlx_key_hook (root.win , exit_esc, &root);
	mlx_loop_hook(root.mlx, NULL, NULL);
	mlx_loop(root.mlx);
	return (0);
}
