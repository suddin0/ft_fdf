/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:48:22 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 11:48:49 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_map	*map_malloc(t_image *img)
{
	t_map *map;

	map = NULL;
	map = (t_map *)malloc(sizeof(t_map));
	map->name = NULL;
	map->path = NULL;
	map->img = img;
	map->map = NULL;
	map->line_sz = NULL;
	map->file_sz = 0;
	map->lines = 0;
	map->data = NULL;
	map->next = NULL;
	map->origine_x = ORIGINE_X;
	map->origine_y = ORIGINE_Y;
	map->step = STEP;
	map->color = COLOR(img->img_ptr, 0xFF3399);
	return (map);
}
