/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ellipsoid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:04:50 by asvirido          #+#    #+#             */
/*   Updated: 2017/07/17 20:04:50 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

static void		find_a_b_c(t_ray *ray, t_object e, t_val_math *val)
{
	double      a1;
	double      a2;

   a1 = 2 * e.size_pow * dot_vector(ray->direction, &e.direction);
   a2 = e.size * e.size + 2 * e.size_pow * dot_vector(ray->origin, &e.direction) - e.size_pow;
	val->a = 4 * e.size * e.size * dot_vector(ray->direction, ray->direction) - a1 * a1;
	val->b = 2 * (4 * e.size * e.size * dot_vector(ray->direction, ray->origin) - a1 * a2);
	val->c = 4 * e.size * e.size * dot_vector(ray->origin, ray->origin) - a2 * a2;
	// t_vector sub;
	// t_vector	tmp;
	// t_vector delta;
	// double beta;
	//
	// val->a = 2 * dot_vector(ray->direction, ray->direction);
	// val->b = dot_vector(ray->direction, &ellips.direction) * 2 * ellips.size_pow;
	// tmp = scalar_vector(ellips.size_pow, &ellips.direction);
	// sub = sub_vector(ray->origin, &ellips.position);
	// delta = add_vector(&tmp, &sub);
	// beta = dot_vector(&sub, &sub);
	// val->c = dot_vector(&delta, &delta) + beta - (ellips.size * ellips.size);
}

int	intersect_ellipsoid(t_ray *ray, t_object ellips, double *t)
{
	t_val_math		val;
	int				res;

	res = 0;
	ellips.size_pow = ellips.size - 1;
	find_a_b_c(ray, ellips, &val);
	res = discriminant(t, val);
	return (res);
}
