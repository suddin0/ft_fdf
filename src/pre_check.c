/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 07:57:57 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 12:38:21 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_dot_fdf(char *str)
{
	if (ft_strcmp(&(str[ft_strlen(str) - 4]), ".fdf") == 0)
		return (1);
	else
		return (0);
}

int	pre_check(int argc, char **argv)
{
	if (argc < 2)
		ft_printf("[-] Error: Not enough argument \n%s", USAGE_MESSAGE);
	else if (argc > 2)
		ft_putstr("[-] Error: Tooo much arguments\n");
	else if (ft_strlen(argv[1]) > NAME_MAX)
		ft_putstr("[-] Error: File name Too long\n");
	else if (is_dot_fdf(argv[1]) == 0)
		ft_putstr("[-] Error: File do not have .fdf extention\n");
	else
		return (1);
	return (0);
}
