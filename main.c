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





	// ft_printf("-------------------ROTATION_START---------------");
	// rotat(root.map, rot);
	// ft_printf("-------------------ROTATION_END-----------------");

	// draw_map(root.map, &(root.prev));





	// mlx_put_image_to_window(root.mlx, root.win, root.menu.img_ptr, root.menu.o_x, root.menu.o_y);
	// mlx_put_image_to_window(root.mlx, root.win, root.prev.img_ptr, root.prev.o_x, root.prev.o_y);
	// mlx_put_image_to_window(root.mlx, root.win, root.foot.img_ptr, root.foot.o_x, root.foot.o_y);



	// mlx_put_image_to_window(root.mlx, root.win, rr, 0,0);
	event_func_init(&root);
	event_handler(&root);


	// mlx_key_hook (root.win , exit_esc, &root);
	mlx_loop(root.mlx);
	return (0);
}
