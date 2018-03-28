/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font_18_creator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 02:16:24 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 04:40:42 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "button_creator.h"

inline static void	char_init(t_char *chr)
{
	chr->ascii = 0;
	chr->data[0] = 0;
	chr->x = 0;
	chr->y = 0;
	chr->pad_top = 0;
	chr->pad_left = 0;
	chr->pad_right = 0;
}

inline static void	imgptr_err(char **argv, int flag, int i)
{
	if (flag == 0)
	{
		printf("[-] Error: getting mlx image pointer for %s\n", argv[i]);
		perror("[!] Reason");
	}
	else if (flag == 1)
	{
		printf("[-] Error: getting mlx data pointer for [%s]\n", argv[i]);
		perror("[!] Reason");
	}
	exit(-1);
}

inline static void	while_ext(char **argv, t_char *chr, t_root *root, int argc)
{
	t_image	ig;
	int		i;
	int		ch_count;

	i = 1;
	ch_count = 1;
	while (i != argc)
	{
		ig.img_ptr = mlx_xpm_file_to_image(root->mlx, argv[i], &(ig.x), \
				&(ig.y));
		if (!(ig.img_ptr))
			imgptr_err(argv, 0, i);
		ig.img = mlx_get_data_addr(ig.img_ptr, &(ig.bpp), &(ig.sl), &(ig.end));
		if (!(ig.img))
			imgptr_err(argv, 1, i);
		char_init(&(chr[ch_count]));
		size_check(argv[i], ig.x, ig.x, CHAR_SIZE_28);
		chr[ch_count].x = ig.x;
		chr[ch_count].y = ig.y;
		chr[ch_count].ascii = name_to_num(argv[i]);
		ft_memcpy(chr[ch_count].data, ig.img, (ig.x * ig.y) * 4);
		mlx_destroy_image(root->mlx, ig.img_ptr);
		i++;
		ch_count++;
	}
}

int					main(int argc, char **argv)
{
	t_root			root;
	t_char			chr[FCHAR_MAX];
	t_f_create_data	fdata[FCHAR_MAX];

	if (font_verif(argc, argv) == -1)
		return (-1);
	root.mlx = mlx_init();
	font18_struct_init(fdata);
	char_init(&(chr[0]));
	chr[0].ascii = 32;
	while_ext(argv, chr, &root, argc);
	font_struct_manage(chr, fdata);
	write_struct_font(chr, FONT_18_STRUCT_PATH);
	exit(0);
	return (0);
}
