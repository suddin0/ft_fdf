#include "main.h"


void load_map(t_root *root, t_map_list *list, int btn)
{
	free_map(root->map);
	list->curr_map = btn;
	CLEAR(root->prev);
	CLEAR(root->foot);
	if ((root->map = get_map(list->map_name[btn], &(root->prev))) == NULL)
	{
		printf_text(root, &(root->prev), "%C%f%x%yMap Error", COL_ERROR,\
		root->font_24, 550, 450);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
		mlx_put_image_to_window(root->mlx, root->win, root->foot.img_ptr, \
		root->foot.o_x, root->foot.o_y);
		return;
	}
	modmatrix(root->map, rotate_x, 120);
	modmatrix(root->map, rotate_y, 120);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
	root->prev.o_x, root->prev.o_y);
}



// Draws rectangle
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
	int border;	// border height;

	if(list->error > 0)
	{
		printf("CAME HERE TO SHOW LIST ERROR %s\n", list->error_msg);
		printf_text(root, &(root->menu), "%f%C%x%y%s",  root->font_11 , COL_ERROR, 10, list->height + 10 , list->error_msg);
		return ;
	}
	i = 0;
	curr_x = list->o_x;
	curr_y = list->o_y;
	border = 2;
	while(i < list->total_map)
	{
		draw_border(&(root->menu), (curr_y  + list->height) - list->border, (curr_y  + list->height) + list->border, COLOR(root->mlx, 0x323842));
		if (i == list->curr_map)
		{
			draw_border(&(root->menu), curr_y, curr_y + list->height, PREV_BG_COLOR);
			draw_border(&(root->menu), (curr_y  + list->height) - list->border, (curr_y  + list->height) + list->border, COLOR(root->mlx, 0x099660));
		}
		printf_text(root, &(root->menu),"%f%x%y%s", root->font_18, curr_x + 10, curr_y + 30, &(list->map_name[i][strlen(MAP_PATH) + 1]));

		curr_y += list->height;
		i++;
	}

}
