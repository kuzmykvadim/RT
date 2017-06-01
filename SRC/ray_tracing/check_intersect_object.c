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
	int	res;

	res = 0;
	if (RT->rt_obj[i].plane != NULL)
		res = intersect_plane(ray, RT->rt_obj[i].plane, t);
	else if (RT->rt_obj[i].sphere != NULL)
		res = intersect_sphere(ray, RT->rt_obj[i].sphere, t);
	else if (RT->rt_obj[i].cylinder != NULL)
		res = intersect_cylinder(ray, RT->rt_obj[i].cylinder, t);
	else if (RT->rt_obj[i].cone != NULL)
		res = intersect_cone(ray, RT->rt_obj[i].cone, t);
	else if (RT->rt_obj[i].disk != NULL)
		res = intersect_disc(ray, RT->rt_obj[i].disk, t);
	else if (RT->rt_obj[i].poligon != NULL)
		res = intersect_poligon(ray, RT->rt_obj[i].poligon, t);
	 return (res);
}
