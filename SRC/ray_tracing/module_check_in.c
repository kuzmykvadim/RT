/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module_check_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:59:35 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:29:11 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

int		module_check_in(t_rtv1 *rtv1, t_vector *pos_obj)
{
	t_val_intersect	val;
	t_val_math		math;
	t_vector		ray_1;
	t_vector		ray_2;

	val.i = 0;
	construct_vector(&ray_1, pos_obj->x - 400, pos_obj->y, pos_obj->z);
	construct_vector(&ray_2, pos_obj->x + 400, pos_obj->y, pos_obj->z);
	ray_1 = normal_vector(sub_vector(&ray_1, pos_obj));
	ray_2 = normal_vector(sub_vector(&ray_2, pos_obj));
	while (val.i < SIZE_OBJ)
	{
		set_vector(RAY_DIRECTION, &ray_1);
		val.hit = check_intersect_object(RT, &math.t1, val.i, RT->ray);
		if (val.hit != 0)
		{
			set_vector(RAY_DIRECTION, &ray_2);
			val.hit = check_intersect_object(RT, &math.t1, val.i, RT->ray);
			if (val.hit != 0)
				if (rtv1->rt_obj[val.i].cone == NULL)
					return (0);
		}
		val.i++;
	}
	return (1);
}
