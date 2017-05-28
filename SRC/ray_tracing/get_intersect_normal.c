/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersect_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:13:50 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:52:10 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

t_vector	get_intersect_normal(t_rtv1 *rtv1, int num_obj, t_vector *point)
{
	t_vector	normal;

	normal.x = 0;
	normal.y = 0;
	normal.z = 0;
	if (RT_OBJ.sphere != NULL)
		normal = normal_vector(sub_vector(RT_OBJ.SPHERE_POSITION, point));
	else if (RT_OBJ.plane != NULL)
		normal = *RT_OBJ.plane->normal;
	else if (RT_OBJ.cylinder != NULL)
		normal = find_normal_cylinder(RT_OBJ.cylinder, point);
	else if (RT_OBJ.cone != NULL)
		normal = find_normal_cone(RT_OBJ.cone, point);
	// else if (RT_OBJ.disk != NULL)
	// 	set_vector(&normal, RT_OBJ.disk->normal);
	return (normal);
}
