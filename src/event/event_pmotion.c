#include "main.h"


int pmotion_func_0(int x, int y, void *rot)
{
	t_root *root;
	int btn;
	int hvr;
	int hst;

	root = rot;
	btn = -1;
	hvr = root->men.btn_hover;
	hst = (hvr != -1) ? root->men.button[hvr].stat : 0;
	if(hvr != -1 &&  root->men.button[hvr].type != TP_RADIO)
	{
		draw_button(root->men.button[hvr], &(root->menu), hst);
		mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
			root->menu.o_x, root->menu.o_y);
		root->men.btn_hover = -1;
	}
	if(x > root->menu.o_x && x < root->menu.o_x + root->menu.x && \
	   y > root->menu.o_y && y < root->menu.o_y + root->menu.y)
		if((btn = is_button_area(root->men.button, x, y)) != -1)
		{
			if (root->men.button[btn].stat == ST_ACTIVE)
				return (0);
			draw_button(root->men.button[btn], &(root->menu), ST_HOVER);
			mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
				root->menu.o_x, root->menu.o_y);
			root->men.btn_hover = btn;
			return (1);
		}
	return (0);
}

int pmotion_func_1(int x, int y, void *rot)
{

	return (0);
}

int pmotion_func_2(int x, int y, void *rot)
{

	return (0);
}
