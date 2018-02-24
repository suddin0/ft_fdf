#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int	exit_esc(int key, t_root *root)
{
	//root->key_pressed = key;

	if(key == BTN_ESC || key == BTN_Q)
	{
		mlx_destroy_image(root->mlx, root->menu.img_ptr);
		mlx_destroy_image(root->mlx, root->prev.img_ptr);
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
//


//void  draw_line_img_iso(t_root *r, int Xo, int Yo, int  Xn, int Yn, t_color color)
void  draw_line_iso(t_image *img, double Xo, double Yo, double  Xn, double Yn, t_color color)
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

void rotat_x(t_point *a, double deg)
{
	double x;
	double y;
	double z;

	x = a->x;
	y = a->y;
	z = a->z;
	printf("ROTAT_X BEFOR X[%lf] Y[%lf] Z[%lf]\n", x, y, z);


	a->x = (x * 1)  + (y *  0       ) + (z * 0        );
	a->y = (x * 0)  + (y *  cos(deg)) + (z * -sin(deg));
	a->z = (x * 0)  + (y *  sin(deg)) + (z *  cos(deg));
	printf("ROTAT_X AFTER X[%lf] Y[%lf] Z[%lf]\n", a->x, a->y, a->z);

}


void rotat(t_map *map)
{
	int l;
	int p;

	l = 0;
	p = 0;
	while (l < map->lines)
	{
		while (p < map->line_sz[l])
		{
			rotat_x(&(map->map[l][p]) , 40.0);
			p++;
		}
		p = 0;
		l++;
	}
}

void  draw_line_p(t_image *img, t_point o, t_point n, t_color color)
{
	unsigned steps;
	double	x;
	double	y;
	double Xincrement;
	double Yincrement;

	o.x /= (o.z);
	o.y /= (o.z);
	n.x /= (n.z);
	n.y /= (n.z);

	 printf("DRAW LINE OX[%lf] OY[%lf] -- NX[%lf] NY[%lf]\n", o.x, o.y, n.x, n.y);

	steps = ((n.x - o.x) > (n.y - o.y)) ? fabs(n.x - o.x) : fabs(n.y - o.y);
	x = o.x;
	y = o.y;

	Xincrement = (n.x - o.x) / (double) steps;
	Yincrement = (n.y - o.y) / (double) steps;
	while(steps)
	{
		x += Xincrement;
		y += Yincrement;
		put_color(img, x, y, color); // Normal view
		steps--;
	}
}



void show_map(t_map *map, t_image *img)
{
	int l;
	int p;
	double step;
	t_point **m;
	t_point a;
	t_point b;

	l = 0;
	p = 0;
	m = map->map;
	//rotat(map);
	while (l < map->lines)
	{
		// printf("CAME HERE show_map\n");
		p = 0;
		while (p  < map->line_sz[l])
		{
			// printf("CAME HERE show_map WHILE p < map->line_sz\n");
			if (l + 1 < map->lines && p < map->line_sz[l + 1])
			{
				draw_line_p(img, m[l][p] , m[l + 1][p], get_col(25, 25, 25, 0));
			}
			if (p + 1 <  map->line_sz[l])
			{
				draw_line_p(img, m[l][p], m[l][p + 1], get_col(25, 25, 25, 0));
			}
			p += 1;
			// if (p > 60)
			// 	return ;
		}
		l++;
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

	if(!(map = get_map(argv[1])))
		return (-1);
	root.map = map;
	printf("******** END OF PERSING *********\n");
	//print_map(map, 3);

	init_menu(&root, &(root.menu));
	init_prev(&root, &(root.prev));


	t_point x;
	t_point y;

	x.x = 10 ;		x.y = 10 ;
	//x.x = 10 * cos(90);		x.y = 20 * -sin(90);
	//y.x = 50 * sin(90);		y.y = 20 *  cos(90);

	int xx;
	int yy;

	xx = 50;
	yy = 10;
	y.x = xx * cos(90)	+	yy * -sin(90);
	y.y = xx * sin(90)	+	yy *  cos(90);

	//draw_line(&(root.prev), x.x, x.y, y.x, y.y, get_col(25,25,25, 0));
	//line(&(root.prev), x.x, x.y, y.x, y.y, get_col(0, 0, 0, 0));
	//line(&(root.prev), 10 , 10, 50, 15, get_col(0, 0, 0, 0));

	show_map(root.map, &(root.prev));

	/* ------ Using an xpm image ----- */
	int ppp = 0;
	void *nn = NULL;
	void *rr = NULL;

	int h = 0;
	int w = 0;

	nn = mlx_new_image(root.mlx, root.sz_x, root.sz_y);
	// rr = mlx_xpm_file_to_image(root.mlx , "res/__IMG__/dove.xpm", &w, &w);
	rr = mlx_xpm_file_to_image(root.mlx , "res/FONTS/HH2.xpm", &w, &w);
	// mlx_put_image_to_window(root.mlx, root.win, rr, 0,0);
	/* ---------- End xpm image view -------- */


	mlx_put_image_to_window(root.mlx, root.win, root.menu.img_ptr, root.menu.o_x, root.menu.o_y);
	mlx_put_image_to_window(root.mlx, root.win, root.prev.img_ptr, root.prev.o_x, root.prev.o_y);
	mlx_put_image_to_window(root.mlx, root.win, rr, 0,0);

	mlx_key_hook (root.win , exit_esc, &root);
	mlx_loop(root.mlx);
	return (0);
}
