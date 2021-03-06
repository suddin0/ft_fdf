/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 07:40:28 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 12:25:40 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	put_color(t_image *img, int x, int y, int col)
{
	x = (x >= img->x || x < 0) ? 0 : x;
	y = (y >= img->y || y < 0) ? 0 : y;
	if (x > 0 && y > 0 && (x + (y * img->x)) < img->x * img->y)
		((int *)img->img)[x + (y * img->x)] = col;
}

void	set_color(char *img, unsigned int len, int col)
{
	if (len > 8)
		while (len > 8)
		{
			((int *)img)[len - 1] = col;
			((int *)img)[len - 2] = col;
			((int *)img)[len - 3] = col;
			((int *)img)[len - 4] = col;
			((int *)img)[len - 5] = col;
			((int *)img)[len - 6] = col;
			((int *)img)[len - 7] = col;
			((int *)img)[len - 8] = col;
			len -= 8;
		}
	while (len > 0)
		((int *)img)[len--] = col;
}
