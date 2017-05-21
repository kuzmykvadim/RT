/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_norm_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 20:11:43 by asvirido          #+#    #+#             */
/*   Updated: 2017/04/28 20:11:44 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

int		calc_norm_dir(int i, t_rtv1 *rtv1)
{
	t_vector	tmp;

	tmp = normal_vector(sub_vector(RT->screen[i].ray, RAY_ORIGIN));
	RT->screen[i].dir_normal->x = tmp.x;
	RT->screen[i].dir_normal->y = tmp.y;
	RT->screen[i].dir_normal->z = tmp.z;
	RT->screen2[i].dir_normal->x = tmp.x;
	RT->screen2[i].dir_normal->y = tmp.y;
	RT->screen2[i].dir_normal->z = tmp.z;
	return (1);
}
