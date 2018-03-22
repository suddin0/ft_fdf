#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# include <unistd.h>		// For read



//
// void draw_font(t_char chr, t_image *img, int o_x, int o_y, unsigned int col)
// {
// 	int x;
// 	int y;
// 	int k;
//
// 	if (chr.x == 0 || chr.y == 0)
// 		return;
// 	x = o_x * 4;
// 	y = o_y;
// 	k = 0;
//
// 	// target = opacity * overlay + (1 - opacity) * background
//
// 	unsigned char A = COL_A(col);
// 	unsigned char R = COL_R(col);
// 	unsigned char G = COL_G(col);
// 	unsigned char B = COL_B(col);
//
//
// 	unsigned char BGA;
// 	unsigned char BGR;
// 	unsigned char BGG;
// 	unsigned char BGB;
//
// 	// double opacity = (double) ((double) (A * 100) / 255) * 0.01;
// 	double opacity;
// 	double o_opacity_r; // original opacity
//
//
// 	opacity = (double) ((double) (A * 100) / 255) * 0.01;
// 	printf("font- [%c] X[%3d] Y[%3d]\n", chr.ascii, chr.x, chr.y);
// 	while (y < o_y + chr.y)
// 	{
// 		x = o_x * 4;
// 		while (x < (o_x + chr.x) * 4)
// 		{
// 			// if(x > 0 && y > 0 && (x + (y * img->x * 4)) < (img->x * img->y) * 4)
// 			if((x > 0 && y > 0) && (x + (y * img->x)) < (img->x * img->y) && (x < (img->x * 4) &&  y * img->y))
// 			{
// 				if((unsigned char) (chr.data)[k + 0] != 2 || (unsigned char) (chr.data)[k + 1] != 2 || (unsigned char) (chr.data)[k + 2] != 2)
// 				{
// 					o_opacity_r =   (double) (((unsigned char) (chr.data)[k + 2] * 100) / 255); // original opacity
//
// 					o_opacity_r = o_opacity_r * 0.01; // original opacity
//
// 					o_opacity_r = opacity - o_opacity_r;
// 					o_opacity_r = (o_opacity_r > 0 && o_opacity_r < opacity) ? o_opacity_r : 0;
//
// 					BGA = (unsigned char) ((img->img)[x + 3 + (y * (img->x * 4))]);
// 					BGR = (unsigned char) ((img->img)[x + 2 + (y * (img->x * 4))]);
// 					BGG = (unsigned char) ((img->img)[x + 1 + (y * (img->x * 4))]);
// 					BGB = (unsigned char) ((img->img)[x + 0 + (y * (img->x * 4))]);
//
// 					// (img->img)[x + 3 + (y * (img->x * 4))]  = ((opacity - o_opacity_r) * A + (1 - (opacity - o_opacity_r)) * BGA);	// A
// 					(img->img)[x + 2 + (y * (img->x * 4))]  = ((opacity - o_opacity_r) * R + (1 - (opacity - o_opacity_r)) * BGR);	// R
// 					(img->img)[x + 1 + (y * (img->x * 4))]  = ((opacity - o_opacity_r) * G + (1 - (opacity - o_opacity_r)) * BGG);	// G
// 					(img->img)[x + 0 + (y * (img->x * 4))]  = ((opacity - o_opacity_r) * B + (1 - (opacity - o_opacity_r)) * BGB);	// B
//
// 					// /* Real Colors */
// 					// (img->img)[x + 3 + (y * (img->x * 4))]  = (chr.data)[k + 3];	// R
// 					// (img->img)[x + 2 + (y * (img->x * 4))]  = (chr.data)[k + 2];	// R
// 					// (img->img)[x + 1 + (y * (img->x * 4))]  = (chr.data)[k + 1];	// G
// 					// (img->img)[x + 0 + (y * (img->x * 4))]  = (chr.data)[k + 0];	// B
// 				} /* End of if all white if */
// 			}
// 			k += 4;
// 			x += 4;
// 		}
// 		y++;
// 	}
// }
//
// void put_text(char *str, t_root *root, int o_x, int o_y)
// {
// 	int i;
// 	int o_width; // origine to width;
// 	t_font *font;
//
//
// 	i = 0;
// 	o_width = 0;
// 	font = root->font_24;
//
// 	while (str[i])
// 	{
// 		printf("came there [%d]\n", str[i] - 32);
// 		// void draw_font(t_char chr, t_image *img, int o_x, int o_y, unsigned int col)
// 		// draw_font(font[str[i] - 33], &(root->prev), o_x + o_width, o_y, 0xffffffff);
// 		draw_font(font[str[i] - 32], &(root->menu), o_x + o_width + font[str[i] - 32].pad_left,  o_y + font[str[i] - 32].pad_top, 0x99aab5ff);
// 		o_width += font[str[i] - 32].x + font[str[i] - 32].pad_right;
// 		i++;
// 	}
// }

 /* init list*/

