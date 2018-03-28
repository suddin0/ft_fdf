/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font_struct_manage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 04:43:06 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 04:43:10 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_creator.h"

void	font_struct_manage(t_font *font, t_f_create_data *fdata)
{
	int i;

	i = 0;
	while (i < 96)
	{
		font[i].pad_top = fdata[i].pad_top;
		font[i].pad_left = fdata[i].pad_left;
		font[i].pad_right = fdata[i].pad_right;
		i++;
	}
}
