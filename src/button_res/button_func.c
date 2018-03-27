/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 08:16:08 by suddin            #+#    #+#             */
/*   Updated: 2018/03/27 08:16:13 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int b0(t_root *root)
{

	CLEAR((root->menu));
	root->men.button[0].stat = ST_ACTIVE;
	root->men.button[1].stat = ST_DEFAULT;
	root->men.button[2].stat = ST_DEFAULT;
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
	root->men.curr_opt = 1;
	if (root->men.list.map_name)
		free_list(&(root->men.list));
	init_list(MAP_PATH, &(root->men.list));
	show_list(&(root->men.list), root);
	draw_button(root->men.button[0], &(root->menu), root->men.button[0].stat);
	draw_button(root->men.button[1], &(root->menu), root->men.button[1].stat);
	draw_button(root->men.button[2], &(root->menu), root->men.button[2].stat);
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
	CLEAR(root->prev);
	if (root->men.mvment == MV_TRANS)
		k_left(root);
	else if (root->men.mvment == MV_ROTAT)
		k_y(root);
	mlx_loop_hook(root->mlx, b3, root);
	return (0);
}

int b4(t_root *root)
{
	CLEAR(root->prev);
	if (root->men.mvment == MV_TRANS)
		k_down(root);
	else if (root->men.mvment == MV_ROTAT)
		k_s(root);
	mlx_loop_hook(root->mlx, b4, root);
	return (0);
}

int b5(t_root *root)
{
	CLEAR(root->prev);
	if (root->men.mvment == MV_TRANS)
		k_right(root);
	else if (root->men.mvment == MV_ROTAT)
		k_u(root);
	mlx_loop_hook(root->mlx, b5, root);
	return (0);
}

int b6(t_root *root)
{
	CLEAR(root->prev);
	if (root->men.mvment == MV_TRANS)
		k_up(root);
	else if (root->men.mvment == MV_ROTAT)
		k_x(root);
	mlx_loop_hook(root->mlx, b6, root);
	return (0);
}

int b7(t_root *root)
{
	CLEAR(root->prev);
	if (root->men.mvment == MV_TRANS)
		k_minus(root);
	else if (root->men.mvment == MV_ROTAT)
		k_z(root);
	mlx_loop_hook(root->mlx, b7, root);
	usleep(25000);
	return (0);
}

int b8(t_root *root)
{
	CLEAR(root->prev);
	if (root->men.mvment == MV_TRANS)
		k_plus(root);
	else if (root->men.mvment == MV_ROTAT)
		k_a(root);
	mlx_loop_hook(root->mlx, b8, root);
	usleep(25000);
	return (0);
}

int b9(t_root *root)
{
	char *name_tmp;

	name_tmp = ft_strdup(root->map->name);
	free_map(root->map);
	if((root->map = get_map(name_tmp, &(root->prev))) == NULL)
		ft_printf("[-] Error: getting file (b9: button 9 function, load map)");
	free(name_tmp);
	CLEAR(root->prev);
	modmatrix(root->map, rotate_x, 120);
	modmatrix(root->map, rotate_y, 120);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
	return (0);
}

int b10(t_root *root)
{
	char *name_tmp;

	name_tmp = ft_strdup(root->map->name);
	free_map(root->map);
	if ((root->map = get_map(name_tmp, &(root->prev))) == NULL)
		ft_printf("[-] Error: getting file (b9: button 9 function, reload map)");
	free(name_tmp);
	CLEAR(root->prev);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
		root->prev.o_x, root->prev.o_y);
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
