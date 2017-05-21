/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:29:51 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:26:03 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

t_color		ft_light(t_rtv1 *rtv1, double *t_min, int num_obj)
{
	t_val_vector	*val;
	t_color			color;
	int				*hit;

	val = (t_val_vector*)malloc(sizeof(t_val_vector) * 1);
	hit = (int*)malloc(sizeof(int) * SIZE_LIGHT + 1);
	val->point = find_point_intersect(RT, t_min);
	val->n_point = get_intersect_normal(RT, num_obj, &val->point);
	set_vector(L_RAY_ORIGIN, &val->point);
	all_shadow(RT, num_obj, val, hit);
	all_light(RT, val, hit);
	midle_color(val->rgb, SIZE_LIGHT, &color);
	protected_color(&color);
	free(val);
	free(hit);
	return (color);
}
