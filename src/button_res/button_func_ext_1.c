/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_func_ext_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:12:01 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 12:12:22 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	b5(t_root *root)
{
	CLEAR(root->prev);
	if (root->men.mvment == MV_TRANS)
		k_right(root);
	else if (root->men.mvment == MV_ROTAT)
		k_u(root);
	mlx_loop_hook(root->mlx, b5, root);
	return (0);
}

int	b6(t_root *root)
{
	CLEAR(root->prev);
	if (root->men.mvment == MV_TRANS)
		k_up(root);
	else if (root->men.mvment == MV_ROTAT)
		k_x(root);
	mlx_loop_hook(root->mlx, b6, root);
	return (0);
}

int	b7(t_root *root)
{
	CLEAR(root->prev);
	if (root->men.mvment == MV_TRANS)
		k_minus(root);
	else if (root->men.mvment == MV_ROTAT)
		k_z(root);
	mlx_loop_hook(root->mlx, b7, root);
	usleep(25000);
	return (0);
}

int	b8(t_root *root)
{
	CLEAR(root->prev);
	if (root->men.mvment == MV_TRANS)
		k_plus(root);
	else if (root->men.mvment == MV_ROTAT)
		k_a(root);
	mlx_loop_hook(root->mlx, b8, root);
	usleep(25000);
	return (0);
}

int	b9(t_root *root)
{
	char *name_tmp;

	name_tmp = ft_strdup(root->map->name);
	free_map(root->map);
	if ((root->map = get_map(name_tmp, &(root->prev))) == NULL)
		ft_printf("[-] Error: getting file (b9: button 9 function, load map)");
	free(name_tmp);
	CLEAR(root->prev);
	modmatrix(root->map, rotate_x, 120);
	modmatrix(root->map, rotate_y, 120);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
			root->prev.o_x, root->prev.o_y);
	return (0);
}
