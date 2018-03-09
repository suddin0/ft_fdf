#include "main.h"

int draw_win(t_root *root)
{
	// mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, root->menu.o_x, root->menu.o_y);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	// mlx_put_image_to_window(root->mlx, root->win, root->foot.img_ptr, root->foot.o_x, root->foot.o_y);
	return 1;
}





int pmotion(int x, int y, t_root *root)
{
	// printf("Came in PMOTIOON X[%d] - Y[%d]\n", x, y);
	return 1;
}

//
// void trans_x(t_map *a, double v)
// {
// 	a->origine_x += v;
// }
//
// void trans_y(t_map *a, double v)
// {
// 	a->origine_y += v;
// }
//
// void zoom(t_map *a, int v)
// {
// 	if ((a->origine_x <= 0 || a->origine_y <= 0 || a->step <= 0) && v <= 0)
// 	{
// 		ft_printf("[!] Reached minimum zoom, cannot unzoom %d\n", v);
// 		return ;
// 	}
// 	a->step += v;
// 	a->origine_x += -v;
// 	a->origine_y += -v;
// }

int kpress(int key, t_root *root)
{
	CLEAR(root->prev);
	if(key == BTN_ESC || key == BTN_Q)
	{
		// mlx_destroy_image(root->mlx, root->menu.img_ptr);
		mlx_destroy_image(root->mlx, root->prev.img_ptr);
		// mlx_destroy_image(root->mlx, root->foot.img_ptr);
		mlx_destroy_window(root->mlx,root->win);
		free_map(root->map);
		printf("Key pressed %d\n", key);
		printf("[!] Exiting the programme\n");
		exit(EXIT_SUCCESS);
	}
	else if (key == BTN_UP)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modmatrix(root->map, trans_y, -3.0);
		trans_y(root->map, -10.0);
		draw_map(root->mlx, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	} // --
	else if (key == BTN_DOWN)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modmatrix(root->map, trans_y, 3.0);
		trans_y(root->map, 10.0);
		draw_map(root->mlx, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	} // --
	else if (key == BTN_RIGT)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modmatrix(root->map, trans_x, 3.0);
		trans_x(root->map, 10.0);
		draw_map(root->mlx, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	} // --
	else if (key == BTN_LEFT)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modmatrix(root->map, trans_x, -3.0);
		trans_x(root->map, -10.0);
		draw_map(root->mlx, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	} // --
	else if (key == BTN_PLUS)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modmatrix(root->map, zoom, 1.1);
		zoom(root->map, 5);
		draw_map(root->mlx, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_MINUS)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modmatrix(root->map, zoom, -1.1);
		zoom(root->map, -5);
		draw_map(root->mlx, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	} // --
	else if (key == BTN_X)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modmatrix(root->map, rotate_x, 0.10);
		draw_map(root->mlx, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	} // --
	else if (key == BTN_S)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modmatrix(root->map, rotate_x, -0.10);
		draw_map(root->mlx, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	} // --
	else if (key == BTN_Y)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modmatrix(root->map, rotate_y, 0.10);
		draw_map(root->mlx, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	} //  --
	else if (key == BTN_U)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modmatrix(root->map, rotate_y, -0.10);
		draw_map(root->mlx, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_Z)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modmatrix(root->map, rotate_z, 0.10);
		draw_map(root->mlx, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_A)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modmatrix(root->map, rotate_z, -0.10);
		draw_map(root->mlx, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	// else
	// 	printf("Came in PRESS BUTTON [%d]\n", key);

	return 1;
}


int krelease(int key, t_root *root)
{
	printf("Came in release BUTTON [%d]\n", key);
	return 1;
}

int button_press(int x, int y, t_root *root)
{
	// printf("CAME HERE TO CHECK LENGTH X[%d] - Y[%d]  BX[%d] - BY[%d] - BOX[%d] - BOY[%d]\n", x, y, button.x, button.y, button.o_x, button.o_y);
	// if(x > button.o_x && x < button.o_x + button.x && y > button.o_y && y < button.o_y + button.y)
	// 	return (1);
	// else
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
	// if(x > root->menu.o_x && x < root->menu.o_x + root->menu.x && y > root->menu.o_y && y < root->menu.o_y + root->menu.y)
	// {
	// 	click_menu(root, key, x, y);
	// 	printf("Clicked in Menu\n");
	// }
	// else if(x > root->prev.o_x && x < root->prev.o_x + root->prev.x && y > root->prev.o_y && y < root->prev.o_y + root->prev.y)
	// 	printf("Clicked in Prev\n");
	// else
	// 	printf("Came in B_PRESS\n");

	return (1);
}




void event_handler(t_root *root)
{
	mlx_hook(root->win, PMOTION, PMOTION_M, &pmotion, root); // Mouse motion
	mlx_hook(root->win, KPRESS, KPRESS_M, &kpress, root); // button press
	mlx_hook(root->win, KRELEASE, KRELEASE_M, &krelease, root); // button release
	mlx_hook(root->win, VISIBL, VISIBL_M, &draw_win, root); // expose
	mlx_hook(root->win, BPRESS, BPRESS_M, &bpress, root); // button press (mouse)

}
