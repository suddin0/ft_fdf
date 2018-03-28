/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 08:16:08 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 12:14:01 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	b0(t_root *root)
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

int	b1(t_root *root)
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

int	b2(t_root *root)
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

int	b3(t_root *root)
{
	CLEAR(root->prev);
	if (root->men.mvment == MV_TRANS)
		k_left(root);
	else if (root->men.mvment == MV_ROTAT)
		k_y(root);
	mlx_loop_hook(root->mlx, b3, root);
	return (0);
}
