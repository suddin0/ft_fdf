/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_exp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 04:42:52 by suddin            #+#    #+#             */
/*   Updated: 2018/03/30 05:02:49 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

inline static	int		key_in_set(int key, t_root *root)
{
	int i;

	i = 0;
	while (i != MAX_EVENT_KEY)
	{
		if ((root->key_set)[i] == key)
			return (i);
		i++;
	}
	key = 0;
	return (-1);
}

inline static	int		kpress_exec(t_root *root)
{
	CLEAR(root->prev);
	(root->kevent)[key_in_set(root->key, root)](root);
	return (0);
}

int						kpress(int key, t_root *root)
{
	if (key_in_set(key, root) != -1)
	{
		root->key = key;
		mlx_loop_hook(root->mlx, kpress_exec, root);
	}
	return (1);
}

int						krelease(int key, t_root *root)
{
	int clk;

	clk = root->men.btn_clicked;
	root->key = 0;
	mlx_loop_hook(root->mlx, NULL, NULL);
	key = 0;
	return (1);
}

int						bpress(int key, int x, int y, t_root *root)
{
	int	btn;
	int	clk;

	btn = -1;
	clk = root->men.btn_clicked;
	if (x > root->menu.o_x && x < root->menu.o_x + root->menu.x && \
			y > root->menu.o_y && y < root->menu.o_y + root->menu.y)
	{
		if ((btn = is_button_area(root->men.button, x, y)) != -1 && btn < 3)
		{
			if (btn != 1 && root->men.button[btn].stat == ST_ACTIVE)
				return (0);
			draw_button(root->men.button[btn], &(root->menu), ST_ACTIVE);
			mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
					root->menu.o_x, root->menu.o_y);
			root->men.button[btn].f(root);
			root->men.btn_clicked = btn;
			root->men.button[btn].stat = ST_ACTIVE;
			return (1);
		}
		else
			root->evnt.bpress[root->men.curr_opt](key, x, y, root);
	}
	return (0);
}
