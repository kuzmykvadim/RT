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

void	rotation_y_cam(t_rtv1 *rtv1, int angle)
{
	//t_vector	tmp;
	int			i;
	double		x;
	double		z;

	i = -1;
	// x = DIR_NORMAL->x * cos(angle * RAD) + DIR_NORMAL->z * sin(angle * RAD);
	// z = -DIR_NORMAL->x * sin(angle * RAD) + DIR_NORMAL->z * cos(angle * RAD);
	// DIR_NORMAL->x = x;
	// DIR_NORMAL->z = z;
	while (++i < SIZE)
	{
		x = DIR_NORMAL->x * cos(angle * RAD) + DIR_NORMAL->z * sin(angle * RAD);
		z = -DIR_NORMAL->x * sin(angle * RAD) + DIR_NORMAL->z * cos(angle * RAD);
		DIR_NORMAL->x = x;
		DIR_NORMAL->z = z;
		// x = SCREEN->x * cos(angle * RAD) + SCREEN->z * sin(angle * RAD);
		// z = -SCREEN->x * sin(angle * RAD) + SCREEN->z * cos(angle * RAD);
		// SCREEN->x = x;
		// SCREEN->z = z;
	}
}

void	rotation_y(t_rtv1 *rtv1, int keycode)
{
	if (keycode == BUTTON_W)
		rotation_y_cam(rtv1, 1);
	else if (keycode == BUTTON_S)
		rotation_y_cam(rtv1, -1);
}
