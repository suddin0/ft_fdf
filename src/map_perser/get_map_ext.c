/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_ext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:22:25 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 11:44:13 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		gmap_is_space(char c)
{
	if (c == 0x20 || c == 0x9)
		return (1);
	return (0);
}

int		gmap_is_num_hex(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || \
			(c >= 'a' && c <= 'f') || (c == 'X') || (c == 'x'))
		return (1);
	return (0);
}

long	gmap_line_pnt(char *str, long line)
{
	long i;

	i = line;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (i == line && str[i] != 0)
		return (-2);
	if (i == line || str[i] == 0)
		return (0);
	return (i);
}

char	*gmap_name_verif(char *name, t_map **map, t_image *img)
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

char	*gmap_file_verif(char *name, t_map **map, t_image *img)
{
	char	*mp;
	int		fd;
	int		rd;

	mp = NULL;
	fd = -1;
	rd = 0;
	if (!(mp = gmap_name_verif(name, map, img)))
		return (NULL);
	if ((fd = open(name, O_RDONLY)) == -1)
	{
		ft_printf("[-] Error: opening file: %s\n", name);
		free(*map);
		return (NULL);
	}
	if ((rd = read(fd, mp, (*map)->file_sz)) < (*map)->file_sz)
	{
		free(*map);
		ft_printf("[-] Error: reading. Read %d/%d\n", rd, (*map)->file_sz);
		return (NULL);
	}
	close(fd);
	return (mp);
}
