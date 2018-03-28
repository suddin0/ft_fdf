/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 06:31:28 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 12:22:40 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	rotate_x(t_point *a, double v)
{
	double	x;
	double	y;
	double	z;

	x = a->x;
	y = a->y;
	z = a->z;
	a->x = (x * 1) + (y * 0) + (z * 0);
	a->y = (x * 0) + (y * cos(v)) + (z * -sin(v));
	a->z = (x * 0) + (y * sin(v)) + (z * cos(v));
}

void	rotate_y(t_point *a, double v)
{
	double	x;
	double	y;
	double	z;

	x = a->x;
	y = a->y;
	z = a->z;
	a->x = (x * cos(v)) + (y * 0) + (z * sin(v));
	a->y = (x * 0) + (y * 1) + (z * 0);
	a->z = (x * -sin(v)) + (y * 0) + (z * cos(v));
}

void	rotate_z(t_point *a, double v)
{
	double	x;
	double	y;
	double	z;

	x = a->x;
	y = a->y;
	z = a->z;
	a->x = (x * cos(v)) + (y * -sin(v)) + (z * 0);
	a->y = (x * sin(v)) + (y * cos(v)) + (z * 0);
	a->z = (x * 0) + (y * 0) + (z * 1);
}
