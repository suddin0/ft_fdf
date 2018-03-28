/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 04:47:32 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 05:14:04 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void				name_copy(char *dest, char *src)
{
	int len;
	int start;
	int end;
	int i;

	if (!dest || !src)
		return ;
	start = 0;
	i = 0;
	len = ft_strlen(src);
	while (len > 0)
	{
		if (src[len] == '/')
			break ;
		len--;
	}
	start = (len == 0) ? len : len + 1;
	end = ft_strlen(&(src[start])) - 6;
	while (i != end && src[start])
		dest[i++] = src[start++];
	dest[i] = 0;
}

inline static void	name_copy_font(char *dest, char *src)
{
	int	len;
	int	start;
	int	end;
	int	i;

	if (!dest || !src)
		return ;
	start = 0;
	i = 0;
	len = ft_strlen(src);
	while (len > 0)
	{
		if (src[len] == '/')
			break ;
		len--;
	}
	start = (len == 0) ? len : len + 1;
	end = ft_strlen(&(src[start])) - 4;
	while (i != end && src[start])
		dest[i++] = src[start++];
	dest[i] = 0;
}

int					name_to_num(char *name)
{
	char tmp[100];

	name_copy_font(tmp, name);
	return (ft_atoi(tmp));
}
