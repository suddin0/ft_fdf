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
	// a->z += v;
}


void rotat_x(t_point *a, double v)
{
	double x;
	double y;
	double z;

	x = a->x;
	y = a->y;
	z = a->z;
	printf("++ ROTAT_X BEFOR X[%lf] Y[%lf] Z[%lf]\n", x, y, z);


	a->x = (x * 1)  + (y *         0) + (z *         0);
	a->y = (x * 0)  + (y *  cos(v)) + (z * -sin(v));
	a->z = (x * 0)  + (y *  sin(v)) + (z *  cos(v));
	printf("-- ROTAT_X AFTER X[%lf] Y[%lf] Z[%lf]\n", a->x, a->y, a->z);

}

void rotat_y(t_point *a, double v)
{
	double x;
	double y;
	double z;

	x = a->x;
	y = a->y;
	z = a->z;
	printf("++ ROTAT_X BEFOR X[%lf] Y[%lf] Z[%lf]\n", x, y, z);


	a->x = (x *  cos(v))  + (y * 0) + (z *  sin(v));
	a->y = (x *       0)  + (y * 1) + (z *        0);
	a->z = (x * -sin(v))  + (y * 0) + (z *  cos(v));
	printf("-- ROTAT_X AFTER X[%lf] Y[%lf] Z[%lf]\n", a->x, a->y, a->z);

}

void rotat_z(t_point *a, double v)
{
	double x;
	double y;
	double z;

	x = a->x;
	y = a->y;
	z = a->z;
	printf("++ ROTAT_X BEFOR X[%lf] Y[%lf] Z[%lf]\n", x, y, z);


	a->x = (x * cos(v))  + (y * -sin(v)) + (z * 0);
	a->y = (x * sin(v))  + (y *  cos(v)) + (z * 0);
	a->z = (x *      0)  + (y *       0) + (z * 1);
	printf("-- ROTAT_X AFTER X[%lf] Y[%lf] Z[%lf]\n", a->x, a->y, a->z);
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
	// void modif_matrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modif_matrix(root->map, trans_y, -3.0);
		trans_y(root->map, -3.0);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_DOWN)
	{
	// void modif_matrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modif_matrix(root->map, trans_y, 3.0);
		trans_y(root->map, 3.0);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_RIGT)
	{
	// void modif_matrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modif_matrix(root->map, trans_x, 3.0);
		trans_x(root->map, 3.0);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_LEFT)
	{
	// void modif_matrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modif_matrix(root->map, trans_x, -3.0);
		trans_x(root->map, -3.0);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_PLUS)
	{
	// void modif_matrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modif_matrix(root->map, zoom, 1.1);
		zoom(root->map, 5);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_MINUS)
	{
	// void modif_matrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		// modif_matrix(root->map, zoom, -1.1);
		zoom(root->map, -5);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_X)
	{
	// void modif_matrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modif_matrix(root->map, rotat_x, 0.10);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_S)
	{
	// void modif_matrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modif_matrix(root->map, rotat_x, -0.10);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_Y)
	{
	// void modif_matrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modif_matrix(root->map, rotat_y, 0.10);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_U)
	{
	// void modif_matrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modif_matrix(root->map, rotat_y, -0.10);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_Z)
	{
	// void modif_matrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modif_matrix(root->map, rotat_z, 0.10);
		draw_map(root->prev.img_ptr, root->map);
		mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	}
	else if (key == BTN_A)
	{
	// void modif_matrix(t_map *map, void *(f(t_point *a, double val)), double rot);
		modif_matrix(root->map, rotat_z, -0.10);
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
