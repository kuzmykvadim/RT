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
	t_vector	old_origin;
	t_vector	old_dir;

	set_vector(&old_origin, ray->origin);
	set_vector(&old_dir, ray->direction);
	anti_rotation_vector(ray->origin, RT->rt_obj[i].rotation);
	anti_rotation_vector(ray->direction, RT->rt_obj[i].rotation);
	res = 0;
	if (RT->rt_obj[i].id == 'l')
		res = intersect_plane_limit(ray, RT->rt_obj[i].plane_limit, t);
	else if (RT->rt_obj[i].id == 's')
		res = intersect_sphere(ray, RT->rt_obj[i].sphere, t);
	else if (RT->rt_obj[i].id == 'C')
		res = intersect_cylinder(ray, RT->rt_obj[i].cylinder, t);
	else if (RT->rt_obj[i].id == 'c')
		res = intersect_cone(ray, RT->rt_obj[i].cone, t);
	// else if (RT->rt_obj[i].id == 'd')
	// 	res = intersect_disc(ray, RT->rt_obj[i].disk, t);
	set_vector(ray->origin, &old_origin);
	set_vector(ray->direction, &old_dir);
	return (res);
}
// else if (RT->rt_obj[i].id == 't')
	// res = intersect_poligon(ray, RT->rt_obj[i].poligon, t);
// if (RT->rt_obj[i].id == 'p')
// 	res = intersect_plane(ray, RT->rt_obj[i].plane, t);
//else if (RT->rt_obj[i].id == 'h')
//res = intersect_half_sphere(ray, RT->rt_obj[i].half_sphere, t);
//
