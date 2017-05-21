/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:44:51 by asvirido          #+#    #+#             */
/*   Updated: 2017/04/26 18:44:52 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_rt.h"

t_cone	*create_cone(void)
{
	t_cone	*cone;

	cone = (t_cone*)malloc(sizeof(t_cone) + 1);
	cone->position = create_vector();
	cone->direction = create_vector();
	return (cone);
}
