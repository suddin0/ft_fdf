/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font11_struct_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 00:44:25 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 04:17:46 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_creator.h"

inline static void	pad_left_init(t_f_create_data *fdata)
{
	int i;

	i = 0;
	fdata[i++].pad_left = 10;
	while (i < 96)
	{
		fdata[i].pad_left = 3;
		i++;
	}
}

inline static void	pad_right_init(t_f_create_data *fdata)
{
	int i;

	i = 0;
	fdata[i++].pad_right = 10;
	while (i < 96)
	{
		fdata[i].pad_right = 3;
		i++;
	}
}

inline static void	pad_top_ext(t_f_create_data *fdata)
{
	fdata['+' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata[',' - 32].pad_top = FONT_11_SMALL_SMALL_PAD_TOP;
	fdata['-' - 32].pad_top = FONT_11_SMALL_MIDLE_PAD_TOP;
	fdata['.' - 32].pad_top = FONT_11_SMALL_SMALL_PAD_TOP;
	fdata[':' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata[';' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['<' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['=' - 32].pad_top = FONT_11_SMALL_EQUAL_PAD_TOP;
	fdata['>' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['@' - 32].pad_top = FONT_11_SMALL_AT_PAD_TOP;
	fdata['_' - 32].pad_top = FONT_11_SMALL_UNDER_PAD_TOP;
	fdata['a' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['c' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['e' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['g' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
}

inline static void	pad_top_init(t_f_create_data *fdata)
{
	pad_top_ext(fdata);
	fdata['m' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['n' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['o' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['p' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['q' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['r' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['s' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['u' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['v' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['w' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['x' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['y' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['z' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
	fdata['~' - 32].pad_top = FONT_11_SMALL_PAD_TOP;
}

void				font11_struct_init(t_f_create_data *fdata)
{
	pad_left_init(fdata);
	pad_right_init(fdata);
	pad_top_init(fdata);
}
