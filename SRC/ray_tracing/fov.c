/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 16:25:52 by asvirido          #+#    #+#             */
/*   Updated: 2017/07/09 16:25:53 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void 	fov(t_rtv1 *rtv1, int x, int y)
{
	t_vector vect;

	vect.x = (x + 0.1) / OPTION->size_x;
	vect.y = (y + 0.1) / OPTION->size_y;
	vect.x = (2 * vect.x) - 1;
	vect.y = 1 - (2 * vect.y);
	vect.x *= (OPTION->size_x / (double)OPTION->size_y) * tan((OPTION->fov / 2) * RAD);
	vect.y *= tan((OPTION->fov / 2) * RAD);
	vect.z = 1;
	set_vector(RAY_DIRECTION, &vect);
}
