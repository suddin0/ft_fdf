/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 07:59:42 by suddin            #+#    #+#             */
/*   Updated: 2018/03/27 08:00:32 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	k_up(t_root *root)
{
	if (!(root->map))
		return (-1);
	trans_y(root->map, -10.0);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
			root->prev.o_x, root->prev.o_y);
	usleep(SLEEP_INTER);
	return (0);
}

int	k_down(t_root *root)
{
	if (!(root->map))
		return (-1);
	trans_y(root->map, 10.0);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
			root->prev.o_x, root->prev.o_y);
	usleep(SLEEP_INTER);
	return (0);
}

int	k_right(t_root *root)
{
	if (!(root->map))
		return (-1);
	trans_x(root->map, 10.0);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
			root->prev.o_x, root->prev.o_y);
	usleep(SLEEP_INTER);
	return (0);
}

int	k_left(t_root *root)
{
	if(!(root->map))
		return (-1);
	trans_x(root->map, -10.0);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
			root->prev.o_x, root->prev.o_y);
	usleep(SLEEP_INTER);
	return (0);
}

int	k_plus(t_root *root)
{
	if (!(root->map))
		return (-1);
	zoom(root->map, 2);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
			root->prev.o_x, root->prev.o_y);
	usleep(SLEEP_INTER);
	return (0);
}
