#include "main.h"


void init_menu(t_root *root, t_img *menu)
{
	menu->o_x = 0;
	menu->o_y = 0;
	menu->x	  = root->sz_x / 4;
	menu->y	  = root->sz_y;

	// printf("MENU->X [%d]\n", menu->x);
	// printf("MENU->Y [%d]\n", menu->y);
	// printf("menu x*y [%d]\n", menu->x * menu->y);
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
	// printf("PREV->X [%d]\n", prev->x);
	// printf("PREV->Y [%d]\n", prev->y);
	// printf("prev x*y [%d]\n", prev->x * prev->y);
	prev->img_ptr	= mlx_new_image(root->mlx, prev->x, prev->y);
	prev->img		= mlx_get_data_addr(prev->img_ptr, &(prev->bpp), &(prev->sl), &(prev->end));
	set_color(prev->img, prev->x * prev->y, get_col(241, 232, 202, 255));
}
