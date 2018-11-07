/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 07:20:42 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 18:30:44 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

inline static	void	font_var_init(t_font_var *var, \
		int col, int o_x, int o_y)
{
	var->x = o_x * 4;
	var->y = o_y;
	var->k = 0;
	var->a = COL_A(col);
	var->r = COL_R(col);
	var->g = COL_G(col);
	var->b = COL_B(col);
	var->bga = 0;
	var->bgr = 0;
	var->bgg = 0;
	var->bgb = 0;
	var->opacity = 0;
	var->o_opacity_r = 0;
	var->opacity = (double)((double)(var->a * 100) / 255) * 0.01;
}

inline static	void	rgb_color_set(t_font_var *var, t_image *img, t_char chr)
{
	var->o_opacity_r = (double)(((unsigned char)(chr.data)[var->k + 2] * \
				100) / 255);
	var->o_opacity_r = var->o_opacity_r * 0.01;
	var->o_opacity_r = var->opacity - var->o_opacity_r;
	var->o_opacity_r = (var->o_opacity_r > 0 && \
			var->o_opacity_r < var->opacity) ? var->o_opacity_r : 0;
	var->bga = (t_uchar)((img->img)[var->x + 3 + (var->y * (img->x * 4))]);
	var->bgr = (t_uchar)((img->img)[var->x + 2 + (var->y * (img->x * 4))]);
	var->bgg = (t_uchar)((img->img)[var->x + 1 + (var->y * (img->x * 4))]);
	var->bgb = (t_uchar)((img->img)[var->x + 0 + (var->y * (img->x * 4))]);
}

inline static	void	rgb_set(t_font_var *v, t_image *img, t_char chr)
{
	rgb_color_set(v, img, chr);
	((img->img)[v->x + 2 + (v->y * (img->x * 4))]) = ((v->opacity - \
	v->o_opacity_r) * v->r + (1 - (v->opacity - v->o_opacity_r)) * v->bgr);
	(img->img)[v->x + 1 + (v->y * (img->x * 4))] = ((v->opacity - \
	v->o_opacity_r) * v->g + (1 - (v->opacity - v->o_opacity_r)) * v->bgg);
	(img->img)[v->x + 0 + (v->y * (img->x * 4))] = ((v->opacity - \
	v->o_opacity_r) * v->b + (1 - (v->opacity - v->o_opacity_r)) * v->bgb);
}

void					draw_font(t_char chr, t_font_data *d, int o_x, int o_y)
{
	t_font_var var;

	if (chr.x == 0 || chr.y == 0)
		return ;
	font_var_init(&var, d->c, o_x, o_y);
	while (var.y < o_y + chr.y)
	{
		var.x = o_x * 4;
		while (var.x < (o_x + chr.x) * 4)
		{
			if ((var.x > 0 && var.y > 0) && (var.x + (var.y * d->img->x)) < \
	(d->img->x * d->img->y) && (var.x < (d->img->x * 4) && var.y & d->img->y))
				if ((t_uchar)(chr.data)[var.k + 0] != 2 || \
						(t_uchar)(chr.data)[var.k + 1] != 2 || \
						(t_uchar)(chr.data)[var.k + 2] != 2)
					rgb_set(&var, d->img, chr);
			var.k += 4;
			var.x += 4;
		}
		(var.y)++;
	}
}
