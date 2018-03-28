/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bpress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 04:57:54 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 05:01:50 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	bpress_func_0(int key, int x, int y, void *rot)
{
	t_root	*root;
	int		btn;
	int		clk;
	int		hst;

	btn = -1;
	clk = root->men.btn_clicked;
	root = rot;
	if (x > root->menu.o_x && x < root->menu.o_x + root->menu.x && y > \
	root->menu.o_y && y < root->menu.o_y + root->menu.y && key == MOUSE_LEFT)
	{
		if ((btn = is_button_area(root->men.button, x, y)) != -1 && btn > 2)
		{
			if (root->men.button[btn].stat == ST_ACTIVE)
				return (0);
			draw_button(root->men.button[btn], &(root->menu), ST_ACTIVE);
			mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
					root->menu.o_x, root->menu.o_y);
			root->men.button[btn].f(root);
			root->men.btn_clicked = btn;
			root->men.button[btn].stat = ST_ACTIVE;
			return (1);
		}
	}
	return (0);
}

int	bpress_func_1(int key, int x, int y, void *rot)
{
	t_root	*root;
	int		btn;
	int		clk;
	int		hst;

	btn = -1;
	clk = root->men.btn_clicked;
	root = rot;
	if (x > root->menu.o_x && x < root->menu.o_x + root->menu.x && \
	y > root->menu.o_y && y < root->menu.o_y + root->menu.y)
	{
		if (key == MOUSE_LEFT && (btn = is_list_area(root->men.list, x, y)) \
				!= -1)
		{
			CLEAR(root->menu);
			load_map(root, &(root->men.list), btn);
			show_list(&(root->men.list), root);
		}
		else if (key == MOUSE_GOUP)
		{
			if (root->men.list.o_y < MAP_LIST_OY)
				root->men.list.o_y += 40;
			CLEAR(root->menu);
			show_list(&(root->men.list), root);
			mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
					root->menu.o_x, root->menu.o_y);
		}
		else if (key == MOUSE_GODWN)
		{
			if (root->men.list.o_y > -((root->men.list.height * \
							(root->men.list.total_map - 10)) - MAP_LIST_OY))
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
	mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
			root->menu.o_x, root->menu.o_y);
	return (0);
}

int	bpress_func_2(int key, int x, int y, void *rot)
{
	return (0);
}
