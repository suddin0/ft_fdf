/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 07:45:21 by suddin            #+#    #+#             */
/*   Updated: 2018/03/27 07:45:23 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

inline static void	free_data(t_m_data *data)
{
	t_m_data *tmp;

	tmp = data;
	while (tmp)
	{
		free(data->data);
		data = data->next;
		free(tmp);
		tmp = data;
	}
	data = NULL;
}

inline static void	free_point(t_map *map, t_point **point)
{
	int line;

	line = 0;
	if (!(point) || !(*point))
		return;
	while (line < map->lines)
	{
		free(point[line]);
		point[line] = NULL;
		line++;
	}
	free(point);
	point = NULL;

}

void				free_map(t_map *map)
{
	t_map *tmp_map;

	tmp_map = map;
	if (!map)
		return ;
	if (map->name)
		free(map->name);
	while (tmp_map)
	{
		free_point(tmp_map, tmp_map->map);
		free(tmp_map->line_sz);
		tmp_map->line_sz = NULL;
		if (tmp_map->data)
			free_data(tmp_map->data);
		map = map->next;
		free(tmp_map);
		tmp_map = NULL;
		tmp_map = map;
	}
	map = NULL;
}
