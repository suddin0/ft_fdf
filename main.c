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


void draw_font(t_char chr, t_image *img, int o_x, int o_y, unsigned int col)
{
	int x;
	int y;
	int k;

	x = o_x * 4;
	y = o_y;
	k = 0;

	// target = opacity * overlay + (1 - opacity) * background

	unsigned char A = COL_A(col);
	unsigned char R = COL_R(col);
	unsigned char G = COL_G(col);
	unsigned char B = COL_B(col);


	unsigned char BGA;
	unsigned char BGR;
	unsigned char BGG;
	unsigned char BGB;

	double opacity = (double) ((double) (A * 100) / 255) * 0.01;
	printf("font- [%c] X[%3d] Y[%3d]\n", chr.ascii, chr.x, chr.y);
	while (y < o_y + chr.y)
	{
		x = o_x * 4;
		while (x < (o_x + chr.x) * 4)
		{
			// printf("font- ** X[%d] Y[%d] ox * chr.x[%d]    - oy * chr.y[%d]\n", y, x, (o_x + chr.x) * 4, o_y + chr.y);

			if(x > 0 && y > 0 && (x + (y * img->x * 4)) < (img->x * img->y) * 4)
			{
				// If not transparent then show
				// if((chr.data)[k + 0] != 0 || (chr.data)[k + 1] != 0 || (chr.data)[k + 2] != 0 || (chr.data)[k + 3] != 0)s
				// if((chr.data)[k + 3] != 0)
				// {
					// (img->img)[x + 0 + (y * (img->x * 4))]  = (chr.data)[k + 0];
					// (img->img)[x + 1 + (y * (img->x * 4))]  = (chr.data)[k + 1];
					// (img->img)[x + 2 + (y * (img->x * 4))]  = (chr.data)[k + 2];
					// (img->img)[x + 3 + (y * (img->x * 4))]  = (chr.data)[k + 3];

					// (img->img)[x + 2 + (y * (img->x * 4))]  = (char) 210; // R
					// (img->img)[x + 1 + (y * (img->x * 4))]  = (char) 211; // G
					// (img->img)[x + 0 + (y * (img->x * 4))]  = (char) 212; // B
					// (img->img)[x + 3 + (y * (img->x * 4))]  = 255;  		  // A


					// (img->img)[x + 2 + (y * (img->x * 4))]  = col & 0xFF; 			// R
					// (img->img)[x + 1 + (y * (img->x * 4))]  = (col >> 8 ) & 0xFF;	// G
					// (img->img)[x + 0 + (y * (img->x * 4))]  = (col >> 16) & 0xFF;	// B
					// (img->img)[x + 3 + (y * (img->x * 4))]  = (col >> 24);			// A

					// (img->img)[x + 2 + (y * (img->x * 4))]  = (col >> 16); 		// R
					// (img->img)[x + 1 + (y * (img->x * 4))]  = (col >> 8) & 0xFF;	// G
					// (img->img)[x + 0 + (y * (img->x * 4))]  = (col) & 0xFF;		// B
					// (img->img)[x + 3 + (y * (img->x * 4))]  = (col & 0xFF);		// A

					// (img->img)[x + 2 + (y * (img->x * 4))]  = COL_R(col); 		// R
					// (img->img)[x + 1 + (y * (img->x * 4))]  = COL_G(col);// G
					// (img->img)[x + 0 + (y * (img->x * 4))]  = COL_B(col);	// B
					// // (img->img)[x + 3 + (y * (img->x * 4))]  = (col & 0xFF);			// A
					// (img->img)[x + 3 + (y * (img->x * 4))]  = (char)(255);			// A


					// (img->img)[x + 2 + (y * (img->x * 4))]  = R;	// R
					// (img->img)[x + 1 + (y * (img->x * 4))]  = G;	// G
					// (img->img)[x + 0 + (y * (img->x * 4))]  = B;	// B
					// // (img->img)[x + 3 + (y * (img->x * 4))]  = (col & 0xFF);			// A
					// (img->img)[x + 3 + (y * (img->x * 4))]  = A;			// A


					/* Working Bit is here */

					// BGA = (unsigned) ((img->img)[x + 3 + (y * (img->x * 4))]);
					// BGR = (unsigned) ((img->img)[x + 2 + (y * (img->x * 4))]);
					// BGG = (unsigned) ((img->img)[x + 1 + (y * (img->x * 4))]);
					// BGB = (unsigned) ((img->img)[x + 0 + (y * (img->x * 4))]);
					//
					// // opacity = (double) ((double) ((chr.data)[k + 3] * 100) / 255) * 0.01;
					//
					// // printf("BR[%3d] - BG[%3d] BB[%3d] | OP[%.3f] : R[%3d] - G[%3d] - B[%3d] | NR[%3d] RB[%3d] NG[%3d]\n",\
				 	// 		BGR, BGG, BGB,\
					// 		opacity, R  , G,   B,\
					// 		(opacity * R + (1 - opacity) * BGR),\
					// 		(opacity * G + (1 - opacity) * BGG),\
					// 		(opacity * A + (1 - opacity) * BGA));
					// printf("[G][%3hhu] - [B][%3hhu] - [R][%3hhu] - [A][%3hhu]\n", (chr.data)[k + 0], (chr.data)[k + 1], (chr.data)[k + 2], (chr.data)[k + 3]);
					//
					// // target = opacity * overlay + (1 - opacity) * background
					//
					//
					// (img->img)[x + 3 + (y * (img->x * 4))]  = (opacity * A + (1 - opacity) * BGA);	// A
					// (img->img)[x + 2 + (y * (img->x * 4))]  = (opacity * R + (1 - opacity) * BGR);	// R
					// (img->img)[x + 1 + (y * (img->x * 4))]  = (opacity * G + (1 - opacity) * BGG);	// G
					// (img->img)[x + 0 + (y * (img->x * 4))]  = (opacity * B + (1 - opacity) * BGB);	// B

					/* End here working bit */
				// }

				// if((chr.data)[k + 3] == 0)
				// {
					(img->img)[x + 0 + (y * (img->x * 4))]  = (chr.data)[k + 0];
					(img->img)[x + 1 + (y * (img->x * 4))]  = (chr.data)[k + 1];
					(img->img)[x + 2 + (y * (img->x * 4))]  = (chr.data)[k + 2];
					(img->img)[x + 3 + (y * (img->x * 4))]  = (chr.data)[k + 3];
					// (img->img)[x + 0 + (y * (img->x * 4))]  = 155; // B
					// (img->img)[x + 1 + (y * (img->x * 4))]  = 149; // G
					// (img->img)[x + 2 + (y * (img->x * 4))]  = 138; // R
					// (img->img)[x + 3 + (y * (img->x * 4))]  = (chr.data)[k + 3]; // A
					// (img->img)[x + 3 + (y * (img->x * 4))]  = 0; // A
					// printf("[K][%4d] - [B][%3d] [G][%3d] [R][%3d] [A][%3d]\n", k, (chr.data)[k + 0], (chr.data)[k + 1], (chr.data)[k + 2], (chr.data)[k + 3]);
				// }
			}
			k += 4;
			x += 4;
		}
		y++;
	}
	printf("---- END COLOR ----\n");
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

	printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[0].ascii, chr[0].ascii, chr[0].x, chr[0].y);
	printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[1].ascii, chr[1].ascii, chr[1].x, chr[1].y);
	printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[2].ascii, chr[2].ascii, chr[2].x, chr[2].y);
	printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[3].ascii, chr[3].ascii, chr[3].x, chr[3].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[4].ascii, chr[4].ascii, chr[4].x, chr[4].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[5].ascii, chr[5].ascii, chr[5].x, chr[5].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[6].ascii, chr[6].ascii, chr[6].x, chr[6].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[7].ascii, chr[7].ascii, chr[7].x, chr[7].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[8].ascii, chr[8].ascii, chr[8].x, chr[8].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[9].ascii, chr[9].ascii, chr[9].x, chr[9].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[10].ascii, chr[10].ascii, chr[10].x, chr[10].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[11].ascii, chr[11].ascii, chr[11].x, chr[11].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[12].ascii, chr[12].ascii, chr[12].x, chr[12].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[13].ascii, chr[13].ascii, chr[13].x, chr[13].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[14].ascii, chr[14].ascii, chr[14].x, chr[14].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[15].ascii, chr[15].ascii, chr[15].x, chr[15].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[16].ascii, chr[16].ascii, chr[16].x, chr[16].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[17].ascii, chr[17].ascii, chr[17].x, chr[17].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[18].ascii, chr[18].ascii, chr[18].x, chr[18].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[19].ascii, chr[19].ascii, chr[19].x, chr[19].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[20].ascii, chr[20].ascii, chr[20].x, chr[20].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[21].ascii, chr[21].ascii, chr[21].x, chr[21].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[22].ascii, chr[22].ascii, chr[22].x, chr[22].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[23].ascii, chr[23].ascii, chr[23].x, chr[23].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[24].ascii, chr[24].ascii, chr[24].x, chr[24].y);
	// printf("[FONT][%d][%c] - X[%9d]  - Y[%9d]\n", chr[25].ascii, chr[25].ascii, chr[25].x, chr[25].y);

	// void draw_font(t_char chr, t_image *img, int stat, int o_x, int o_y)
	draw_font(chr[27], &(root.menu), 10, 10, 0xE6E6FAFF);
	// draw_font(chr[3], &(root.menu), 10, 10, 0xE6E6FAFF);
	// draw_font(chr[4], &(root.menu), 10 + chr[19 ].x, 10, 0xE6E6FA80);
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
