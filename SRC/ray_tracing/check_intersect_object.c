/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersect_object.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:41:51 by asvirido          #+#    #+#             */
/*   Updated: 2017/04/28 13:41:52 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

int	check_intersect_object(t_rtv1 *rtv1, double *t, int i, t_ray *ray)
{
 	int			res;

	res = 0;
	if (RT->data->all_obj[i].id == PLANE)
		res = intersect_plane_limit(ray, RT->data->all_obj[i], t);
	else if (RT->data->all_obj[i].id == SPHERE)
		res = intersect_sphere(ray, RT->data->all_obj[i], t);
	else if (RT->data->all_obj[i].id == DISC)
		res = intersect_disc(ray, RT->data->all_obj[i], t);
	else if (RT->data->all_obj[i].id == CYLINDER)
		res = intersect_cylinder(ray,RT->data->all_obj[i], t);
	else if (RT->data->all_obj[i].id == CONE)
		res = intersect_cone(ray, RT->data->all_obj[i], t);
	// else if (RT->rt_obj[i].id == 'h')
	// 	res = intersect_half_sphere(ray, RT->rt_obj[i].half_sphere, t);
	return (res);
}
// else if (RT->rt_obj[i].id == 't')
	// res = intersect_poligon(ray, RT->rt_obj[i].poligon, t);
