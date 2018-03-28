/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_data_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 00:13:22 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 04:10:28 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_creator.h"

void	button_data_init(t_b_create_data *b)
{
	strcpy(((b[0]).name), "controle");
	strcpy(((b[1]).name), "maps");
	strcpy(((b[2]).name), "info");
	strcpy(((b[3]).name), "left");
	strcpy(((b[4]).name), "down");
	strcpy(((b[5]).name), "right");
	strcpy(((b[6]).name), "up");
	strcpy(((b[7]).name), "uzoom");
	strcpy(((b[8]).name), "zoom");
	strcpy(((b[9]).name), "reload");
	strcpy(((b[10]).name), "face");
	strcpy(((b[11]).name), "help");
	strcpy(((b[12]).name), "trans");
	strcpy(((b[13]).name), "rotate");
	init_bid(b);
	init_btype(b);
	init_bstat(b);
	init_borigine(b);
}

void	init_bid(t_b_create_data *b)
{
	(b[0]).id = 0;
	(b[1]).id = 1;
	(b[2]).id = 2;
	(b[3]).id = 3;
	(b[4]).id = 4;
	(b[5]).id = 5;
	(b[6]).id = 6;
	(b[7]).id = 7;
	(b[8]).id = 8;
	(b[9]).id = 9;
	(b[10]).id = 10;
	(b[11]).id = 11;
	(b[12]).id = 12;
	(b[13]).id = 13;
}

void	init_btype(t_b_create_data *b)
{
	(b[0]).type = TP_RADIO;
	(b[1]).type = TP_RADIO;
	(b[2]).type = TP_RADIO;
	(b[3]).type = TP_NORMAL;
	(b[4]).type = TP_NORMAL;
	(b[5]).type = TP_NORMAL;
	(b[6]).type = TP_NORMAL;
	(b[7]).type = TP_NORMAL;
	(b[8]).type = TP_NORMAL;
	(b[9]).type = TP_NORMAL;
	(b[10]).type = TP_NORMAL;
	(b[11]).type = TP_NORMAL;
	(b[12]).type = TP_RADIO;
	(b[13]).type = TP_RADIO;
}

void	init_bstat(t_b_create_data *b)
{
	(b[0]).stat = 2;
	(b[1]).stat = 0;
	(b[2]).stat = 0;
	(b[3]).stat = 0;
	(b[4]).stat = 0;
	(b[5]).stat = 0;
	(b[6]).stat = 0;
	(b[7]).stat = 0;
	(b[8]).stat = 0;
	(b[9]).stat = 0;
	(b[10]).stat = 0;
	(b[11]).stat = 0;
	(b[12]).stat = 2;
	(b[13]).stat = 0;
	(b[0]).o_x = OX_MAIN;
	(b[1]).o_x = OX_MAP;
	(b[2]).o_x = OX_INFO;
	(b[3]).o_x = OX_LEFT;
	(b[4]).o_x = OX_DOWN;
	(b[5]).o_x = OX_RIGHT;
	(b[6]).o_x = OX_UP;
	(b[7]).o_x = OX_UZOOM;
	(b[8]).o_x = OX_ZOOM;
	(b[9]).o_x = OX_RELOAD;
	(b[10]).o_x = OX_FACE;
}

void	init_borigine(t_b_create_data *b)
{
	(b[11]).o_x = OX_HELP;
	(b[12]).o_x = OX_TRANS;
	(b[13]).o_x = OX_ROTATE;
	(b[0]).o_y = OY_MAIN;
	(b[1]).o_y = OY_MAP;
	(b[2]).o_y = OY_INFO;
	(b[3]).o_y = OY_LEFT;
	(b[4]).o_y = OY_DOWN;
	(b[5]).o_y = OY_RIGHT;
	(b[6]).o_y = OY_UP;
	(b[7]).o_y = OY_UZOOM;
	(b[8]).o_y = OY_ZOOM;
	(b[9]).o_y = OY_RELOAD;
	(b[10]).o_y = OY_FACE;
	(b[11]).o_y = OY_HELP;
	(b[12]).o_y = OY_TRANS;
	(b[13]).o_y = OY_ROTATE;
}
