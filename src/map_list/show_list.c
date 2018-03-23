#include "main.h"


void load_map(t_root *root, t_map_list *list, int btn)
{

	printf("A MAP WAS CLICKED -------------------------> [%d]\n", btn);
	free_map(root->map);
	root->map = get_map(list->map_name[btn], &(root->prev));
	CLEAR(root->prev);
	modmatrix(root->map, rotate_x, 120);
	modmatrix(root->map, rotate_y, 120);
	draw_map(root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
	root->prev.o_x, root->prev.o_y);
}



void draw_border(t_image *img, int start, int height, int col)
{
	int x;
	int y;

	x = 0;
	y = start;
	while (y < height)
	{
		while(x++ != img->x)
			put_color(img, x, y, col);
		x = 0;
		y++;
	}
}


void show_list(t_map_list *list, t_root *root)
{
	int i;
	int curr_x; // current x
	int curr_y; // current y
	int div_height; // height of each division
	int border;		// border height;

	i = 0;
	curr_x = list->o_x;
	curr_y = list->o_y;
	div_height = 50;
	border = 2;
	while(i < list->total_map)
	{
		printf_text(root, &(root->menu),"%x%y%s", curr_x + 10, curr_y + 30, &(list->map_name[i][strlen(MAP_PATH) + 1]));
		draw_border(&(root->menu), (curr_y  + list->height) - list->border, (curr_y  + list->height) + list->border, COLOR(root->mlx, 0x323842));
		curr_y += list->height;
		i++;
	}

}
