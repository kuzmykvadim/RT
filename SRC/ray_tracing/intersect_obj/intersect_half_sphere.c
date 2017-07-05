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

// static int intersect_plane_two(t_ray *ray, t_half_sphere *sphere, double *t)
// {
// 	double		t0;
// 	double		denom;
// 	t_vector	p0l0;
//
// 	denom = dot_vector(ray->direction, sphere->normal);
// 	if (denom == 0)
// 		return (0);
// 	t0 = -1;
// 	if (denom > 0.001f)
// 	{
// 		p0l0 = sub_vector(sphere->p_pos, ray->origin);
// 		t0 = dot_vector(&p0l0, sphere->normal) / denom;
// 		sphere->light_n = 2;
// 		*t = t0;
// 	}
// 	return (t0 >= 0);
// }
//
// static int	intersect_two(t_ray *ray, t_half_sphere *sphere, double *t)
// {
// 	t_vector	p;
// 	t_vector	tmp;
// 	t_vector	scale;
// 	t_val_math	val;
// 	int			res;
//
// 	scale = scalar_vector(*t, ray->direction);
// 	p = add_vector(&scale, ray->origin);
// 	res = check_point(&p, sphere);
// 	if (res == 1)
// 		return (1);
// 	val.d = dot_vector(sphere->normal, ray->direction);
// 	if (val.d != 0)
// 	{
// 		tmp = sub_vector(sphere->position, ray->origin);
// 		val.t0 = dot_vector(&tmp, sphere->normal) / val.d;
// 		if (val.t0 > 0.001f)
// 		{
// 			// tmp = scalar_vector(val.t0, ray->direction);
// 			// p = add_vector(ray->origin, &tmp);
// 			// tmp = sub_vector(&p, sphere->position);
// 			// val.d = dot_vector(&tmp, &tmp);
// 			// if (sqrtf(val.d) <= sphere->radius + 100000)
// 			// {
// 			//	if (val.t0 >= *t)
// 			//	*t = val.t0;
// 				sphere->light_n = 2;
// 				res = 1;
// 			// }
// 		}
// 	}
// 	return (res);
// }
//
// int	intersect_half_sphere(t_ray *ray, t_half_sphere *sphere, double *t)
// {
// 	t_val_math	val;
// 	t_vector	tmp;
// 	t_vector	p;
// 	int			res;
//
// 	sphere->light_n = 0;
// 	val.dist = sub_vector(ray->origin, SPHERE_POSITION);
// 	val.a = dot_vector(ray->direction, ray->direction);
// 	val.b = 2 * dot_vector(ray->direction, &val.dist);
// 	val.c = dot_vector(&val.dist, &val.dist) - SPHERE_RADIUS_POW;
// 	res = discriminant(t, val);
// 	if (res == 0)
// 		return (res);
// 	res = intersect_two(ray, sphere, t);
// 	return (res);
// }
