/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:18:53 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 12:20:04 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_button(t_button btn, t_image *img, int st)
{
	int x;
	int y;
	int k;

	x = btn.o_x * 4;
	y = btn.o_y;
	k = 0;
	while (y < btn.o_y + btn.y)
	{
		x = btn.o_x * 4;
		while (x < (btn.o_x + btn.x) * 4)
		{
			if (x > 0 && y > 0 && (x + (y * img->x * 4)) < (img->x * img->y) *\
					4 && (x < (img->x * 4) && y * img->y))
			{
				(img->img)[x + 0 + (y * (img->x * 4))] = (btn.view[st])[k + 0];
				(img->img)[x + 1 + (y * (img->x * 4))] = (btn.view[st])[k + 1];
				(img->img)[x + 2 + (y * (img->x * 4))] = (btn.view[st])[k + 2];
				(img->img)[x + 3 + (y * (img->x * 4))] = (btn.view[st])[k + 3];
			}
			k += 4;
			x += 4;
		}
		y++;
	}
}