//
// int dir_file_count_list(char *map_dir)
// {
// 	DIR *dir;
// 	struct dirent *ep;
// 	int file;
// 	char *tmp_file;
//
// 	dir = opendir(map_dir);
// 	file = 0;
// 	if (dir != NULL)
//   	{
// 		while ((ep = readdir(dir)))
// 		{
// 			tmp_file = (char *) malloc(sizeof(char) * ((ft_strlen(map_dir) + ft_strlen(ep->d_name) + 5)));
// 			ft_strcpy(tmp_file, map_dir);
// 			ft_strcat(tmp_file, "/");
// 			ft_strcat(tmp_file, ep->d_name);
//
// 			// printf("CAME IN WHILE FILE [%s] is_file[%d]\n", ep->d_name, is_file(ep->d_name));
// 			if(is_file(tmp_file) == 1)
// 			{
// 				// printf("CAME IN WHILE FILE [%s]\n", ep->d_name);
//
// 				if(is_dot_fdf(ep->d_name))
// 					file++;
// 			}
// 			free(tmp_file);
// 		}
// 		closedir(dir);
//   	}
// 	else
// 		return (-1);
// 	return (file);
// }
//
// void init_list(char *map_dir, t_map_list *list)
// {
// 	DIR *dir;
// 	struct dirent *ep;
// 	int file;
// 	int i;
// 	char *tmp_file;
//
//
// 	list->total_map = 0;
// 	list->error = 0; // no rror
// 	list->o_x = 0;
// 	list->o_y = 60;
// 	list->x = MENU_X;
// 	list->y = MENU_Y + list->o_y;
// 	i = 0;
// 	if((list->total_map = dir_file_count_list(map_dir)) == 0)
// 	{
// 		list->error = 1;
//   		ft_strcpy(list->error_msg, "[-] Error: directory ");
//   		ft_strcat(list->error_msg, map_dir);
//   		ft_strcat(list->error_msg, " might be empty (read 0 files)");
// 	}
//
// 	printf("DIR_NAME[%s]\n", map_dir);
//
// 	dir = opendir(map_dir);
// 	if (dir != NULL || list->total_map == -1)
//   	{
// 		list->map_name = (char **) malloc(sizeof(char *) * list->total_map); // MUST BE FREED
// 		while ((ep = readdir(dir)))
// 		{
// 			tmp_file = (char *) malloc(sizeof(char) * ((ft_strlen(map_dir) + ft_strlen(ep->d_name) + 5)));
// 			ft_strcpy(tmp_file, map_dir);
// 			ft_strcat(tmp_file, "/");
// 			ft_strcat(tmp_file, ep->d_name);
// 			if(is_file(tmp_file))
// 				if(is_dot_fdf(ep->d_name))
// 					list->map_name[i++] = ft_strdup(tmp_file);  // MUST BE FREED
// 			free(tmp_file);
// 		}
// 		closedir(dir);
//   	}
// 	else
// 	{
// 		list->error = 1;
//   		ft_strcpy(list->error_msg, "[-] Error: directory ");
//   		ft_strcat(list->error_msg, map_dir);
//   		ft_strcat(list->error_msg, " could not been open");
// 	}
// }
//
// // void put_text(char *str, t_root *root, int o_x, int o_y)
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
// 		put_text(&(list->map_name[i][strlen(MAP_PATH) + 1]), root, curr_x + 10, curr_y + 10);
// 		curr_y += 40;
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

	t_map_list list;
	// init_list(MAP_PATH, &list);

	int i = 0;
	printf("total maps [%d]\n", list.total_map);
	while(i < list.total_map )
		printf("total map[%s]\n", list.map_name[i++]);
	printf("Error  [%d]\n", list.error);
	printf("Error Message [%s]\n", list.error_msg);

	// show_list(&list, &root);

	// printf("%s\n", );

	printf_text(&root, &(root.menu), "%C%x%yHello there [%s] [%d]%", 0x99aab5aa, 10, 90, "Lol", 334);

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
