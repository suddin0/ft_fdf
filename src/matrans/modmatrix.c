/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modmatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 08:02:37 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 06:31:05 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	modmatrix(t_map *map, void f(t_point *a, double val), double rot)
{
	int	l;
	int	p;

	l = 0;
	p = 0;
	while (l < map->lines)
	{
		while (p < map->line_sz[l])
		{
			f(&(map->map[l][p]), rot);
			p++;
		}
		p = 0;
		l++;
	}
}
