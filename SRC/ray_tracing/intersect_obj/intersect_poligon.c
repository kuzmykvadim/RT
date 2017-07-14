/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_poligon.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 19:39:46 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/29 19:39:50 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"
// #define EPS 0.00000001
//
// int	intersect_poligon(t_ray *ray, t_poligon *poligon, double *t)
// {
// 		t_vector	edge1;
// 		t_vector	edge2;
// 		t_vector	tvec;
// 		t_vector	pvec;
// 		t_vector	qvec;
// 		double		det;
// 		double		inv_det;
// 		double		u;
// 		double		v;
//
// 		edge1 = sub_vector(poligon->v1, poligon->v0);
// 		edge2 = sub_vector(poligon->v2, poligon->v0);
// 		pvec = product_vectors(ray->direction, &edge2);
// 		det = dot_vector(&edge1, &pvec);
// 		if (det < 0)
// 			return (0);
// 		if (fabs(det) < 0.00000001)
// 			return (0);
// 		inv_det = 1.0 / det;
// 		tvec = sub_vector(ray->origin, poligon->v0);
// 		u = dot_vector(&tvec, &pvec) * inv_det;
// 		if (u < 0 || u > 1)
// 			return (0);
// 		qvec = product_vectors(&tvec, &edge1);
// 		v = dot_vector(ray->direction, &qvec) * inv_det;
// 		if (v < 0 || u + v > 1)
// 			return (0);
// 		*t = dot_vector(&edge2, &qvec) * inv_det;
// 		if (*t >= 0)
// 			return (0);
// 		*t = fabs(*t);
// 	//	printf("dot_product %f\n",dot_vector(ray->direction, poligon->normal));
// 		// printf("t %f\n",*t);
// 		return (1);
// }
