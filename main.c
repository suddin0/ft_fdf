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

void put_color(t_img *img, int x, int y, t_color color)
{
	x = (x > img->x) ? 0 : x;
	y = (y > img->y) ? 0 : y;
	if(x <= img->x && x > 0 && y <= img->y)
		((t_color *) img->img)[x + (y * img->x)]  = color;
}


//void  draw_line_img_iso(t_root *r, int Xo, int Yo, int  Xn, int Yn, t_color color)
void  draw_line_img_iso(t_img *img, double Xo, double Yo, double  Xn, double Yn, t_color color)
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

void  draw_line(t_img *img, double Xo, double Yo, double  Xn, double Yn, t_color color)
//void  draw_line(t_img *img, double Xo, double Yo, double Zo, double  Xn, double Yn, double Zn, t_color color)
{
	unsigned steps;
	double	x;
	double	y;
	double Xincrement;
	double Yincrement;

	steps = ((Xn - Xo) > (Yn - Yo)) ? fabs(Xn - Xo) : fabs(Yn - Yo);
	//steps = (fabs((Xn/Zn) - (Xo/ Zo)) > fabs((Yn/Zn) - (Yo/Zo))) ? fabs((Xn/Zn) - (Xo/Zo)) : fabs((Yn/Zn) - (Yo/Zo));

	x = Xo;
	y = Yo;

	//x = Xo / Zo;
	//y = Yo / Zo;

	Xincrement = (Xn - Xo) / (double) steps; // X or Y increment by this ration
	Yincrement = (Yn - Yo) / (double) steps;

	//Xincrement = ((Xn/Zn) - (Xo/Zo)) / (float) steps; // X or Y increment by this ration
	//Yincrement = ((Yn/Zn) - (Yo/Zo)) / (float) steps;

	printf("DRAW-LiNE                   Xo[%6.6lf]    Yo[%6.6lf]\n", Xo, Yo);
	printf("DRAW-LiNE                   Xn[%6.6lf]    Yn[%6.6lf]\n", Xn, Yn);
	printf("CAME HERE int DRAW-LiNE  X-INC[%6.6lf] Y-INC[%6.6lf]\n", Xincrement, Yincrement);
	while(steps)
	{
		x += Xincrement;
		y += Yincrement;
		//put_color(img, fabs(x), fabs(y), color); // Normal view
		put_color(img, fabs(x), fabs(y), color); // Normal view
		steps--;
	}
}



t_color	  get_col(int r, int g, int b, int a)
{
	t_color	col;

	col.b = b;
	col.g = g;
	col.r = r;
	col.a = a;
	return (col);
}

void set_color(char *img, unsigned int len, t_color col)
{
	int i;

	i = 0;
	while (i != len)
		((t_color *) img)[i++] = col;
}

void init_menu(t_root *root, t_img *menu)
{
	menu->o_x = 0;
	menu->o_y = 0;
	menu->x	  = root->sz_x / 4;
	menu->y	  = root->sz_y;
	menu->img_ptr	= mlx_new_image(root->mlx, menu->x , menu->y);
	menu->img		= mlx_get_data_addr(menu->img_ptr, &(menu->bpp), &(menu->sl), &(menu->end));
	set_color(menu->img, menu->x * menu->y, get_col(51, 51, 51, 0));
}

void init_prev(t_root *root, t_img *prev)
{
	prev->o_x = root->sz_x / 4;
	prev->o_y = 0;
	prev->x	  = root->sz_x - root->sz_x / 4;
	prev->y	  = root->sz_y;
	prev->img_ptr	= mlx_new_image(root->mlx, prev->x, prev->y);
	prev->img		= mlx_get_data_addr(prev->img_ptr, &(prev->bpp), &(prev->sl), &(prev->end));
	set_color(prev->img, prev->x * prev->y, get_col(241,232,202, 0));
}
//  draw_line(t_img *img, double Xo, double Yo, double  Xn, double Yn, t_color color)
void show_map(t_map *map, t_img *img)
{
	int l;
	int p;
	int step;
	double x;
	double y;

	double z1;
	double z2;

	l = 0;
	p = 0;
	step = 30;
	x = ORIGINE_X;
	y = ORIGINE_Y;
	while (l < map->lines)
	{
		p = 0;
		while (p  <= map->line_sz[l])
		{
			//if((p + 1) < map->line_sz[l])
			if((p + 1) < map->line_sz[l])
			{
				//z1 = ((double) map->map[l][p	] * 0.5 == 0) ? 1.0 : (double) map->map[l][p	] * 0.3;
				//z2 = ((double) map->map[l][p + 1] * 0.5 == 0) ? 1.0 : (double) map->map[l][p + 1] * 0.3;
				z1 = (((double) map->map[l][p	] * 1.50 == 0) ? 1.0 : (double) map->map[l][p     ] * 1.50) * 0.10;
				z2 = (((double) map->map[l][p + 1] * 1.50 == 0) ? 1.0 : (double) map->map[l][p + 1] * 1.50) * 0.10;
				draw_line(img, x / z1, y / z1, (x + step) / z2, y/ z2, get_col(25,25,25, 0));
				//draw_line(img, x, y, z1, (x + step), y, z2, get_col(25,25,25, 0));
			}
			//ft_printf("CAME HERE\n");
			x += step;
			p += 1;
		}

		x = ORIGINE_X;
		y += step;
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
	print_map(map, 3);

	init_menu(&root, &(root.menu));
	init_prev(&root, &(root.prev));


	//draw_line(&(root.prev), 10, 10, 100, 10, get_col(25,25,25, 0));

	show_map(root.map, &(root.prev));

	mlx_put_image_to_window(root.mlx, root.win, root.menu.img_ptr, root.menu.o_x, root.menu.o_y);
	mlx_put_image_to_window(root.mlx, root.win, root.prev.img_ptr, root.prev.o_x, root.prev.o_y);
	mlx_key_hook (root.win , exit_esc, &root);
	mlx_loop(root.mlx);
	return (0);
}






