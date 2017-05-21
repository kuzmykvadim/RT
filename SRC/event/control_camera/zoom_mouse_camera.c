/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_mouse_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 01:59:22 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 01:59:23 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

void	zoom(int keycode, int x, int y, t_rtv1 *rtv1)
{
	double		mult;
	t_vector	tmp;
	int			size;
	int			i;

	size = SIZE_X * SIZE_Y;
	i = 0;
	mult = (keycode == 5 ? 0.96 : 1.1);
	rtv1->ray->origin->x = rtv1->ray->origin->x * mult + x * (1 - mult);
	rtv1->ray->origin->y = rtv1->ray->origin->y * mult + y * (1 - mult);
	while (i < size)
	{
		RT->screen[i].ray->x = RT->screen[i].ray->x * mult + x * (1 - mult);
		RT->screen[i].ray->y = RT->screen[i].ray->y * mult + y * (1 - mult);
		tmp = normal_vector(sub_vector(RT->screen[i].ray, RAY_ORIGIN));
		RT->screen[i].dir_normal->x = tmp.x;
		RT->screen[i].dir_normal->y = tmp.y;
		RT->screen[i].dir_normal->z = tmp.z;
		i++;
	}
	ray_tracing(rtv1);
}
