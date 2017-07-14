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

// int		disc(t_ray *ray, t_half_sphere *half, double *t)
// {
// 	t_vector	tmp;
// 	t_val_math	val;
// 	t_vector	p;
//
// 	val.d = dot_vector(half->normal, ray->direction);
// 	if (val.d != 0)
// 	{
// 		tmp = sub_vector(half->position, ray->origin);
// 		val.t0 = dot_vector(&tmp, half->normal) / val.d;
// 		if (val.t0 > 0.001)
// 		{
// 		   tmp = scalar_vector(val.t0, ray->direction);
// 		   p = add_vector(ray->origin, &tmp);
// 		   tmp = sub_vector(&p, half->position);
// 		   val.d = dot_vector(&tmp, &tmp);
// 		   if (sqrtf(val.d) <= half->radius_disc)
// 		   {
// 			   *t = val.t0;
// 			   return (1);
// 		   }
// 		}
// 	}
// 	return (0);
// }
// int	intersect_half_sphere(t_ray *ray, t_half_sphere *sphere, double *t)
// {
// 	t_val_math	val;
// 	t_vector	normal_s;
// 	t_vector	p;
// 	double		t_s;
// 	double		dot;
// 	int			res;
//
// 	sphere->light_n = 0;
// 	val.dist = sub_vector(ray->origin, SPHERE_POSITION);
// 	val.a = dot_vector(ray->direction, ray->direction);
// 	val.b = 2 * dot_vector(ray->direction, &val.dist);
// 	val.c = dot_vector(&val.dist, &val.dist) - SPHERE_RADIUS_POW;
// 	res = discriminant(t, val);
// 	if (res == 0)
// 		return (0);
// 	p = point_intersect(ray, t);
// 	t_s = *t;
// 	res = disc(ray, sphere, t);
// 	normal_s = normal_vector(sub_vector(sphere->position, &p));
// 	dot = cos_vector(&normal_s, sphere->normal);
// 	if (dot >= 0)
// 	{
// 		*t = t_s;
// 		return (1);
// 	}
// 	if (res == 0)
// 		return (0);
// 	sphere->light_n = 2;
// 	return (1);
// }
