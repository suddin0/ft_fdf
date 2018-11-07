/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_func_ext_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:13:27 by suddin            #+#    #+#             */
/*   Updated: 2018/03/30 01:48:32 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	b4(t_root *root)
{
	CLEAR(root->prev);
	if (root->men.mvment == MV_TRANS)
		k_down(root);
	else if (root->men.mvment == MV_ROTAT)
		k_s(root);
	mlx_loop_hook(root->mlx, b4, root);
	return (0);
}

int	b10(t_root *root)
{
	char *name_tmp;

	name_tmp = ft_strdup(root->map->name);
	free_map(root->map);
	if ((root->map = get_map(name_tmp, &(root->prev))) == NULL)
		ft_printf("[-] Error: getting file (b9: button 9 function:reload map)");
	free(name_tmp);
	CLEAR(root->prev);
	draw_map(root, root->mlx, root->map);
	mlx_put_image_to_window(root->mlx, root->win, root->prev.img_ptr, \
			root->prev.o_x, root->prev.o_y);
	return (0);
}

int	b11(t_root *root)
{
	(void)root;
	return (0);
}

int	b12(t_root *root)
{
	if (root->men.button[12].stat == ST_ACTIVE)
		return (0);
	draw_button(root->men.button[13], root->men.img, ST_DEFAULT);
	draw_button(root->men.button[12], root->men.img, ST_ACTIVE);
	root->men.button[12].stat = ST_ACTIVE;
	root->men.button[13].stat = ST_DEFAULT;
	root->men.mvment = MV_TRANS;
	mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
			root->menu.o_x, root->menu.o_y);
	return (0);
}

int	b13(t_root *root)
{
	if (root->men.button[13].stat == ST_ACTIVE)
		return (0);
	draw_button(root->men.button[12], root->men.img, ST_DEFAULT);
	draw_button(root->men.button[13], root->men.img, ST_ACTIVE);
	root->men.button[13].stat = ST_ACTIVE;
	root->men.button[12].stat = ST_DEFAULT;
	root->men.mvment = MV_ROTAT;
	mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
			root->menu.o_x, root->menu.o_y);
	return (0);
}
