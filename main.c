#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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

// void  draw_line(t_image *img, double Xo, double Yo, double  Xn, double Yn, t_color color)
// //void  draw_line(t_image *img, double Xo, double Yo, double Zo, double  Xn, double Yn, double Zn, t_color color)
// {
// 	unsigned steps;
// 	double	x;
// 	double	y;
// 	double Xincrement;
// 	double Yincrement;
//
// 	steps = ((Xn - Xo) > (Yn - Yo)) ? fabs(Xn - Xo) : fabs(Yn - Yo);
// 	//steps = (fabs((Xn/Zn) - (Xo/ Zo)) > fabs((Yn/Zn) - (Yo/Zo))) ? fabs((Xn/Zn) - (Xo/Zo)) : fabs((Yn/Zn) - (Yo/Zo));
//
// 	x = Xo;
// 	y = Yo;
//
// 	//x = Xo / Zo;
// 	//y = Yo / Zo;
//
// 	Xincrement = (Xn - Xo) / (double) steps; // X or Y increment by this ration
// 	Yincrement = (Yn - Yo) / (double) steps;
//
// 	//Xincrement = ((Xn/Zn) - (Xo/Zo)) / (float) steps; // X or Y increment by this ration
// 	//Yincrement = ((Yn/Zn) - (Yo/Zo)) / (float) steps;
//
// 	printf("DRAW-LiNE                   Xo[%6.6lf]    Yo[%6.6lf]\n", Xo, Yo);
// 	printf("DRAW-LiNE                   Xn[%6.6lf]    Yn[%6.6lf]\n", Xn, Yn);
// 	printf("CAME HERE int DRAW-LiNE  X-INC[%6.6lf] Y-INC[%6.6lf]\n", Xincrement, Yincrement);
//  ft_printf("----------------------------------------------------\n");
// 	while(steps)
// 	{
// 		x += Xincrement;
// 		y += Yincrement;
// 		//put_color(img, fabs(x), fabs(y), color); // Normal view
// 		put_color(img, x, y, color); // Normal view
// 		steps--;
// 	}
// }

// void rotat_x(t_point *a, double deg)
// {
// 	double x;
// 	double y;
// 	double z;
//
// 	x = a->x;
// 	y = a->y;
// 	z = a->z;
// 	printf("++ ROTAT_X BEFOR X[%lf] Y[%lf] Z[%lf]\n", x, y, z);
//
//
// 	a->x = (x * 1)  + (y *         0) + (z *         0);
// 	a->y = (x * 0)  + (y *  cos(deg)) + (z * -sin(deg));
// 	a->z = (x * 0)  + (y *  sin(deg)) + (z *  cos(deg));
// 	printf("-- ROTAT_X AFTER X[%lf] Y[%lf] Z[%lf]\n", a->x, a->y, a->z);
//
// }

// void rotat_z(t_point *a, double deg)
// {
// 	double x;
// 	double y;
// 	double z;
//
// 	x = a->x;
// 	y = a->y;
// 	z = a->z;
// 	printf("++ ROTAT_X BEFOR X[%lf] Y[%lf] Z[%lf]\n", x, y, z);
//
//
// 	a->x = (x * cos(deg))  + (y * -sin(deg)) + (z * 0);
// 	a->y = (x * sin(deg))  + (y *  cos(deg)) + (z * 0);
// 	a->z = (x *        0)  + (y *         0) + (z * 1);
// 	printf("-- ROTAT_X AFTER X[%lf] Y[%lf] Z[%lf]\n", a->x, a->y, a->z);
// }

void uzoom(t_point *a, double zoom)
{
	printf("++ ROTAT_X BEFOR X[%lf] Y[%lf] Z[%lf]\n", a->x, a->y, a->z);
	a->x += zoom;
	a->y += zoom;
	a->z += zoom;
	printf("-- ROTAT_X AFTER X[%lf] Y[%lf] Z[%lf]\n", a->x, a->y, a->z);
}

// void zoom(t_point *a, double zoom)
// {
// 	a->x -= zoom;
// 	a->y -= zoom;
// 	a->z -= zoom;
// }




int mouse(int x, int y, void *param)
{
	printf("X[%d] --  Y[%d]\n", x, y);
	return 0;
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
	draw_map(root.mlx, root.map);

	/* ------ Using an xpm image ----- */
	int ppp = 0;
	void *nn = NULL;
	void *rr = NULL;

	int h = 0;
	int w = 0;

	// nn = mlx_new_image(root.mlx, root.sz_x, root.sz_y);

	// rr = mlx_xpm_file_to_image(root.mlx , "res/__IMG__/dove.xpm", &w, &w);

	// rr = mlx_xpm_file_to_image(root.mlx , "res/FONTS/HH2.xpm", &w, &w);


	// mlx_put_image_to_window(root.mlx, root.win, rr, 0,0);
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





	mlx_put_image_to_window(root.mlx, root.win, root.menu.img_ptr, root.menu.o_x, root.menu.o_y);
	mlx_put_image_to_window(root.mlx, root.win, root.prev.img_ptr, root.prev.o_x, root.prev.o_y);
	mlx_put_image_to_window(root.mlx, root.win, root.foot.img_ptr, root.foot.o_x, root.foot.o_y);
	// mlx_put_image_to_window(root.mlx, root.win, rr, 0,0);
	event_handler(&root);


	// mlx_key_hook (root.win , exit_esc, &root);
	mlx_loop(root.mlx);
	return (0);
}
