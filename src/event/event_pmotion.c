/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_pmotion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 05:29:19 by suddin            #+#    #+#             */
/*   Updated: 2018/03/30 02:04:15 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


inline static	int	p_func_0_ext(t_root *root, int btn)
{
	if (root->men.button[btn].stat == ST_ACTIVE)
		return (0);
	draw_button(root->men.button[btn], &(root->menu), ST_HOVER);
	mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
			root->menu.o_x, root->menu.o_y);
	root->men.btn_hover = btn;
	return (1);
}

int					pmotion_func_0(int x, int y, void *rot)
{
	int		btn;
	int		hvr;
	int		hst;
	t_root	*root;

	root = CAST_T_ROOT(rot);
	btn = -1;
	hvr = root->men.btn_hover;
	hst = (hvr != -1) ? root->men.button[hvr].stat : 0;
	if (hvr != -1)
	{
		draw_button(root->men.button[hvr], &(root->menu), hst);
		mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
				root->menu.o_x, root->menu.o_y);
		root->men.btn_hover = -1;
	}
	if (x > root->menu.o_x && x < root->menu.o_x + root->menu.x && \
			y > root->menu.o_y && y < root->menu.o_y + root->menu.y)
		if ((btn = is_button_area(root->men.button, x, y)) != -1)
			return (p_func_0_ext(root, btn));
	return (0);
}

int					pmotion_func_1(not_used int x, not_used int y, not_used void *rot)
{
	// (void)x;
	// (void)y;
	// (void)rot;
	return (0);
}

int					pmotion_func_2(not_used int x, not_used int y, not_used void *rot)
{
	// (void)x;
	// (void)y;
	// (void)rot;
	return (0);
}
