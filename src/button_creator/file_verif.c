/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 00:42:19 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 04:16:44 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_creator.h"

inline static int	print_ext(void)
{
	ft_printf("[-] Error MAX_BUTTON: Too much muttons, maximum limit is %d",\
			BUTTON_MAX);
	return (-1);
}

int					file_check(int argc, char ***argv)
{
	int i;

	i = 0;
	while (i != argc - 1)
	{
		if (is_file(argv[i][0]) <= 0 ||\
				is_file(argv[i][1]) <= 0 || is_file(argv[i][2]) <= 0)
			return (i + 1);
		i++;
	}
	return (0);
}

int					file_verif(int argc, char **argv, char ****file)
{
	int error;

	error = 0;
	if (argc < 2)
	{
		ft_printf("[!] No file was given as arguments\n");
		return (-1);
	}
	if ((argc - 1) > BUTTON_MAX)
		return (print_ext());
	if (create_name(file, argc, argv) != 1)
	{
		ft_printf("[-] Error setting file name in create_name(...) function");
		return (-1);
	}
	if ((error = file_check(argc, *file)) != 0)
	{
		ft_printf("[-] Error files: %s\n", argv[error]);
		free_file(*file, argc);
		return (-1);
	}
	return (0);
}
