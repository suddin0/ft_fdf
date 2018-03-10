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


int key_in_set(int key, t_root *root)
{
	int i;

	i = 0;
	while(i != MAX_EVENT_KEY)
	{
		printf("INSIDE KEY_IN_SET  i[%d]\n", i);
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

}

int bpress(int key, int x, int y, t_root *root)
{
	
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
