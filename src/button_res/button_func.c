#include "main.h"

int b0(t_root *root)
{

	CLEAR((root->menu));
	root->men.button[0].stat = ST_ACTIVE;
	root->men.button[1].stat = ST_DEFAULT;
	root->men.button[2].stat = ST_DEFAULT;
	// draw_button(root->men.button[0], &(root->menu), root->men.button[0].stat);
	// draw_button(root->men.button[1], &(root->menu), root->men.button[1].stat);
	// draw_button(root->men.button[2], &(root->menu), root->men.button[2].stat);
	show_button(root, &(root->menu));
	root->men.curr_opt = 0;
	mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
		root->menu.o_x, root->menu.o_y);

	return (0);

}
int b1(t_root *root)
{
	CLEAR((root->menu));
	root->men.button[0].stat = ST_DEFAULT;
	root->men.button[1].stat = ST_ACTIVE;
	root->men.button[2].stat = ST_DEFAULT;
	draw_button(root->men.button[0], &(root->menu), root->men.button[0].stat);
	draw_button(root->men.button[1], &(root->menu), root->men.button[1].stat);
	draw_button(root->men.button[2], &(root->menu), root->men.button[2].stat);
	root->men.curr_opt = 1;

	mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
		root->menu.o_x, root->menu.o_y);

	return (0);

}

int b2(t_root *root)
{
	CLEAR((root->menu));
	root->men.button[0].stat = ST_DEFAULT;
	root->men.button[1].stat = ST_DEFAULT;
	root->men.button[2].stat = ST_ACTIVE;
	draw_button(root->men.button[0], &(root->menu), root->men.button[0].stat);
	draw_button(root->men.button[1], &(root->menu), root->men.button[1].stat);
	draw_button(root->men.button[2], &(root->menu), root->men.button[2].stat);
	root->men.curr_opt = 2;

	mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
		root->menu.o_x, root->menu.o_y);

	return (0);

}

int b3(t_root *root)
{
	// CLEAR(root->prev);s
	// printf("CAME INSIDE B# FINCTION\n");
	// while(root->men.btn_clicked != -1)
	// {
	// 	sleep(2);
	// 	CLEAR(root->prev);
	// 	if(root->men.mvment == MV_TRANS)
	// 		k_y(root);
	// 		// k_left(root);
	// 	else if(root->men.mvment == MV_ROTAT)
	// 		k_y(root);
	// }

	CLEAR(root->prev);
	if(root->men.mvment == MV_TRANS)
		k_left(root);
	else if(root->men.mvment == MV_ROTAT)
		k_y(root);
	return (0);
}

int b4(t_root *root)
{
	CLEAR(root->prev);
	if(root->men.mvment == MV_TRANS)
		k_down(root);
	else if(root->men.mvment == MV_ROTAT)
		k_s(root);
	return (0);
}

int b5(t_root *root)
{
	CLEAR(root->prev);
	if(root->men.mvment == MV_TRANS)
		k_right(root);
	else if(root->men.mvment == MV_ROTAT)
		k_u(root);
	return (0);
}

int b6(t_root *root)
{
	CLEAR(root->prev);
	if(root->men.mvment == MV_TRANS)
		k_up(root);
	else if(root->men.mvment == MV_ROTAT)
		k_x(root);
	return (0);
}

int b7(t_root *root)
{
	CLEAR(root->prev);
	if(root->men.mvment == MV_TRANS)
		k_minus(root);
	else if(root->men.mvment == MV_ROTAT)
		k_z(root);
	return (0);
}

int b8(t_root *root)
{
	CLEAR(root->prev);
	if(root->men.mvment == MV_TRANS)
		k_plus(root);
	else if(root->men.mvment == MV_ROTAT)
		k_a(root);
	return (0);
}

int b9(t_root *root)
{
	return (0);
}

int b10(t_root *root)
{
	return (0);
}

int b11(t_root *root)
{
	return (0);
}

int b12(t_root *root)
{
	if (root->men.button[12].stat == ST_ACTIVE)
		return (0);
	draw_button(root->men.button[13], root->men.img, ST_DEFAULT);
	draw_button(root->men.button[12], root->men.img, ST_ACTIVE);
	root->men.button[12].stat = ST_ACTIVE;
	root->men.button[13].stat = ST_DEFAULT;
	root->men.mvment = MV_TRANS;
	mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
		root->menu.o_x, root->menu.o_y);
	return (0);
}

int b13(t_root *root)
{

	if (root->men.button[13].stat == ST_ACTIVE)
		return (0);
	draw_button(root->men.button[12], root->men.img, ST_DEFAULT);
	draw_button(root->men.button[13], root->men.img, ST_ACTIVE);
	root->men.button[13].stat = ST_ACTIVE;
	root->men.button[12].stat = ST_DEFAULT;
	root->men.mvment = MV_ROTAT;
	mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
		root->menu.o_x, root->menu.o_y);
	return (0);

}
