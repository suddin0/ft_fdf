/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 07:39:57 by suddin            #+#    #+#             */
/*   Updated: 2018/03/30 06:02:20 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

inline static char	*text_itoa(int num)
{
	static char	str[22];
	int			k;
	long		n;
	char		sign;

	k = 0;
	sign = 0;
	ft_memset(str, 0, 22);
	if (num == 0 && (str[k] = '0') > 0)
		return (str);
	else if (num < 0)
		sign = 1;
	n = (num < 0) ? -num : num;
	while (n != 0)
	{
		str[k] = (n % 10) + 48;
		n /= 10;
		k++;
	}
	if (sign == 1)
		str[k] = '-';
	ft_strrev(str);
	return (str);
}

inline static	int	put_text(t_image *img, char *str, ...)
{
	t_printf_text pf;

	va_start(pf.args, str);
	pf.i = 0;
	(pf.o_)[0] = va_arg(pf.args, int);
	(pf.o_)[1] = va_arg(pf.args, int);
	pf.font = va_arg(pf.args, t_font *);
	pf.d.c = va_arg(pf.args, int);
	pf.d.img = img;
	if (!str)
		return (0);
	while (str[pf.i])
	{
		if (!ft_isprint(str[pf.i]))
			str[pf.i] = 127;
		draw_font((pf.font)[str[pf.i] - 32], &(pf.d), (pf.o_)[0] + \
		(pf.font)[str[pf.i] - 32].pad_left, (pf.o_)[1] + \
		(pf.font)[str[pf.i] - 32].pad_top);
		(pf.o_)[0] += (pf.font)[str[pf.i] - 32].x + \
					(pf.font)[str[pf.i] - 32].pad_right;
		(pf.i)++;
	}
	va_end(pf.args);
	return ((pf.o_)[0]);
}

inline static	int	printf_text_ext(t_printf_text *pf, char *str, t_image *img)
{
	if (str[pf->i] != '%')
		return (0);
	if (str[pf->i + 1] && str[pf->i + 1] == 'C' && (pf->i += 2) > 0)
		pf->d.c = va_arg(pf->args, int);
	else if (str[pf->i + 1] && str[pf->i + 1] == 's' && (pf->i += 2) > 0)
		pf->o_[0] = put_text(img, va_arg(pf->args, char *), \
				pf->o_[0], pf->o_[1], pf->font, pf->d.c);
	else if (str[pf->i + 1] && str[pf->i + 1] == 'd' && (pf->i += 2) > 0)
		pf->o_[0] = put_text(img, text_itoa(va_arg(pf->args, int)), \
				pf->o_[0], pf->o_[1], pf->font, pf->d.c);
	else if (str[pf->i + 1] && str[pf->i + 1] == 'x' && (pf->i += 2) > 0)
		pf->o_[0] = va_arg(pf->args, int);
	else if (str[pf->i + 1] && str[pf->i + 1] == 'y' && (pf->i += 2) > 0)
		pf->o_[1] = va_arg(pf->args, int);
	else if (str[pf->i + 1] && str[pf->i + 1] == 'f' && (pf->i += 2) > 0)
		pf->font = va_arg(pf->args, t_font *);
	else if ((pf->i += 1) > 0)
	{
		draw_font((pf->font)[str[pf->i] - 32], &(pf->d), pf->o_[0] + \
				(pf->font)[str[pf->i] - 32].pad_left, pf->o_[1] + \
				(pf->font)[str[pf->i] - 32].pad_top);
		pf->o_[0] += (pf->font)[str[pf->i] - 32].x +
			(pf->font)[str[pf->i] - 32].pad_right;
	}
	return (1);
}

inline static void	pf_init(t_printf_text *pf, t_root *root, t_image *img)
{
	ft_memset(pf->o_, 0, 4);
	pf->i = 0;
	pf->font = root->font_18;
	pf->d.c = COL_WHITE;
	pf->d.img = img;
	pf->o_[0] = 10;
	pf->o_[1] = 10;
}

void				printf_text(t_root *root, t_image *img, char *str, ...)
{
	t_printf_text pf;

	va_start(pf.args, str);
	pf_init(&pf, root, img);
	while (str[pf.i])
	{
		if (!ft_isprint(str[pf.i]))
			str[pf.i] = 127;
		if (printf_text_ext(&pf, str, img))
			continue ;
		else
		{
			draw_font((pf.font)[str[pf.i] - 32], &(pf.d), pf.o_[0] + \
					(pf.font)[str[pf.i] - 32].pad_left, pf.o_[1] + \
					(pf.font)[str[pf.i] - 32].pad_top);
			pf.o_[0] += (pf.font)[str[pf.i] - 32].x + \
						(pf.font)[str[pf.i] - 32].pad_right;
		}
		(pf.i)++;
	}
	va_end(pf.args);
}
