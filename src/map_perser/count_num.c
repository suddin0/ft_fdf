/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 06:37:49 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 07:16:33 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

inline static int	is_space(char c)
{
	if (c == 0x20 || c == 0x9)
		return (1);
	return (0);
}

inline static int	is_num_hex(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || \
			(c >= 'a' && c <= 'f') || (c == 'X') || (c == 'x'))
		return (1);
	return (0);
}

inline static void	count_ext_one(int *i, int *count, int *signe)
{
	if (*i == 0)
		*count += 1;
	*i = 1;
	*signe = 0;
}

inline static int	count_ext_two(int flag, int *i, int o_line)
{
	if (flag == 0)
		ft_printf("[-] Error: unsupported value at %ld\n", o_line);
	else if (flag == 1)
	{
		i[0] = 0;
		i[1] = 0;
		i[2] = 0;
	}
	return (-1);
}

int					count_num(char *str, long o_line, long n_line)
{
	int	i[4];

	count_ext_two(1, i, 0);
	while (str[o_line] && (o_line != n_line))
	{
		if (is_space(str[o_line]) && !i[1])
			i[0] = 0;
		else if (ft_isdigit(str[o_line]))
			count_ext_one(&(i[0]), &(i[2]), &(i[1]));
		else if (((str[o_line] == '+') || (str[o_line] == '-')) && \
				((o_line + 1) != n_line))
			i[1] = 1;
		else if ((str[o_line] == ',') && ((o_line + 1) < n_line))
		{
			o_line++;
			while (str[o_line] && is_num_hex(str[o_line]) && o_line < n_line)
				o_line++;
			continue ;
		}
		else
			return (count_ext_two(0, NULL, o_line));
		o_line++;
	}
	return (i[2]);
}
