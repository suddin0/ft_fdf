/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 07:43:38 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 12:27:23 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

inline static void	line_var_init(t_line_var *var, t_map *map, \
		t_point o, t_point n)
{
	o.x = map->origine_x + (map->step * o.x);
	o.y = map->origine_y + (map->step * o.y);
	n.x = map->origine_x + (map->step * n.x);
	n.y = map->origine_y + (map->step * n.y);
	var->x0 = (int)o.x;
	var->y0 = (int)o.y;
	var->x1 = (int)n.x;
	var->y1 = (int)n.y;
	var->dx = abs(var->x1 - var->x0);
	var->sx = var->x0 < var->x1 ? 1 : -1;
	var->dy = abs(var->y1 - var->y0);
	var->sy = var->y0 < var->y1 ? 1 : -1;
	var->err = (var->dx > var->dy ? var->dx : -(var->dy)) / 2;
	var->e2 = 0;
}

void				draw_line(t_map *map, t_point o, t_point n, int color)
{
	t_line_var var;

	line_var_init(&var, map, o, n);
	while (1)
	{
		put_color(map->img, var.x0, var.y0, color);
		if (var.x0 == var.x1 && var.y0 == var.y1)
			break ;
		var.e2 = var.err;
		if (var.e2 > -(var.dx))
		{
			var.err -= var.dy;
			var.x0 += var.sx;
		}
		if (var.e2 < var.dy)
		{
			var.err += var.dx;
			var.y0 += var.sy;
		}
	}
}
