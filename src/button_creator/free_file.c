/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 04:46:29 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 04:47:14 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_creator.h"

void	free_file(char ***file, int argc)
{
	int i;

	i = 0;
	while (i != argc && file[i])
	{
		free((file[i])[0]);
		free((file[i])[1]);
		free((file[i])[2]);
		free(file[i]);
		i++;
	}
	free(file);
}

void	clear_button(t_button *button)
{
	button->id = 0;
	button->type = 0;
	button->stat = 0;
	memset(button->view[0], 0, BUTTON_SIZE);
	memset(button->view[1], 0, BUTTON_SIZE);
	memset(button->view[2], 0, BUTTON_SIZE);
	memset(button->view[2], 0, BUTTON_SIZE);
	memset(button->name, 0, 100);
	button->x = 0;
	button->y = 0;
	button->o_x = 0;
	button->o_y = 0;
	button->value = NULL;
	button->f = NULL;
}
