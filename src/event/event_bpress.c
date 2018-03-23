#include "main.h"


int bpress_func_0(int key, int x, int y, void *rot)
{
	t_root *root;
	int btn;
	int clk;
	int hst;

	btn = -1;
	clk = root->men.btn_clicked;
	root = rot;
	// if(x > root->menu.o_x && x < root->menu.o_x + root->menu.x && y > root->menu.o_y && y < root->menu.o_y + root->menu.y)
	// {
	// 	click_menu(root, key, x, y);
	// 	printf("Clicked in Menu\n");
	// }
	// else if(x > root->prev.o_x && x < root->prev.o_x + root->prev.x && y > root->prev.o_y && y < root->prev.o_y + root->prev.y)
	// 	printf("Clicked in Prev\n");
	// elseb
	// 	printf("Came in B_PRESS\n");
	//
		if(x > root->menu.o_x && x < root->menu.o_x + root->menu.x && \
		   y > root->menu.o_y && y < root->menu.o_y + root->menu.y)
		{
			if((btn = is_button_area(root->men.button, x, y)) != -1 && btn > 2)
			{
				if (root->men.button[btn].stat == ST_ACTIVE)
					return (0);
				draw_button(root->men.button[btn], &(root->menu), ST_ACTIVE);
				mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
					root->menu.o_x, root->menu.o_y);
				root->men.button[btn].f(root);
				root->men.btn_clicked = btn;
				root->men.button[btn].stat = ST_ACTIVE;
				printf("CAME INSIDE BPRESS X[%d] Y[%d] KEY[%d] BTN[%d]\n", x, y, key, btn);
				return (1);
			}
		}

	return (0);
}

/* If pressed menu */
int bpress_func_1(int key, int x, int y, void *rot)
{
	t_root *root;
	int btn;
	int clk;
	int hst;

	btn = -1;
	clk = root->men.btn_clicked;
	root = rot;

	if(x > root->menu.o_x && x < root->menu.o_x + root->menu.x && \
	   y > root->menu.o_y && y < root->menu.o_y + root->menu.y)
	{
		if(key == MOUSE_LEFT && (btn = is_list_area(root->men.list, x, y)) != -1)
		{
			load_map(root, &(root->men.list), btn);
			// if (root->men.button[btn].stat == ST_ACTIVE)
			// 	return (0);
			// draw_button(root->men.button[btn], &(root->menu), ST_ACTIVE);
			mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
				root->menu.o_x, root->menu.o_y);

			// root->men.button[btn].f(root);
			// root->men.btn_clicked = btn;
			// root->men.button[btn].stat = ST_ACTIVE;
			printf("CAME INSIDE BPRESS X[%d] Y[%d] KEY[%d] BTN[%d]\n", x, y, key, btn);
			return (1);
		}
		else if(key == MOUSE_GOUP)
		{
			// init_list(MAP_PATH, &(root->men.list));
			if(root->men.list.o_y < MAP_LIST_OY)
				root->men.list.o_y += 40;
			CLEAR(root->menu);
			show_list(&(root->men.list), root);
			mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
				root->menu.o_x, root->menu.o_y);

		}
		else if(key == MOUSE_GODWN)
		{
			// init_list(MAP_PATH, &(root->men.list));
			if(root->men.list.o_y > -((root->men.list.height * (root->men.list.total_map - 10) ) - MAP_LIST_OY) )
				root->men.list.o_y -= 40;
			CLEAR(root->menu);
			show_list(&(root->men.list), root);
			mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
				root->menu.o_x, root->menu.o_y);

		}
	}
	draw_button(root->men.button[0], &(root->menu), root->men.button[0].stat);
	draw_button(root->men.button[1], &(root->menu), root->men.button[1].stat);
	draw_button(root->men.button[2], &(root->menu), root->men.button[2].stat);
	return (0);
}

int bpress_func_2(int key, int x, int y, void *rot)
{
	return (0);
}
