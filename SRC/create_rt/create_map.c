/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:44:13 by asvirido          #+#    #+#             */
/*   Updated: 2017/02/09 16:44:16 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_rt.h"

t_screen	*create_map(void)
{
	t_screen	*new;
	int			y;
	int			i;
	int			x;

	i = 0;
	y = 0;
	x = 0;
	new = (t_screen*)malloc(sizeof(t_screen) * (SIZE_Y * SIZE_X) + 1);
	while (y < SIZE_Y)
	{
		new[i].ray = create_vector();
		new[i].dir_normal = create_vector();
		(x == SIZE_X ? y += 1 : 0);
		(x == SIZE_X ? x = 0 : 0);
		new[i].ray->x = x;
		new[i].ray->y = y;
		new[i].ray->z = 0.99;
		x++;
		i++;
	}
	return (new);
}
