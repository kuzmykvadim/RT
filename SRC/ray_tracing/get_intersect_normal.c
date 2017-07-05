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

	if (RT_OBJ.id == 's')
		normal = normal_vector(sub_vector(RT_OBJ.SPHERE_POSITION, point));
	else if (RT_OBJ.id == 'C')
		normal = find_normal_cylinder(RT_OBJ.cylinder, point);
	else if (RT_OBJ.id == 'c')
		normal = find_normal_cone(RT_OBJ.cone, point);
	else if (RT_OBJ.id == 'l')
	{
		set_vector(&normal, RT_OBJ.plane_limit->normal);
		// rotation_vector(&normal, RT->rt_obj[num_obj].rotation);
	}
	// else if (RT_OBJ.id == 'd')
	// 	set_vector(&normal, RT_OBJ.disk->normal);
	return (normal);
}

// else if (RT_OBJ.plane != NULL)
// 	set_vector(&normal, RT_OBJ.plane->normal);
// else if (RT_OBJ.poligon != NULL)
// 	set_vector(&normal, RT_OBJ.poligon->normal);
// else if (RT_OBJ.half_sphere != NULL)
// {
// 	if (RT_OBJ.half_sphere->light_n == 2)
// 		set_vector(&normal, RT_OBJ.half_sphere->normal);
// 	else
// 		normal = normal_vector(sub_vector(RT_OBJ.half_sphere->position, point));
// }
