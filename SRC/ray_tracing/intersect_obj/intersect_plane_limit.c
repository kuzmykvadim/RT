/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane_limit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:58:22 by asvirido          #+#    #+#             */
/*   Updated: 2017/06/09 19:58:23 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

int		intersect_plane_limit(t_ray *ray, t_plane_limit *plane, double *t)
{
	t_vector	tmp;
	t_val_math	val;
	// double		min_x;
	// double		max_x;
	// double		min_z;
	// double		max_z;
	t_vector	p;

	val.d = dot_vector(plane->normal, ray->direction);
	// min_x = plane->position->x + (plane->weight / 2);
	// min_z = plane->position->z + (plane->height / 2);
	// max_x = plane->position->x - (plane->weight / 2);
	// max_z = plane->position->z - (plane->height / 2);
	if (val.d != 0)
	{
		tmp = sub_vector(plane->position, ray->origin);
		val.t0 = dot_vector(&tmp, plane->normal) / val.d;
		if (val.t0 > 0.001f)
		{
			tmp = scalar_vector(val.t0, ray->direction);
			p = add_vector(&tmp, ray->origin);
			// if ((p.x <= min_x && p.x >= max_x) && (p.z <= min_z && p.z >= max_z))
			// 	{
				*t = val.t0;
				return (1);
				// }
		}
	}
	return (0);
}
