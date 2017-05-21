/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_point_intersect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:44:54 by asvirido          #+#    #+#             */
/*   Updated: 2017/04/28 13:44:55 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

t_vector	find_point_intersect(t_rtv1 *rtv1, double *t)
{
	t_vector	new_point;
	t_vector	scale;

	scale = scalar_vector(*t, RAY_DIRECTION);
	new_point = add_vector(&scale, RAY_ORIGIN);
	return (new_point);
}
