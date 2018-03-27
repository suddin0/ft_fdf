/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 07:39:57 by suddin            #+#    #+#             */
/*   Updated: 2018/03/27 07:39:58 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


inline static char *text_itoa(int num)
{
	static char str[22];
	int k;
	long n;
	char sign;

	k = 0;
	sign = 0;
	memset(str, 0, 22);
	if(num == 0 && (str[k] = '0') > 0)
		return (str);
	else if(num < 0)
		sign = 1;
	n = (num < 0) ? -num : num;
	while(n != 0)
	{
		str[k] = (n % 10) + 48;
		n /= 10;
		k++;
	}
	if(sign == 1)
		str[k] = '-';
	ft_strrev(str);
	return (str);
}


int put_text(t_root *root, t_image *img, char *str, ...)
{
	int i;
	int o_[4];
	t_font *font;
	va_list args;
	int RGBA;

	va_start(args, str);
	i = 0;
	o_[0] = va_arg(args, int);
	o_[1] = va_arg(args, int);
	font  = va_arg(args, t_font *);
	RGBA = va_arg(args, int);
	if(!str)
		return 0;
	while (str[i])
	{
		if(!ft_isprint(str[i]))
			str[i] = 127;
		draw_font(font[str[i] - 32], img, o_[0] + font[str[i] - 32].pad_left,\
		o_[1] + font[str[i] - 32].pad_top, RGBA);
		o_[0] +=  font[str[i] - 32].x + font[str[i] - 32].pad_right;
		i++;
	}
	va_end(args);
	return (o_[0]);
}

void printf_text(t_root *root, t_image *img, char *str, ...)
{
	int i;
	int RGBA;
	int o_[5];
	t_font *font;
	va_list args;

	va_start(args, str);
	ft_memset(o_, 0, 5);
	i = 0;
	font = root->font_18;
	RGBA = COL_WHITE;
	o_[0] = 10;
	o_[1] = 10;

	while (str[i])
	{
		if(!ft_isprint(str[i]))
			str[i] = 127;
		if(str[i] == '%')
		{
			if(str[i + 1] && str[i + 1] == 'C')
			{
				RGBA = va_arg(args, int);
				i += 2;
				continue;
			}
			if(str[i + 1] && str[i + 1] == 's')
			{
				o_[0] = put_text(root, img, va_arg(args, char *), o_[0], o_[1], font, RGBA);
				i += 2;
				continue;
			}
			if(str[i + 1] && str[i + 1] == 'd')
			{
				o_[0] = put_text(root, img, text_itoa(va_arg(args, int)), o_[0], o_[1], font, RGBA);
				i += 2;
				continue;
			}
			if(str[i + 1] && str[i + 1] == 'x')
			{
				o_[0] = va_arg(args, int);
				i += 2;
				continue;
			}
			if(str[i + 1] && str[i + 1] == 'y')
			{
				o_[1] = va_arg(args, int);
				i += 2;
				continue;
			}
			if(str[i + 1] && str[i + 1] == 'f')
			{
				font  = va_arg(args, t_font *);
				i += 2;
				continue;
			}
			else
			{
				draw_font(font[str[i] - 32], img, o_[0] + font[str[i] - 32].pad_left,  o_[1] + font[str[i] - 32].pad_top, RGBA);
				o_[0] += font[str[i] - 32].x + font[str[i] - 32].pad_right;
			}
		}
		else
		{
			draw_font(font[str[i] - 32], img, o_[0] + font[str[i] - 32].pad_left,  o_[1] + font[str[i] - 32].pad_top, RGBA);
			o_[0] += font[str[i] - 32].x + font[str[i] - 32].pad_right;
		}
		i++;
	}
	va_end(args);
}
