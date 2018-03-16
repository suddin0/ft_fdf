#include "main.h"

int draw_win(t_root *root)
{
	mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, root->menu.o_x, root->menu.o_y);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	mlx_put_image_to_window(root->mlx, root->win, root->foot.img_ptr, root->foot.o_x, root->foot.o_y);
	return 1;
}


int pmotion(int x, int y, t_root *root)
{
	int btn;
	int hvr;
	int hst;

	btn = -1;
	hvr = root->men.btn_hover;
	hst = (hvr != -1 && hvr > 0 && hvr < 3) ? root->men.button[hvr].stat : 0;
	if(hvr != -1 && hvr < 3 &&  root->men.button[hvr].type != TP_RADIO)
	{
		draw_button(root->men.button[hvr], &(root->menu), hst);
		mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
			root->menu.o_x, root->menu.o_y);
		root->men.btn_hover = -1;
	}
	if(x > root->menu.o_x && x < root->menu.o_x + root->menu.x && \
	   y > root->menu.o_y && y < root->menu.o_y + root->menu.y)
	{
		if((btn = is_button_area(root->men.button, x, y)) != -1 && btn < 3)
		{
			if (root->men.button[btn].stat == ST_ACTIVE)
				return (0);
			draw_button(root->men.button[btn], &(root->menu), ST_HOVER);
			mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
				root->menu.o_x, root->menu.o_y);
			root->men.btn_hover = btn;
			return (1);
			printf("INSIDE HIVER LIL\n");
		}
		else
			root->evnt.pmotion[root->men.curr_opt](x, y, root);
	}
	return (0);
}



int key_in_set(int key, t_root *root)
{
	int i;

	i = 0;
	while(i != MAX_EVENT_KEY)
	{
		if ((root->key_set)[i] == key)
			return (i);
		i++;
	}
	return (-1);
}

int kpress(int key, t_root *root)
{
	if(key_in_set(key, root) != -1)
	{
		CLEAR(root->prev);
		(root->kevent)[key_in_set(key, root)](root);
	}
	return 1;
}




int krelease(int key, t_root *root)
{
	int clk;

	clk = root->men.btn_clicked;
	printf("Came in release BUTTON [%d] X[%d] int Y[%d]\n", key, root->sz_x, root->sz_y);

	// if(clk != -1 && key == MOUSE_LEFT)
	// {
	// 	if(root->men.button[clk].type == TP_RADIO)
	// 		return (0);
	// 	draw_button(root->men.button[clk], &(root->menu), ST_DEFAULT);
	// 	mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
	// 		root->menu.o_x, root->menu.o_y);
	// 	root->men.btn_clicked = -1;
	// 	root->men.button[clk].stat = ST_DEFAULT;
	// }
	return 1;
}

int button_press(int x, int y, t_button button)
{
	printf("CAME HERE TO CHECK LENGTH X[%d] - Y[%d]  BX[%d] - BY[%d] - BOX[%d] - BOY[%d]\n", x, y, button.x, button.y, button.o_x, button.o_y);
	if(x > button.o_x && x < button.o_x + button.x && y > button.o_y && y < button.o_y + button.y)
		return (1);
	else
		return (0);
}

void click_menu(t_root *root, int key, int x, int y)
{
	// if ( button_press(x, y, root->men.opt[0]) == 1)
	// 	printf("Print The first button\n");
	// else if ( button_press(x, y, root->men.opt[1]) == 1)
	// 	printf("Print The Second button\n");
	// else if ( button_press(x, y, root->men.opt[2]) == 1)
	// 	printf("Print The Third button\n");
}

int bpress(int key, int x, int y, t_root *root)
{
	int btn;
	int clk;
	int hst;

	btn = -1;
	clk = root->men.btn_clicked;
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
			if((btn = is_button_area(root->men.button, x, y)) != -1 && btn < 3)
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
			else
				root->evnt.bpress[root->men.curr_opt](key, x, y, root);
			}

	return (0);
}

int brelease(int key, int x, int y, t_root *root)
{
	printf("___Button release key[%d] X[%d] Y[%d]___\n", key, x, y);
	int clk;

	clk = root->men.btn_clicked;
	printf("Came in release BUTTON [%d] X[%d] int Y[%d]\n", key, x, y);

	if(clk != -1 && key == MOUSE_LEFT)
	{
		if(root->men.button[clk].type == TP_RADIO)
			return (0);
		draw_button(root->men.button[clk], &(root->menu), ST_DEFAULT);
		mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
			root->menu.o_x, root->menu.o_y);
		root->men.btn_clicked = -1;
		root->men.button[clk].stat = ST_DEFAULT;
	}
	return 1;
	// return 0;

}



void event_handler(t_root *root)
{
	mlx_hook(root->win, PMOTION, PMOTION_M, &pmotion, root); // Mouse motion
	mlx_hook(root->win, KPRESS, KPRESS_M, &kpress, root); // key press
	mlx_hook(root->win, KRELEASE, KRELEASE_M, &krelease, root); // key release
	mlx_hook(root->win, VISIBL, VISIBL_M, &draw_win, root); // expose
	mlx_hook(root->win, BPRESS, BPRESS_M, &bpress, root); // button press (mouse)
	mlx_hook(root->win, BRELEASE, BRELEASE_M, &brelease, root); // button release

}
