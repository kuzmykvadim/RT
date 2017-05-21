/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_z.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:48:00 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:11:01 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

void	rotation_z_forward(t_rtv1 *rtv1, int angle)
{
	t_vector	tmp;
	int			i;
	int			size;
	double		y;
	double		x;

	i = 0;
	size = SIZE_X * SIZE_Y;
	x = RAY_ORIGIN->x * cos(angle * RAD) + RAY_ORIGIN->y * sin(angle * RAD);
	y = -RAY_ORIGIN->x * sin(angle * RAD) + RAY_ORIGIN->y * cos(angle * RAD);
	RAY_ORIGIN->x = x;
	RAY_ORIGIN->y = y;
	while (i < size)
	{
		x = SCREEN->x * cos(angle * RAD) + SCREEN->y * sin(angle * RAD);
		y = -SCREEN->x * sin(angle * RAD) + SCREEN->y * cos(angle * RAD);
		SCREEN->x = x;
		SCREEN->y = y;
		tmp = normal_vector(sub_vector(SCREEN, RAY_ORIGIN));
		RT->screen[i].dir_normal->x = tmp.x;
		RT->screen[i].dir_normal->y = tmp.y;
		RT->screen[i].dir_normal->z = tmp.z;
		i++;
	}
}

void	rotation_z_back(t_rtv1 *rtv1, int angle)
{
	t_vector	tmp;
	int			i;
	int			size;
	double		y;
	double		x;

	i = 0;
	size = SIZE_X * SIZE_Y;
	x = RAY_ORIGIN->x * cos(angle * RAD) - RAY_ORIGIN->y * sin(angle * RAD);
	y = RAY_ORIGIN->x * sin(angle * RAD) + RAY_ORIGIN->y * cos(angle * RAD);
	RAY_ORIGIN->x = x;
	RAY_ORIGIN->y = y;
	while (i < size)
	{
		x = SCREEN->x * cos(angle * RAD) - SCREEN->y * sin(angle * RAD);
		y = SCREEN->x * sin(angle * RAD) + SCREEN->y * cos(angle * RAD);
		SCREEN->x = x;
		SCREEN->y = y;
		tmp = normal_vector(sub_vector(SCREEN, RAY_ORIGIN));
		RT->screen[i].dir_normal->x = tmp.x;
		RT->screen[i].dir_normal->y = tmp.y;
		RT->screen[i].dir_normal->z = tmp.z;
		i++;
	}
}

void	rotation_z(t_rtv1 *rtv1, int keycode)
{
	if (keycode == BUTTON_A)
		rotation_z_forward(rtv1, 1);
	else if (keycode == BUTTON_D)
		rotation_z_back(rtv1, 1);
}
