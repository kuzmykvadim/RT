/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:34:17 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:43:17 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

int		intersect_plane(t_ray *ray, t_plane *plane, double *t)
{
	t_val_math	val;
	int			res;

	res = 0;
	val.d = dot_vector(plane->normal, ray->direction);
	if (val.d != 0)
	{
		val.a = (dot_vector(plane->normal, ray->origin));
		val.b = -(val.a + plane->distance);
		val.t0 = val.b / val.d;
		if (val.t0 > 0.001)
		{
			*t = val.t0;
			res = 1;
		}
	}
	return (res);
}
