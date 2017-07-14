/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:04:00 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:51:40 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

t_color		get_color(t_rtv1 *rtv1, int num_obj)
{
	t_color color;

	color.red = RT->data->all_obj[num_obj].color.red;
	color.blue = RT->data->all_obj[num_obj].color.blue;
	color.green = RT->data->all_obj[num_obj].color.green;
	// if (RT->rt_obj[num_obj].id == 'h')
	// {
	// 	if (RT->rt_obj[num_obj].half_sphere->light_n == 2)
	// 	{
	// 		color.red *= 0.9;
	// 		color.blue *= 0.9;//RT->rt_obj[num_obj].color.blue;
	// 		color.green *= 0.9;//RT->rt_obj[num_obj].color.green;
	// 	}
	// }
	return (color);
}
