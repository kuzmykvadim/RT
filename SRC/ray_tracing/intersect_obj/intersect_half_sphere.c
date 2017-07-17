/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_half_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 03:53:29 by asvirido          #+#    #+#             */
/*   Updated: 2017/06/03 03:53:30 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

int		disc(t_ray *ray, t_object *half, double *t)
{
	t_vector		tmp;
	t_val_math	val;
	t_vector		p;

	val.d = dot_vector(&half->direction, ray->direction);
	if (val.d != 0)
	{
		tmp = sub_vector(&half->position, ray->origin);
		val.t0 = dot_vector(&tmp, &half->direction) / val.d;
		if (val.t0 > 0.001)
		{
		   tmp = scalar_vector(val.t0, ray->direction);
		   p = add_vector(ray->origin, &tmp);
		   tmp = sub_vector(&p, &half->position);
		   val.d = dot_vector(&tmp, &tmp);
		   if (sqrtf(val.d) <= half->radius_disc)
		   {
			   *t = val.t0;
			   return (1);
		   }
		}
	}
	return (0);
}

int	sphere(t_ray *ray, t_object *obj, double *t)
{
	t_val_math	val;

	obj->light_n = 0;
	val.dist = sub_vector(ray->origin, &obj->position);
	val.a = dot_vector(ray->direction, ray->direction);
	val.b = 2 * dot_vector(ray->direction, &val.dist);
	val.c = dot_vector(&val.dist, &val.dist) - obj->size_pow;
	return(discriminant(t, val));
}

int	intersect_half_sphere(t_ray *ray, t_object *obj, double *t)
{
	t_vector		normal_s;
	t_vector		p;
	t_vector		p2;
	double		t_s;
	double		dot;
	int			res;

	if ((res = sphere(ray, obj, t)) == 0)
		return (0);
	p = point_intersect(ray, t);
	t_s = *t;
	normal_s = normal_vector(sub_vector(&obj->position, &p));
	dot = cos_vector(&normal_s, &obj->direction);
	if (dot >= 0)
	{
		*t = t_s;
		return (1);
	}
	res = disc(ray, obj, t);
	if (res == 0)
		return (0);
	obj->light_n = 2;
	return (1);
}
