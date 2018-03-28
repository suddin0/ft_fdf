/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 08:03:42 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 18:37:46 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

inline static t_m_data	*gmap_data_set(t_m_data **data, int flag, t_map *map)
{
	t_m_data *dt;

	dt = NULL;
	if (flag == 0)
	{
		dt = (t_m_data *)malloc(sizeof(t_m_data));
		dt->next = NULL;
		dt->prev = NULL;
		return (dt);
	}
	else if (flag == 1)
	{
		data[0]->next = map->data;
		data[1] = data[0];
		map->data = data[0];
		if (data[0]->next)
			data[0]->next->prev = data[1];
		while (data[0])
			data[0] = data[0]->next;
	}
	return (NULL);
}

inline static	t_map	*gmap_map_eror_(char *mp, t_map *map, \
		t_m_data *data, int flag)
{
	if (flag == 0)
	{
		ft_printf("[-] Error: Invalid map (line %d)\n", map->lines + 1);
		free(mp);
		free(data);
		free_map(map);
	}
	else if (flag == 1 || flag == 2)
	{
		if (flag == 2)
			ft_printf("[-] Error: map contains %d lines\n", map->lines);
		free(mp);
		free_map(map);
	}
	return (NULL);
}

inline static	void	gmap_var_init(long *line, char **mp, \
		t_map **map, t_m_data **data)
{
	line[0] = 0;
	line[1] = 0;
	*mp = NULL;
	*map = NULL;
	data[0] = NULL;
	data[1] = NULL;
}

inline static	t_map	*while_ext(t_map *map, t_m_data **data, \
		char *mp, long *line)
{
	while ((line[1] = gmap_line_pnt(mp, line[0])) != 0)
	{
		if (line[1] == -2)
		{
			line[0]++;
			continue;
		}
		data[0] = gmap_data_set(NULL, 0, NULL);
		if (((data[0])->row = count_num(mp, line[0], line[1])) <= 0)
			return (gmap_map_eror_(mp, map, data[0], 0));
		(data[0])->col = map->lines;
		if (((data[0])->data = get_num(mp, line[0], line[1], \
						(data[0])->row)) == NULL)
			return (gmap_map_eror_(mp, map, data[0], 1));
		data[0] = gmap_data_set(data, 1, map);
		map->lines++;
		line[0] = line[1] + 1;
	}
	return (map);
}

t_map					*get_map(char *name, t_image *img)
{
	t_map		*map;
	t_m_data	*data[2];
	char		*mp;
	long		line[2];

	gmap_var_init(line, &mp, &map, data);
	if (!(mp = gmap_file_verif(name, &map, img)))
		return (NULL);
	if (while_ext(map, data, mp, line) == NULL)
		return (NULL);
	if (map->lines <= 0)
		return (gmap_map_eror_(mp, map, data[0], 2));
	data_to_array(map);
	free(mp);
	return (map);
}
