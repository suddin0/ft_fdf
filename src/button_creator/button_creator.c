/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 08:19:18 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 03:57:33 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "button_creator.h"

inline static void	name_init(int lim, int jim, char ****file, char **argv)
{
	ft_strcpy((*file)[jim][0], argv[lim]);
	ft_strcpy((*file)[jim][1], argv[lim]);
	ft_strcpy((*file)[jim][2], argv[lim]);
	ft_strcat((*file)[jim][0], "_0.xpm");
	ft_strcat((*file)[jim][1], "_1.xpm");
	ft_strcat((*file)[jim][2], "_2.xpm");
}

int					create_name(char ****file, int argc, char **argv)
{
	int lim;
	int jim;

	lim = 1;
	jim = 0;
	if ((*file = (char ***)malloc(sizeof(char **) * (argc))) == NULL)
		return (-1);
	memset(*file, 0, argc);
	while (lim != argc)
	{
		if (((*file)[jim] = (char **)malloc(sizeof(char *) * 3)) == NULL)
			return (-1);
		if (((*file)[jim][0] = ft_strnew(ft_strlen(argv[lim]) + 7)) == NULL)
			return (-1);
		if (((*file)[jim][1] = ft_strnew(ft_strlen(argv[lim]) + 7)) == NULL)
			return (-1);
		if (((*file)[jim][2] = ft_strnew(ft_strlen(argv[lim]) + 7)) == NULL)
			return (-1);
		name_init(lim, jim, file, argv);
		jim++;
		lim++;
	}
	(*file)[jim] = 0;
	return (1);
}

inline static void	init_ext(t_fle *fle, int i, t_image *ig)
{
	(ig[0]).img_ptr = mlx_xpm_file_to_image(fle->root.mlx,\
			fle->file[i][0], &((ig[0]).x), &((ig[0]).y));
	(ig[1]).img_ptr = mlx_xpm_file_to_image(fle->root.mlx,\
			fle->file[i][1], &((ig[1]).x), &((ig[1]).y));
	(ig[2]).img_ptr = mlx_xpm_file_to_image(fle->root.mlx,\
			fle->file[i][2], &((ig[2]).x), &((ig[2]).y));
}

inline static void	init_image(t_fle *fle, int i, t_button *b, \
		t_b_create_data *dt)
{
	t_image ig[3];

	init_ext(fle, i, ig);
	if (!((ig[0]).img_ptr) || !((ig[1]).img_ptr) || !((ig[2]).img_ptr))
	{
		ft_printf("[-] Error: getting mlx image pointer\n");
		perror("[!] Reason");
		free_file(fle->file, fle->argc);
		exit(-1);
	}
	(ig[0]).img = mlx_get_data_addr((ig[0]).img_ptr, &((ig[0]).bpp),\
			&((ig[0]).sl), &((ig[0]).end));
	(ig[1]).img = mlx_get_data_addr((ig[1]).img_ptr, &((ig[1]).bpp),\
			&((ig[1]).sl), &((ig[1]).end));
	(ig[2]).img = mlx_get_data_addr((ig[2]).img_ptr, &((ig[2]).bpp),\
			&((ig[2]).sl), &((ig[2]).end));
	size_check(fle->file[i][0], (ig[0]).x, (ig[0]).x, BUTTON_SIZE);
	size_check(fle->file[i][1], (ig[1]).x, (ig[1]).x, BUTTON_SIZE);
	size_check(fle->file[i][2], (ig[2]).x, (ig[2]).x, BUTTON_SIZE);
	struct_manage(ig, b, dt, fle->file[i][2]);
	mlx_destroy_image(fle->root.mlx, (ig[0]).img_ptr);
	mlx_destroy_image(fle->root.mlx, (ig[1]).img_ptr);
	mlx_destroy_image(fle->root.mlx, (ig[2]).img_ptr);
}

int					main(int argc, char **argv)
{
	t_fle			fle;
	int				i;
	t_button		b[BUTTON_MAX];
	t_b_create_data	button_data[BUTTON_MAX];

	fle.argc = argc;
	button_data_init(button_data);
	if (file_verif(argc, argv, &(fle.file)) == -1)
		return (-1);
	fle.root.mlx = mlx_init();
	i = 0;
	while (i != argc - 1)
	{
		init_image(&fle, i, b, button_data);
		i++;
	}
	write_struct(b, BUTTON_STRUCT_PATH);
	free_file(fle.file, argc);
	exit(0);
	return (0);
}
