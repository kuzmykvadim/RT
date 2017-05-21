/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 22:19:50 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:19:53 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

int	intersect_sphere(t_ray *ray, t_sphere *sphere, double *t)
{
	t_val_math	val;
	int			res;

	val.dist = sub_vector(ray->origin, SPHERE_POSITION);
	val.a = dot_vector(ray->direction, ray->direction);
	val.b = 2 * dot_vector(ray->direction, &val.dist);
	val.c = dot_vector(&val.dist, &val.dist) - SPHERE_RADIUS_POW;
	res = discriminant(t, val);
	return (res);
}
