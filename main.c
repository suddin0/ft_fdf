#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# include <unistd.h>		// For read


//
// //void  draw_line_img_iso(t_root *r, int Xo, int Yo, int  Xn, int Yn, t_color color)
// void  draw_line_iso(t_image *img, double Xo, double Yo, double  Xn, double Yn, int color)
// {
// 	int	steps;
// 	double	x;
// 	double	y;
// 	double Xincrement;
// 	double	Yincrement;
//
// 	steps = (fabs(Xn - Xo) > fabs(Yn - Yo)) ? fabs(Xn - Xo) : fabs(Yn - Yo);
//
// 	x = Xo;
// 	y = Yo;
// 	Xincrement = (Xn - Xo) / (float) steps; // X or Y increment by this ration
// 	Yincrement = (Yn - Yo) / (float) steps;
//
// 	for(int v = 0; v < steps; v++)
// 	{
// 		x += Xincrement;
// 		y += Yincrement;
// 		put_color(img, (x - y) , ((y + x) / 2), color); // Iso view
// 		//put_color(r, x, y, color); // Normal view
// 	}
// }
//


void draw_font(t_char chr, t_image *img, int o_x, int o_y)
{
	int x;
	int y;
	int k;

	x = o_x * 4;
	y = o_y;
	k = 0;
	printf("font_Button- [%3d] X[%3d] Y[%3d]\n", chr.ascii, chr.x, chr.y);
	while (y < o_y + chr.y)
	{
		x = o_x * 4;
		while (x < (o_x + chr.x) * 4)
		{
			if(x > 0 && y > 0 && (x + (y * img->x * 4)) < (img->x * img->y) * 4)
			{
				// If not transparent then show
				// if((chr.data)[k + 0] != 0 || (chr.data)[k + 1] != 0 || (chr.data)[k + 2] != 0 || (chr.data)[k + 3] != 0)
				// {
				// 	// (img->img)[x + 0 + (y * (img->x * 4))]  = (chr.data)[k + 0];
				// 	// (img->img)[x + 1 + (y * (img->x * 4))]  = (chr.data)[k + 1];
				// 	// (img->img)[x + 2 + (y * (img->x * 4))]  = (chr.data)[k + 2];
				// 	// (img->img)[x + 3 + (y * (img->x * 4))]  = (chr.data)[k + 3];
				// 	(img->img)[x + 0 + (y * (img->x * 4))]  = (char) 128;
				// 	(img->img)[x + 1 + (y * (img->x * 4))]  = (char) 112;
				// 	(img->img)[x + 2 + (y * (img->x * 4))]  = (char) 255;
				// 	(img->img)[x + 3 + (y * (img->x * 4))]  = 50;
				// }
				// if((chr.data)[k + 3] == 0)
				// {
					// (img->img)[x + 0 + (y * (img->x * 4))]  = (chr.data)[k + 0];
					// (img->img)[x + 1 + (y * (img->x * 4))]  = (chr.data)[k + 1];
					// (img->img)[x + 2 + (y * (img->x * 4))]  = (chr.data)[k + 2];
					// (img->img)[x + 3 + (y * (img->x * 4))]  = (chr.data)[k + 3];
					(img->img)[x + 0 + (y * (img->x * 4))]  = 155; // B
					(img->img)[x + 1 + (y * (img->x * 4))]  = 149; // G
					(img->img)[x + 2 + (y * (img->x * 4))]  = 138; // R
					// (img->img)[x + 3 + (y * (img->x * 4))]  = (chr.data)[k + 3]; // A
					(img->img)[x + 3 + (y * (img->x * 4))]  = (chr.data)[k + 3]; // A
					printf("[K][%4d] - [B][%3d] [G][%3d] [R][%3d] [A][%3d]\n", k, (chr.data)[k + 0], (chr.data)[k + 1], (chr.data)[k + 2], (chr.data)[k + 3]);
				// }
			}
			k += 4;
			x += 4;
		}
		y++;
	}
}

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
	t_char chr[FCHAR_MAX];

	fd = open(FONT_STRUCT_PATH, O_RDONLY);
	if(fd < 0)
	{
		printf("[-] Error: opening %s\n", FONT_STRUCT_PATH);
		perror("Reason");
		exit(-1);
	}
	read(fd, chr, sizeof(t_char) * FCHAR_MAX);
	if(read <= 0)
	{
		printf("[-] Error: read %s\n", FONT_STRUCT_PATH);
		exit(-1);
	}

	// void draw_font(t_char chr, t_image *img, int stat, int o_x, int o_y)
	draw_font(chr[0 ], &(root.menu), 10, 10);
	// draw_font(chr[19], &(root.menu), 10, 10 + chr[0 ].y);
	// draw_font(chr[25], &(root.menu), 10 + chr[0 ].x, 10);
	// draw_font(chr[16], &(root.menu), 10 + chr[0 ].x, 10 + chr[0 ].y);

	// mlx_put_image_to_window( root->mlx,root.window, t_img *img, int x, int y);



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
	mlx_loop(root.mlx);
	return (0);
}
