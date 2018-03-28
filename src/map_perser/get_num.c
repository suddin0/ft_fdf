/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:49:10 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 18:38:05 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

inline static	int	is_space(char c)
{
	if (c == 0x20 || c == 0x9)
		return (1);
	return (0);
}

inline static int	get_comma(char *str, long *o_line, int n_line)
{
	if (str[*o_line] == ',')
	{
		while (str[*o_line] && !is_space(str[*o_line]) && *o_line < n_line)
			(*o_line)++;
		return (1);
	}
	return (0);
}

inline static	int	nlineeq(char *str, long *o_line, int n_line, long **num)
{
	int ret;

	ret = 0;
	if ((str[*o_line] == '-') || (str[*o_line] == '+'))
	{
		if (((*o_line + 1) == n_line))
		{
			ft_printf("[-] Error: get_number: bad map at [%ld][%c]\n", \
					*o_line, str[*o_line]);
			free(*num);
			*num = NULL;
			return (-1);
		}
		if (str[*o_line] == '-')
			ret = 1;
		(*o_line) += 1;
	}
	return (ret);
}

long				*get_num(char *str, long o_line, int n_line, int dig)
{
	long	i;
	long	neg;
	long	*num;

	i = 0;
	neg = 0;
	num = (long *)malloc(sizeof(long) * (dig + 1));
	while (str[o_line] && (o_line < n_line))
	{
		num[i] = 0;
		while (is_space(str[o_line]) && (o_line != n_line))
			o_line += 1;
		if (get_comma(str, &o_line, n_line) == 1)
			continue;
		if ((neg = nlineeq(str, &o_line, n_line, &num)) == -1)
			return (NULL);
		while (str[o_line] && ft_isdigit(str[o_line]) && o_line < n_line)
			num[i] = (num[i] * 10L) + (str[o_line++] - 48);
		if (neg)
			num[i] *= -1;
		i++;
		neg = 0;
	}
	return (num);
}
