/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 08:03:42 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 10:04:55 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

inline static	int		is_space(char c)
{
	if (c == 0x20 || c == 0x9)
		return (1);
	return (0);
}

inline static	int		is_num_hex(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || \
			(c >= 'a' && c <= 'f') || (c == 'X') || (c == 'x'))
		return (1);
	return (0);
}


inline static	long	line_pnt(char *str, long line)
{
	long i;

	i = line;
	if (!str)
		return (0);
	while(str[i] && str[i] != '\n')
		i++;
	if (i == line && str[i] != 0)
		return (-2);
	if (i == line || str[i] == 0)
		return (0);
	return (i);
}


inline static	char	*name_verif(char *name, t_map **map, t_image *img)
{
	char *mp;
	if (is_file(name) == 1)
	{
		(*map) = map_malloc(img);
		(*map)->file_sz = file_size(name);
		(*map)->name = ft_strdup(name);
		if (!(mp = ft_strnew((*map)->file_sz)))
		{
			ft_printf("[-] Error: allocating %d bytes\n", (*map)->file_sz);
			return (NULL);
		}
		return (mp);
	}
	else
	{
		if (is_dir(name) == 1)
			ft_printf("[-] Error: %s is a directory and not a file\n", name);
		else
			ft_printf("[-] Error: not a valid file\n");
		return (NULL);
	}
	return (NULL);
}

inline static	char	*file_verif(char *name, t_map **map, t_image *img)
{
	char	*mp;
	int		fd;
	int		rd;

	mp = NULL;
	fd = -1;
	rd = 0;
	if (!(mp = name_verif(name,map, img)))
		return (NULL);
	if ((fd = open(name, O_RDONLY)) == -1)
	{
		ft_printf("[-] Error: opening file: %s\n", name);
		free(*map);
		return (NULL);
	}
	if ((rd = read(fd, mp,(*map)->file_sz)) < (*map)->file_sz)
	{
		free(*map);
		ft_printf("[-] Error: reading. Read %d/%d\n", rd , (*map)->file_sz);
		return (NULL);
	}
	close(fd);
	return (mp);
}

inline static t_m_data *data_set(t_m_data **data, int flag, t_map *map)
{
	t_m_data *dt;

	dt = NULL;
	if (flag == 0)
	{
		dt = (t_m_data *) malloc(sizeof(t_m_data));
		dt->next = NULL;
		dt->prev = NULL;
		return (dt);
	}
	else if (flag == 1)
	{
		data[0]->next = map->data;
		data[1]  = data[0];
		map->data = data[0];
		if (data[0]->next)
			data[0]->next->prev = data[1];
		while (data[0])
			data[0] = data[0]->next;
	}
	return (NULL);
}

inline static t_map *map_eror_(char *mp, t_map *map, t_m_data *data, int flag)
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
			printf("[-] Error: map contains %d lines\n", map->lines);
		free(mp);
		free_map(map);
	}
	return (NULL);
}

inline static void var_init(long *line, char **mp, t_map **map, t_m_data **data)
{
	line[0] = 0;
	line[1] = 0;
	*mp = NULL;
	*map = NULL;
	data[0] = NULL;
	data[1] = NULL;
}

inline static t_map *while_ext(t_map *map, t_m_data **data, char *mp, long *line)
{
	while((line[1] = line_pnt(mp, line[0])) != 0)
	{
		if(line[1] == -2)
		{
			line[0]++;
			continue;
		}
		data[0] = data_set(NULL, 0, NULL);
		if (((data[0])->row = count_num(mp, line[0], line[1])) <= 0)
			return (map_eror_(mp, map, data[0], 0));
		(data[0])->col = map->lines;
		if (((data[0])->data = get_num(mp, line[0], line[1], (data[0])->row)) == NULL)
			return (map_eror_(mp, map, data[0], 1));
		data[0] = data_set(data, 1, map);
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

	var_init(line, &mp, &map, data);
	if (!(mp = file_verif(name, &map, img)))
		return (NULL);
	if (while_ext(map, data, mp, line) == NULL)
		return (NULL);
	if (map->lines <= 0)
		return (map_eror_(mp, map, data[0], 2));
	data_to_array(map);
	free(mp);
	return (map);
}
