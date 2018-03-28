/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_point_ext.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:22:27 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 12:22:37 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	trans_x(t_map *a, double v)
{
	a->origine_x += v;
}

void	trans_y(t_map *a, double v)
{
	a->origine_y += v;
}

void	zoom(t_map *a, int v)
{
	if (a->step <= 0 && v < 0)
	{
		ft_printf("[!] Reached minimum zoom, cannot unzoom %d o_x[%d] o_y[%d]\
				step[%d]\n", v, a->origine_x, a->origine_y, a->step);
		return ;
	}
	a->step += v;
	a->origine_x += -v;
	a->origine_y += -v;
}
