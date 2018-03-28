/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:47:25 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 11:47:55 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <sys/stat.h>

int	is_file(const char *name)
{
	struct stat st;

	stat(name, &st);
	return (S_ISREG(st.st_mode));
}
