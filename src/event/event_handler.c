/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 05:15:01 by suddin            #+#    #+#             */
/*   Updated: 2018/03/30 05:41:16 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		brelease(int key, int x, int y, t_root *root)
{
	int clk;

	clk = root->men.btn_clicked;
	if (clk != -1 && key == MOUSE_LEFT)
	{
		if (root->men.button[clk].type == TP_RADIO)
			return (0);
		draw_button(root->men.button[clk], &(root->menu), ST_DEFAULT);
		mlx_put_image_to_window(root->mlx, root->win, root->menu.img_ptr, \
				root->menu.o_x, root->menu.o_y);
		root->men.btn_clicked = -1;
		root->men.button[clk].stat = ST_DEFAULT;
	}
	mlx_loop_hook(root->mlx, NULL, NULL);
	key = 0;
	(void)x;
	(void)y;
	return (1);
}

int		draw_win(t_root *root)
{
	mlx_put_image_to_window(root->mlx, root->win, \
			root->menu.img_ptr, root->menu.o_x, root->menu.o_y);
	mlx_put_image_to_window(root->mlx, root->win, \
			root->prev.img_ptr, root->prev.o_x, root->prev.o_y);
	mlx_put_image_to_window(root->mlx, root->win, \
			root->foot.img_ptr, root->foot.o_x, root->foot.o_y);
	return (1);
}

int		destroy(t_root *root)
{
	int i;

	i = 0;
	mlx_destroy_image(root->mlx, root->prev.img_ptr);
	mlx_destroy_window(root->mlx, root->win);
	free_map(root->map);
	while (i != root->men.list.total_map)
		free(root->men.list.map_name[i++]);
	free(root->men.list.map_name);
	free(root->font_24);
	free(root->font_18);
	free(root->font_11);
	ft_printf("[!] Exiting the programme\n");
	exit(EXIT_SUCCESS);
	return (0);
}

void	event_handler(t_root *root)
{
	mlx_hook(root->win, PMOTION, PMOTION_M, &pmotion, root);
	mlx_hook(root->win, KPRESS, KPRESS_M, &kpress, root);
	mlx_hook(root->win, KRELEASE, KRELEASE_M, &krelease, root);
	mlx_hook(root->win, VISIBL, VISIBL_M, &draw_win, root);
	mlx_hook(root->win, BPRESS, BPRESS_M, &bpress, root);
	mlx_hook(root->win, BRELEASE, BRELEASE_M, &brelease, root);
	mlx_hook(root->win, DESTROY, DESTROY_M, &destroy, root);
	mlx_loop(root->mlx);
}
