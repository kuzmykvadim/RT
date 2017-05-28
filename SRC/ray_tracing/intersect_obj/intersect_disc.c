/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_disc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 05:01:40 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/26 05:01:42 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

int		intersect_disc(t_ray *ray, t_disk *disk, double *t)
{
	double		d;
	t_vector	tmp;
	t_val_math	val;
	t_vector	p;

	d = dot_vector(disk->normal, ray->direction);
	if (d != 0)
	{
		tmp = sub_vector(disk->position, ray->origin);
		val.t0 = dot_vector(&tmp, disk->normal) / d;
		if (val.t0 > 0.001)
		{
			// printf("t0 %f\n",val.t0);
		   // tmp = add_vector(ray->origin, ray->direction);
		   // p = scalar_vector(val.t0, &tmp);
		   tmp = scalar_vector(val.t0, ray->direction);
		   p = add_vector(ray->origin, &tmp);
		   tmp = sub_vector(&p, disk->position);
			// printf("D_P x %f y %f z %f\n",disk->position->x, disk->position->y, disk->position->z);
			// printf("P x %f y %f z %f\n",p.x, p.y, p.z);
			//  printf("V x %f y %f z %f\n",tmp.x, tmp.y, tmp.z);
		   float d2 = dot_vector(&tmp, &tmp);
			// printf("d2 %f\n",d2);
		   if (sqrtf(d2) <= disk->radius)
		   {
				// printf("AA t %f\n",val.t0);
			   *t = val.t0;
			   return (1);
		   }
		}
	}
	return (0);
}
