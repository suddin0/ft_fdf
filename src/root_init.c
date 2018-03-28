/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:39:19 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 18:41:42 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

inline static t_font	*get_font(char *f_path)
{
	int		fd;
	int		rd;
	t_font	*font;

	fd = -1;
	font = NULL;
	if (!(font = (t_font *)malloc(sizeof(t_font) * (FCHAR_MAX + 1))))
	{
		ft_printf("[-] Error: Could not allocat enough memory for %s", f_path);
		exit(-1);
	}
	fd = open(f_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("[-] Error: opening %s\n", f_path);
		perror("[!] Reason");
		exit(-1);
	}
	if (read(fd, font, sizeof(t_font) * FCHAR_MAX) <= 0)
	{
		ft_printf("[-] Error: read %s\n", f_path);
		exit(-1);
	}
	close(fd);
	return (font);
}

void					root_init(t_root *root, char **argv)
{
	root->mlx = mlx_init();
	root->sz_x = DEF_ROOT_X;
	root->sz_y = DEF_ROOT_Y;
	root->font_24 = get_font(FONT_24_STRUCT_PATH);
	root->font_18 = get_font(FONT_18_STRUCT_PATH);
	root->font_11 = get_font(FONT_11_STRUCT_PATH);
	ft_memset(root->name, 0, NAME_MAX + 5);
	ft_strncpy(root->name, argv[1], strlen(argv[1]) - 4);
	ft_putstr(root->name);
	root->win = mlx_new_window(root->mlx, root->sz_x, root->sz_y, root->name);
	root->prev.img_ptr = NULL;
	root->menu.img_ptr = NULL;
	root->foot.img_ptr = NULL;
}
