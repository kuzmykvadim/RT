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

t_vector	point_intersect(t_ray *ray, double *t)
{
	t_vector	new_point;
	t_vector	scale;

	scale = scalar_vector(*t, ray->direction);
	new_point = add_vector(&scale, ray->origin);
	return (new_point);
}

static int	plane(t_ray *ray, t_half_sphere *sphere, double *t)
{
	t_vector	tmp;
	t_val_math	val;
	t_vector	p;

	val.d = dot_vector(sphere->normal, ray->direction);
	if (val.d != 0)
	{
		tmp = sub_vector(sphere->position, ray->origin);
		val.t0 = dot_vector(&tmp, sphere->normal) / val.d;
		if (val.t0 > 0.001f)
		{
			*t = val.t0;
			return (1);
		}
	}
	return (0);
}

int	intersect_half_sphere(t_ray *ray, t_half_sphere *sphere, double *t)
{
	t_val_math	val;
	t_vector	tmp;
	t_vector	p;
	double		t_s;
	double		t_p;
	t_vector	p2;
	int			res;


	// SPHERE INTERSECT
	sphere->light_n = 0;
	val.dist = sub_vector(ray->origin, SPHERE_POSITION);
	val.a = dot_vector(ray->direction, ray->direction);
	val.b = 2 * dot_vector(ray->direction, &val.dist);
	val.c = dot_vector(&val.dist, &val.dist) - SPHERE_RADIUS_POW;
	res = discriminant(t, val);
	// if (res == 0)  //IF SPHERE INTERSECT NO;RETURN FALSE
	// 	return (0);
	p = point_intersect(ray, t); // ELSE CREATE POINT INTERSECT SPHERE
	t_s = *t; // REMEMBER t for sphere
	/////////////////////////// PLANE INTERSECT
	res = plane(ray, sphere, t); // find intersect plane
	t_p = *t;

	t_vector	normal_p;
	t_vector	normal_s;

	normal_s = normal_vector(sub_vector(sphere->position, &p));
	set_vector(&normal_p, sphere->normal);

	double dot = cos_vector(&normal_s, &normal_p);

	if (dot >= 0)
	{
		*t = t_s;
		return (1);
	}
	if (res == 0)
		return (0);
	*t = t_p;
	sphere->light_n = 2;
	return (1);
}
