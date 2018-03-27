/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 08:02:51 by suddin            #+#    #+#             */
/*   Updated: 2018/03/27 08:08:05 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	k_z(t_root *root)
{
	if (!(root->map))
		return (-1);
	modmatrix(root->map, rotate_z, 0.10);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
			root->prev.o_x, root->prev.o_y);
	usleep(SLEEP_INTER);
	return (0);
}

int	k_a(t_root *root)
{
	if (!(root->map))
		return (-1);
	modmatrix(root->map, rotate_z, -0.10);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
			root->prev.o_x, root->prev.o_y);
	usleep(SLEEP_INTER);
	return (0);
}

int	k_esc(t_root *root)
{
	free_root(root, EXIT_SUCCESS);
	return (0);
}
