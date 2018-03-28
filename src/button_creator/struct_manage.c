/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 04:54:34 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 04:55:55 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_creator.h"

void	struct_manage(t_image *ig, t_button *b, \
		t_b_create_data *bdata, char *fn)
{
	int		i;
	char	name[100];

	i = 0;
	name_copy(name, fn);
	while (i < BUTTON_MAX)
	{
		if (ft_strcmp(name, bdata[i].name) == 0)
		{
			b[i].type = bdata[i].type;
			b[i].stat = bdata[i].stat;
			ft_memcpy((b[i].view)[0], (ig[0]).img, ((ig[0]).x * (ig[0]).y) * 4);
			ft_memcpy((b[i].view)[1], (ig[1]).img, ((ig[1]).x * (ig[1]).y) * 4);
			ft_memcpy((b[i].view)[2], (ig[2]).img, ((ig[2]).x * (ig[2]).y) * 4);
			name_copy((b[i]).name, name);
			b[i].x = (ig[0]).x;
			b[i].y = (ig[0]).y;
			b[i].o_x = bdata[i].o_x;
			b[i].o_y = bdata[i].o_y;
			break ;
		}
		i++;
	}
}
