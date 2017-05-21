/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:23:10 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 21:42:53 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_rt.h"

t_light		*create_all_light(int size)
{
	t_light		*new;
	int			i;

	i = 0;
	new = (t_light*)malloc(sizeof(t_light) * size + 1);
	while (i < size)
	{
		new[i].position = create_vector();
		i++;
	}
	return (new);
}
