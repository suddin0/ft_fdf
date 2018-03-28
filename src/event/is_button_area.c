/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_button_area.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 05:39:27 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 05:39:49 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_button_area(t_button *b, int x, int y)
{
	int i;

	i = 0;
	while (i < BUTTON_MAX)
	{
		if (x > (b[i]).o_x && x < (b[i]).o_x + (b[i]).x && \
				y > (b[i]).o_y && y < (b[i]).o_y + (b[i]).y)
			return (i);
		i++;
	}
	return (-1);
}

int	is_list_area(t_map_list list, int x, int y)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (j < list.total_map)
	{
		if (x > (list.o_x * i) && x < (list.o_x) + MENU_X && \
				y > (list.o_y * i) && y < (list.o_y) + (list.height * i))
			return (i - 1);
		i++;
		j++;
	}
	return (-1);
}
