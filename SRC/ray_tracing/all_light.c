/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:23:14 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:21:20 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	all_light(t_rtv1 *rtv1, t_val_vector *val, int *hit)
{
	t_model_light	*v;
	int				i;

	i = -1;
	v = (t_model_light*)malloc(sizeof(t_model_light) * 1);
	while (++i < SIZE_LIGHT)
	{
		val->tmp = normal_vector(sub_vector(&val->point, L.position));
		v->dot = cos_vector(&val->n_point, &val->tmp);
		v->dot = min(pow(v->dot, 2), 1);
		v->ambient = ambient(0.3, 1.1);
		v->diffuse = diffuse(0.3, 1.1, v->dot);
		v->specular = specular(0.9, 1.11, v->dot);
		v->diffuse = min(pow(v->diffuse, 12), 1);
		v->ambient = min(v->ambient, 1);
		(v->specular < 0 ? v->specular = 0 : 0);
		v->specular = min(pow(v->specular, 8), 1);
		v->beta = (v->ambient + v->diffuse + v->dot);
		v->beta = pow(v->beta, 2);
		if (hit[i] == 1 && SIZE_LIGHT != 0)
			val->rgb[i] = bleak(val->rgb[i], L_COLOR, v->beta, v->specular);
	}
	free(v);
}
