/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 07:18:05 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 07:57:37 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

inline static	t_m_data	*init_ext(t_map *map, int *i, float *x, float *y)
{
	map->line_sz = (long *)malloc(sizeof(long) * map->lines);
	map->map = (t_point **)malloc(sizeof(t_point *) * (map->lines + 1));
	ft_memset(map->map, 0, map->lines + 1);
	*i = 0;
	*x = 0;
	*y = 0;
	return (map->data);
}

inline static	int			point_init(t_point *pnt, float *x, \
		float *y, long int data)
{
	pnt->x = *x;
	pnt->y = *y;
	pnt->z = (data == 0) ? 0.10 : data;
	(*x)++;
	return (1);
}

t_point						**data_to_array(t_map *map)
{
	t_m_data	*data;
	int			i;
	float		x;
	float		y;

	if (!map)
		return (NULL);
	data = init_ext(map, &i, &x, &y);
	while (data && data->next)
		data = data->next;
	while (data)
	{
		i = 0;
		map->line_sz[data->col] = data->row;
		map->map[data->col] = (t_point *)malloc(sizeof(t_point) * data->row);
		while (i != data->row)
			i += point_init(&((map->map)[data->col][i]), \
					&x, &y, (data->data)[i]);
		y++;
		x = 0;
		data = data->prev;
	}
	return (map->map);
}
