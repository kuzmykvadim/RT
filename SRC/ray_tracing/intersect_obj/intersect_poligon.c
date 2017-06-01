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

int	intersect_poligon(t_ray *ray, t_poligon *poligon, double *t)
{
	t_vector	edge1;
	t_vector	edge2;
	t_vector	tvec;
	t_vector	pvec;
	t_vector	qvec;
	double		det;
	double		inv_det;
	double		u;
	double		v;
	//float		distance;

	edge1 = sub_vector(poligon->v1, poligon->v0);
	edge2 = sub_vector(poligon->v2, poligon->v0);
	pvec = product_vectors(ray->direction, &edge2);
	det = dot_vector(&edge1, &pvec);
	// if (det < 0.0001f)
	// 	return	(0);
	// tvec = sub_vector(ray->origin, poligon->v0);
	// u = dot_vector(&tvec, &pvec);
	// if (u < 0.f || u > det)
	// 	return (0);
	// v = dot_vector(ray->direction, &qvec);
	// if (v < 0 || u + v > det)
	// 	return (0);
	//  double t0 = dot_vector(&edge2, &qvec) * (1.0 / det);
	//  *t = t0;


	if (det > -0.0001f && det < 0.0001f)
		return (0);
	inv_det = 1.0 / det;
	tvec = sub_vector(ray->origin, poligon->v0);
	u = dot_vector(&tvec, &pvec) * inv_det;
	if (u < 0.f || u > 1.f)
		return (0);
	qvec = product_vectors(&tvec, &edge1);
	v = dot_vector(&qvec, ray->direction) * inv_det;
	if (v < 0 || u + v > 1)
		return (0);
	double t0 = dot_vector(&edge2, &qvec) * inv_det;
	*t = t0;
	// printf("t %f\n",t0);
	return (1);
}
