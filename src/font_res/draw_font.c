/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 07:20:42 by suddin            #+#    #+#             */
/*   Updated: 2018/03/27 07:33:43 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


inline static	void font_var_init(t_font_var *var, int col, int o_x, int o_y)
{
	var->x = o_x * 4;
	var->y = o_y;
	var->k = 0;
	var->A = COL_A(col);
	var->R = COL_R(col);
	var->G = COL_G(col);
	var->B = COL_B(col);
	var->BGA = 0;
	var->BGR = 0;
	var->BGG = 0;
	var->BGB = 0;
	var->opacity = 0;
	var->o_opacity_r = 0;
	var->opacity = (double) ((double) (var->A * 100) / 255) * 0.01;
}

inline static	void rgb_color_set(t_font_var *var, t_image *img, t_char chr)
{
	var->o_opacity_r = (double) (((unsigned char) \
				(chr.data)[var->k + 2] * 100) / 255);
	var->o_opacity_r = var->o_opacity_r * 0.01;
	var->o_opacity_r = var->opacity - var->o_opacity_r;
	var->o_opacity_r = (var->o_opacity_r > 0 && \
			var->o_opacity_r < var->opacity) ? var->o_opacity_r : 0;
	var->BGA = (t_uchar) ((img->img)[var->x + 3 + (var->y * (img->x * 4))]);
	var->BGR = (t_uchar) ((img->img)[var->x + 2 + (var->y * (img->x * 4))]);
	var->BGG = (t_uchar) ((img->img)[var->x + 1 + (var->y * (img->x * 4))]);
	var->BGB = (t_uchar) ((img->img)[var->x + 0 + (var->y * (img->x * 4))]);
}


inline static	void rgb_set(t_font_var *v, t_image *img, t_char chr)
{
	rgb_color_set(v, img, chr);
	(img->img)[v->x + 2 + (v->y * (img->x * 4))]  = ((v->opacity -\
	v->o_opacity_r) * v->R + (1 - (v->opacity - v->o_opacity_r)) * v->BGR);
	(img->img)[v->x + 1 + (v->y * (img->x * 4))]  = ((v->opacity -\
	v->o_opacity_r) * v->G + (1 - (v->opacity - v->o_opacity_r)) * v->BGG);
	(img->img)[v->x + 0 + (v->y * (img->x * 4))]  = ((v->opacity -\
	v->o_opacity_r) * v->B + (1 - (v->opacity - v->o_opacity_r)) * v->BGB);
}

void			draw_font(t_char chr, t_image *img, int o_x, int o_y, t_uint c)
{
	t_font_var var;

	if (chr.x == 0 || chr.y == 0)
		return;
	font_var_init(&var, c, o_x, o_y);
	while (var.y < o_y + chr.y)
	{
		var.x = o_x * 4;
		while (var.x < (o_x + chr.x) * 4)
		{
			if((var.x > 0 && var.y > 0) && (var.x + (var.y * img->x)) < \
			(img->x * img->y) && (var.x < (img->x * 4) &&  var.y * img->y))
				if((t_uchar) (chr.data)[var.k + 0] != 2 || \
				(t_uchar) (chr.data)[var.k + 1] != 2 || \
				(t_uchar) (chr.data)[var.k + 2] != 2)
					rgb_set(&var, img, chr);
			var.k += 4;
			var.x += 4;
		}
		(var.y)++;
	}
}
