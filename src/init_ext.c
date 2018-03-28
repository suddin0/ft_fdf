/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:36:48 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 12:36:50 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void					init_foot(t_root *root, t_image *f)
{
	f->o_x = MENU_X;
	f->o_y = PREV_Y;
	f->x = FOOT_X;
	f->y = FOOT_Y;
	f->bg = COLOR(root->mlx, FOOT_BG_COLOR);
	f->img_ptr = mlx_new_image(root->mlx, f->x, f->y);
	f->img = mlx_get_data_addr(f->img_ptr, &(f->bpp), &(f->sl), &(f->end));
	set_color(f->img, f->x * f->y, f->bg);
	mlx_put_image_to_window(root->mlx, root->win, f->img_ptr, f->o_x, f->o_y);
}
