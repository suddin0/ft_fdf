/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 07:57:52 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 12:38:57 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_map(t_map *map, int space)
{
	int l;
	int p;
	int num_sz;

	l = 0;
	p = 0;
	num_sz = 0;
	while (l < map->lines)
	{
		while (p < map->line_sz[l])
		{
			num_sz = ft_intlen(map->map[l][p].z);
			if ((space - num_sz) > 0)
				ft_putnchar(' ', space - num_sz);
			ft_putnbr(map->map[l][p].z);
			p++;
		}
		ft_putchar('\n');
		p = 0;
		l++;
	}
}
