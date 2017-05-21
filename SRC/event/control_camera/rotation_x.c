/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:35:49 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:02:15 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

void	rotation_x_forward(t_rtv1 *rtv1, int angle)
{
	t_vector	tmp;
	int			i;
	int			size;
	double		y;
	double		z;

	i = 0;
	size = SIZE_X * SIZE_Y;
	y = RAY_ORIGIN->y * cos(angle * RAD) + RAY_ORIGIN->z * sin(angle * RAD);
	z = -RAY_ORIGIN->y * sin(angle * RAD) + RAY_ORIGIN->z * cos(angle * RAD);
	rtv1->ray->origin->y = y;
	rtv1->ray->origin->z = z;
	while (i < size)
	{
		y = SCREEN->y * cos(angle * RAD) + SCREEN->z * sin(angle * RAD);
		z = -SCREEN->y * sin(angle * RAD) + SCREEN->z * cos(angle * RAD);
		SCREEN->y = y;
		SCREEN->z = z;
		tmp = normal_vector(sub_vector(SCREEN, RAY_ORIGIN));
		RT->screen[i].dir_normal->x = tmp.x;
		RT->screen[i].dir_normal->y = tmp.y;
		RT->screen[i].dir_normal->z = tmp.z;
		i++;
	}
}

void	rotation_x_back(t_rtv1 *rtv1, int angle)
{
	t_vector	tmp;
	int			i;
	int			size;
	double		y;
	double		z;

	i = 0;
	size = SIZE_X * SIZE_Y;
	y = RAY_ORIGIN->y * cos(angle * RAD) - RAY_ORIGIN->z * sin(angle * RAD);
	z = RAY_ORIGIN->y * sin(angle * RAD) + RAY_ORIGIN->z * cos(angle * RAD);
	rtv1->ray->origin->y = y;
	rtv1->ray->origin->z = z;
	while (i < size)
	{
		y = SCREEN->y * cos(angle * RAD) - SCREEN->z * sin(angle * RAD);
		z = SCREEN->y * sin(angle * RAD) + SCREEN->z * cos(angle * RAD);
		SCREEN->y = y;
		SCREEN->z = z;
		tmp = normal_vector(sub_vector(SCREEN, RAY_ORIGIN));
		RT->screen[i].dir_normal->x = tmp.x;
		RT->screen[i].dir_normal->y = tmp.y;
		RT->screen[i].dir_normal->z = tmp.z;
		i++;
	}
}

void	rotation_x(t_rtv1 *rtv1, int keycode)
{
	if (keycode == 16)
		rotation_x_forward(rtv1, 1);
	else if (keycode == 4)
		rotation_x_back(rtv1, 1);
}
