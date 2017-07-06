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

void	rotation_x_cam(t_rtv1 *rtv1, int angle)
{
	//t_vector	tmp;
	int			i;
	double		y;
	double		z;

	i = -1;
	// y = RAY_ORIGIN->y * cos(angle * RAD) - RAY_ORIGIN->z * sin(angle * RAD);
	// z = RAY_ORIGIN->y * sin(angle * RAD) + RAY_ORIGIN->z * cos(angle * RAD);
	// RAY_ORIGIN->y = y;
	// RAY_ORIGIN->z = z;
	while (++i < SIZE)
	{
		y = DIR_NORMAL->y * cos(angle * RAD) - DIR_NORMAL->z * sin(angle * RAD);
		z = DIR_NORMAL->y * sin(angle * RAD) + DIR_NORMAL->z * cos(angle * RAD);
		DIR_NORMAL->y = y;
		DIR_NORMAL->z = z;
		// y = SCREEN->y * cos(angle * RAD) + SCREEN->z * sin(angle * RAD);
		// z = -SCREEN->y * sin(angle * RAD) + SCREEN->z * cos(angle * RAD);
		// SCREEN->y = y;
		// SCREEN->z = z;
	}
}

void	rotation_x(t_rtv1 *rtv1, int keycode)
{
	if (keycode == 16)
		rotation_x_cam(rtv1, 1);
	else if (keycode == 4)
		rotation_x_cam(rtv1, -1);
}
