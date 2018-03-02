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
	printf("Came in PMOTIOON X[%d] - Y[%d]\n", x, y);
	return 1;
}


void trans_x(t_map *a, double v)
{
	a->origine_x += v;
}

void trans_y(t_map *a, double v)
{
	a->origine_y += v;
}

void zoom(t_map *a, int v)
{
	a->step += v;
	a->origine_x += -v;
	a->origine_y += -v;
	// a->z += v;
}


void change_z(t_point *a, double v)
{

	a->z += v;
	printf("-- change_z AFTER X[%lf] Y[%lf] Z[%lf]\n", a->x, a->y, a->z);
}


int kpress(int key, t_root *root)
{
	CLEAR(root->prev);
	if(key == BTN_ESC || key == BTN_Q)
	{
		mlx_destroy_image(root->mlx, root->menu.img_ptr);
		mlx_destroy_image(root->mlx, root->prev.img_ptr);
		mlx_destroy_image(root->mlx, root->foot.img_ptr);
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
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_DOWN)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modmatrix(root->map, trans_y, 3.0);
		trans_y(root->map, 10.0);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_RIGT)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modmatrix(root->map, trans_x, 3.0);
		trans_x(root->map, 10.0);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_LEFT)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modmatrix(root->map, trans_x, -3.0);
		trans_x(root->map, -10.0);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_PLUS)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modmatrix(root->map, zoom, 1.1);
		zoom(root->map, 5);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_MINUS)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modmatrix(root->map, zoom, -1.1);
		zoom(root->map, -5);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_X)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modmatrix(root->map, rotate_x, 0.10);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_S)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modmatrix(root->map, rotate_x, -0.10);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_Y)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modmatrix(root->map, rotate_y, 0.10);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_U)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modmatrix(root->map, rotate_y, -0.10);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_Z)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modmatrix(root->map, rotate_z, 0.10);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_A)
	{
	// void modmatrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modmatrix(root->map, rotate_z, -0.10);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else
		printf("Came in PRESS BUTTON [%d]\n", key);

	return 1;
}


int krelease(int key, t_root *root)
{
	printf("Came in release BUTTON [%d]\n", key);
	return 1;
}

void event_handler(t_root *root)
{
	mlx_hook(root->win, PMOTION, PMOTION_M, &pmotion, root); // Mouse motion
	mlx_hook(root->win, KPRESS, KPRESS_M, &kpress, root); // button press
	mlx_hook(root->win, KRELEASE, KRELEASE_M, &krelease, root); // button release
	mlx_hook(root->win, VISIBL, VISIBL_M, &draw_win, root); // expose

}
