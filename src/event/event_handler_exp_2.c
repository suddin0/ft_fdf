/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_exp_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 05:21:17 by suddin            #+#    #+#             */
/*   Updated: 2018/03/30 05:21:32 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

inline static void	pmotion_ext(t_root *root, int hvr, int hst)
{
	if (hvr != -1 && hvr < 3 && root->men.button[hvr].type != TP_RADIO)
	{
		draw_button(root->men.button[hvr], &(root->menu), hst);
		mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
				root->menu.o_x, root->menu.o_y);
		root->men.btn_hover = -1;
	}
}

int					pmotion(int x, int y, t_root *root)
{
	int	btn;
	int	hvr;
	int	hst;

	btn = -1;
	hvr = root->men.btn_hover;
	hst = (hvr != -1 && hvr > 0 && hvr < 3) ? root->men.button[hvr].stat : 0;
	pmotion_ext(root, hvr, hst);
	if (x > root->menu.o_x && x < root->menu.o_x + root->menu.x && \
			y > root->menu.o_y && y < root->menu.o_y + root->menu.y)
	{
		if ((btn = is_button_area(root->men.button, x, y)) != -1 && btn < 3)
		{
			if (root->men.button[btn].stat == ST_ACTIVE)
				return (0);
			draw_button(root->men.button[btn], &(root->menu), ST_HOVER);
			mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
					root->menu.o_x, root->menu.o_y);
			root->men.btn_hover = btn;
			return (1);
		}
		else
			root->evnt.pmotion[root->men.curr_opt](x, y, root);
	}
	return (0);
}
