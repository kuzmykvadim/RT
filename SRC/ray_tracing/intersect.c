/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:57:54 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:37:39 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

t_color		intersect(t_rtv1 *rtv1)
{
	t_val_intersect	val;
	t_val_math		val_t;
	t_color			color;

	val.i = 0;
	val.num_obj = -1;
	val_t.t0 = 2000000.0f;
	while (val.i < SIZE_OBJ)
	{
		val_t.t1 = 2000000.0f;
		val.hit = check_intersect_object(RT, &val_t.t1, val.i, RT->ray);
		if (val.hit != 0 && val_t.t1 < val_t.t0 && RT->rt_obj[val.i].of_on == 1)
		{
			val_t.t0 = val_t.t1;
			val.num_obj = val.i;
		}
		val.i++;
	}
	if (val.num_obj != -1 && RT->light_off_on == 1)
		color = ft_light(RT, &val_t.t0, val.num_obj);
	else if (val.num_obj != -1 && RT->light_off_on == 0)
		color = get_color(RT, val.num_obj);
	else
		set_color(&color, 0, 0, 0);
	return (color);
}
