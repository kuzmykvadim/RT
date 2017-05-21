/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:47:44 by asvirido          #+#    #+#             */
/*   Updated: 2017/02/06 17:47:45 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

void	rotation_y_forward(t_rtv1 *rtv1, int angle)
{
	t_vector	tmp;
	int			i;
	int			size;
	double		x;
	double		z;

	i = 0;
	size = SIZE_X * SIZE_Y;
	x = RAY_ORIGIN->x * cos(angle * RAD) + RAY_ORIGIN->z * sin(angle * RAD);
	z = -RAY_ORIGIN->x * sin(angle * RAD) + RAY_ORIGIN->z * cos(angle * RAD);
	rtv1->ray->origin->x = x;
	rtv1->ray->origin->z = z;
	while (i < size)
	{
		x = SCREEN->x * cos(angle * RAD) + SCREEN->z * sin(angle * RAD);
		z = -SCREEN->x * sin(angle * RAD) + SCREEN->z * cos(angle * RAD);
		SCREEN->x = x;
		SCREEN->z = z;
		tmp = normal_vector(sub_vector(SCREEN, RAY_ORIGIN));
		RT->screen[i].dir_normal->x = tmp.x;
		RT->screen[i].dir_normal->y = tmp.y;
		RT->screen[i].dir_normal->z = tmp.z;
		i++;
	}
}

void	rotation_y_back(t_rtv1 *rtv1, int angle)
{
	t_vector	tmp;
	int			i;
	int			size;
	double		x;
	double		z;

	i = 0;
	size = SIZE_X * SIZE_Y;
	x = RAY_ORIGIN->x * cos(angle * RAD) - RAY_ORIGIN->z * sin(angle * RAD);
	z = RAY_ORIGIN->x * sin(angle * RAD) + RAY_ORIGIN->z * cos(angle * RAD);
	RAY_ORIGIN->x = x;
	RAY_ORIGIN->z = z;
	while (i < size)
	{
		x = SCREEN->x * cos(angle * RAD) - SCREEN->z * sin(angle * RAD);
		z = SCREEN->x * sin(angle * RAD) + SCREEN->z * cos(angle * RAD);
		SCREEN->x = x;
		SCREEN->z = z;
		tmp = normal_vector(sub_vector(SCREEN, RAY_ORIGIN));
		RT->screen[i].dir_normal->x = tmp.x;
		RT->screen[i].dir_normal->y = tmp.y;
		RT->screen[i].dir_normal->z = tmp.z;
		i++;
	}
}

void	rotation_y(t_rtv1 *rtv1, int keycode)
{
	if (keycode == BUTTON_W)
		rotation_y_forward(rtv1, 1);
	else if (keycode == BUTTON_S)
		rotation_y_back(rtv1, 1);
}
