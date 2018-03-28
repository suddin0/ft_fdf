/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 05:55:23 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 09:06:24 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_list(t_map_list *list)
{
	int i;

	i = 0;
	while (i < list->total_map)
		free(list->map_name[i++]);
	free(list->map_name);
	list->map_name = NULL;
}
