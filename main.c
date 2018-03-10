#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# include <unistd.h>		// For read



//void  draw_line_img_iso(t_root *r, int Xo, int Yo, int  Xn, int Yn, t_color color)
void  draw_line_iso(t_image *img, double Xo, double Yo, double  Xn, double Yn, int color)
{
	int	steps;
	double	x;
	double	y;
	double Xincrement;
	double	Yincrement;

	steps = (fabs(Xn - Xo) > fabs(Yn - Yo)) ? fabs(Xn - Xo) : fabs(Yn - Yo);

	x = Xo;
	y = Yo;
	Xincrement = (Xn - Xo) / (float) steps; // X or Y increment by this ration
	Yincrement = (Yn - Yo) / (float) steps;

	for(int v = 0; v < steps; v++)
	{
		x += Xincrement;
		y += Yincrement;
		put_color(img, (x - y) , ((y + x) / 2), color); // Iso view
		//put_color(r, x, y, color); // Normal view
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



	printf("******** END OF PERSING *********\n");
	//print_map(map, 3);

	init_menu(&root, &(root.menu));
	init_prev(&root, &(root.prev));
	init_foot(&root, &(root.foot));

	if(!(map = get_map(argv[1], &(root.prev))))
		return (-1);
	root.map = map;

	// modmatrix(map, rotate_x, 120);
	// modmatrix(map, rotate_y, 120);
	draw_map(root.mlx, root.map);

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

	// fd = open(BUTTON_STRUCT_PATH, O_RDONLY);
	// read(fd, root.men.button, sizeof(t_button) * BUTTON_MAX);


	// nn = mlx_new_image(root.mlx, root.sz_x, root.sz_y);
	// rr = mlx_xpm_file_to_image(root.mlx , "res/__IMG__/dove.xpm", &w, &w);
	// rr = mlx_xpm_file_to_image(root.mlx , "res/__buttons__/xpm/arrow_0.xpm", &dt_x, &dt_y);
	// dt = mlx_get_data_addr(rr, &(none), &(none), &(none));



	// ft_printf("dx[%d] - dy[%d] __  bx[%d]  by[%d]", dt_x, dt_y, root.men.button[0].x , root.men.button[0].y);
	// ft_memcpy(dt, root.men.button[0].view[2], (root.men.button[0].x * root.men.button[0].y) * sizeof(int));


	// show_image(dt, dt_x, dt_y);

	// mlx_put_image_to_window(root.mlx, root.win, rr, 0,0);
    //
	// rr = mlx_xpm_file_to_image(root.mlx , "res/FONTS/HH2.xpm", &w, &w);



	t_image t_0;
	t_image t_1;
	t_image t_2;
	t_image t_3;
	t_image t_4;

	t_0.o_x = 20;
	t_1.o_x = 20;
	t_2.o_x = 20;
	t_3.o_x = 20;
	t_4.o_x = 20;

	t_0.o_y = 20;
	t_1.o_y = 20;
	t_2.o_y = 20;
	t_3.o_y = 20;
	t_4.o_y = 20;

// /home/samad/Bureau/__42__/fdf/res/__IMG__/trans_test/xpm/trans_test_0.xpm
// /home/samad/Bureau/__42__/fdf/res/__IMG__/trans_test/xpm/trans_test_4_FULL_TRANS_.xpm

// test
	// t_0.img_ptr = mlx_xpm_file_to_image(root.mlx, "res/__IMG__/trans_test/xpm/trans_test_0.xpm", &(t_0.x), &(t_0.y));
	// t_1.img_ptr = mlx_xpm_file_to_image(root.mlx, "res/__IMG__/trans_test/xpm/trans_test_1.xpm", &(t_1.x), &(t_1.y));
	// t_2.img_ptr = mlx_xpm_file_to_image(root.mlx, "res/__IMG__/trans_test/xpm/trans_test_2.xpm", &(t_2.x), &(t_2.y));
	// t_3.img_ptr = mlx_xpm_file_to_image(root.mlx, "res/__IMG__/trans_test/xpm/trans_test_3.xpm", &(t_3.x), &(t_3.y));
	// t_4.img_ptr = mlx_xpm_file_to_image(root.mlx, "res/__IMG__/trans_test/xpm/trans_test_4.xpm", &(t_4.x), &(t_4.y));
    //
	// mlx_put_image_to_window(root.mlx, root.win, t_0.img_ptr, 100, 100);
	// mlx_put_image_to_window(root.mlx, root.win, t_1.img_ptr, 100, 300);
	// mlx_put_image_to_window(root.mlx, root.win, t_2.img_ptr, 100, 500);
	// mlx_put_image_to_window(root.mlx, root.win, t_3.img_ptr, 100, 700);
	// mlx_put_image_to_window(root.mlx, root.win, t_4.img_ptr, 200, 700);
    //
	// t_0.img = mlx_get_data_addr(t_0.img_ptr, &(t_0.bpp), &(t_0.sl), &(t_0.end));
	// t_1.img = mlx_get_data_addr(t_1.img_ptr, &(t_1.bpp), &(t_1.sl), &(t_1.end));
	// t_2.img = mlx_get_data_addr(t_2.img_ptr, &(t_2.bpp), &(t_2.sl), &(t_2.end));
	// t_3.img = mlx_get_data_addr(t_3.img_ptr, &(t_3.bpp), &(t_3.sl), &(t_3.end));
	// t_4.img = mlx_get_data_addr(t_4.img_ptr, &(t_4.bpp), &(t_4.sl), &(t_4.end));
    //
	// int t0 = open("res/__IMG__/trans_test/xpm/trans_test_0.char", O_WRONLY | O_APPEND | O_CREAT, 0644);
	// int t1 = open("res/__IMG__/trans_test/xpm/trans_test_1.char", O_WRONLY | O_APPEND | O_CREAT, 0644);
	// int t2 = open("res/__IMG__/trans_test/xpm/trans_test_2.char", O_WRONLY | O_APPEND | O_CREAT, 0644);
	// int t3 = open("res/__IMG__/trans_test/xpm/trans_test_3.char", O_WRONLY | O_APPEND | O_CREAT, 0644);
	// int t4 = open("res/__IMG__/trans_test/xpm/trans_test_4.char", O_WRONLY | O_APPEND | O_CREAT, 0644);
    //
	// write(t0, t_0.img, sizeof(char) * (t_0.x * t_0.y));
	// write(t1, t_1.img, sizeof(char) * (t_1.x * t_1.y));
	// write(t2, t_2.img, sizeof(char) * (t_2.x * t_2.y));
	// write(t3, t_3.img, sizeof(char) * (t_3.x * t_3.y));
	// write(t4, t_4.img, sizeof(char) * (t_4.x * t_4.y));
    //
	// close(t0);
	// close(t1);
	// close(t2);
	// close(t3);
	// close(t4);


	/* ---------- End xpm image view -------- */


	// // mlx_put_image_to_window(root.mlx, root.win, root.menu.img_ptr, root.menu.o_x, root.menu.o_y);
	// mlx_put_image_to_window(root.mlx, root.win, rr, 0,0);
	// // mlx_put_image_to_window(root.mlx, root.win, root.prev.img_ptr, root.prev.o_x, root.prev.o_y);
    //
	double rot = 3.0;
    //
	// while(rot != 0.8)
	// {
	// 	rotat(root.map, rot);
	// 	set_color(root.prev.img, root.prev.x * root.prev.y, get_col(241, 232, 202, 255));
	// 	draw_map(root.map, &(root.prev));
	// 	mlx_put_image_to_window(root.mlx, root.win, root.prev.img_ptr, root.prev.o_x, root.prev.o_y);
	// 	usleep(900000);
	// 	rot += 0.2;
    //
	// }




	// ft_printf("-------------------ROTATION_START---------------");
	// rotat(root.map, rot);
	// ft_printf("-------------------ROTATION_END-----------------");

	// draw_map(root.map, &(root.prev));





	// mlx_put_image_to_window(root.mlx, root.win, root.menu.img_ptr, root.menu.o_x, root.menu.o_y);
	// mlx_put_image_to_window(root.mlx, root.win, root.prev.img_ptr, root.prev.o_x, root.prev.o_y);
	// mlx_put_image_to_window(root.mlx, root.win, root.foot.img_ptr, root.foot.o_x, root.foot.o_y);



	// mlx_put_image_to_window(root.mlx, root.win, rr, 0,0);
	event_handler(&root);


	// mlx_key_hook (root.win , exit_esc, &root);
	mlx_loop(root.mlx);
	return (0);
}
