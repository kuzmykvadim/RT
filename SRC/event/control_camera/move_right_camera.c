/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 01:23:41 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:15:18 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

void	move_right_camera(t_rtv1 *rtv1)
{
	t_vector	tmp;
	int			size;
	int			i;

	size = SIZE_X * SIZE_Y;
	i = 0;
	rtv1->ray->origin->x -= 100;
	while (i < size)
	{
		RT->screen[i].ray->x -= 100;
		tmp = normal_vector(sub_vector(RT->screen[i].ray, RAY_ORIGIN));
		RT->screen[i].dir_normal->x = tmp.x;
		RT->screen[i].dir_normal->y = tmp.y;
		RT->screen[i].dir_normal->z = tmp.z;
		i++;
	}
}
