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

// typedef struct s_fdfmap
// {
// 	char		*name;		// stores the maps name
// 	char		*path;		// stores the maps path
// 	t_image		*img;		// A copy of the section where map is shown
// 	t_point		**map;		// stores the map as an long int table[data->col][data->raw]
// 	long		*line_sz;	// stores the amount of number a line contains (for looping purpose)
// 	int			file_sz;	// stores the size if the map file
// 	int			lines;		// saves total number of lines in the chained list (data)
//
// 	t_m_data	*data;		// The chained list that contain each line of the map
//
// 	double		origine_x;	// Where should the ´x´ point of the map start
// 	double		origine_y;	// Where should the ´y´ point of the map start
// 	int			step;		// Distance between each points
// 	int 		color;
// 	struct s_fdfmap	*next;	// next map;
// }	t_map;


int main(int argc, char **argv)
{
	t_root root;
	t_map *map;

	map = NULL;
	if(pre_check(argc, argv) == 0)
		return (0);
	root_init(&root, argv);

	ft_printf("******** END OF PERSING *********\n");


	init_prev(&root, &(root.prev));
	if(!(map = get_map(argv[1], &(root.prev))))
		return (-1);
	root.map = map;

	// print_map(map, 3);
	printf("map.name[%s]\n", map->name);
	printf("map.lines[%d]\n", map->lines);
	printf("map.line_size[0][%ld]\n", map->line_sz[0]);


	// modmatrix(map, rotate_x, 120);
	// modmatrix(map, rotate_y, 120);
	draw_map(root.mlx, root.map);

	mlx_put_image_to_window(root.mlx, root.win, root.prev.img_ptr, root.prev.o_x, root.prev.o_y);
	event_handler(&root);
	mlx_loop(root.mlx);
	return (0);
}
