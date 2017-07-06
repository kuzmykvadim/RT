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

void	rotation_z_cam(t_rtv1 *rtv1, int angle)
{
//	t_vector	tmp;
	int			i;
	double		y;
	double		x;

	i = -1;
	// x = RAY_ORIGIN->x * cos(angle * RAD) + RAY_ORIGIN->y * sin(angle * RAD);
	// y = -RAY_ORIGIN->x * sin(angle * RAD) + RAY_ORIGIN->y * cos(angle * RAD);
	// RAY_ORIGIN->x = x;
	// RAY_ORIGIN->y = y;
	while (++i < SIZE)
	{
		x = DIR_NORMAL->x * cos(angle * RAD) + DIR_NORMAL->y * sin(angle * RAD);
		y = -DIR_NORMAL->x * sin(angle * RAD) + DIR_NORMAL->y * cos(angle * RAD);
		DIR_NORMAL->x = x;
		DIR_NORMAL->y = y;
		// x = SCREEN->x * cos(angle * RAD) + SCREEN->y * sin(angle * RAD);
		// y = -SCREEN->x * sin(angle * RAD) + SCREEN->y * cos(angle * RAD);
		// SCREEN->x = x;
		// SCREEN->y = y;
	}
}

void	rotation_z(t_rtv1 *rtv1, int keycode)
{
	if (keycode == BUTTON_A)
		rotation_z_cam(rtv1, 1);
	else if (keycode == BUTTON_D)
		rotation_z_cam(rtv1, -1);
}
