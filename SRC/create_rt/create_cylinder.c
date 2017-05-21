/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 14:06:51 by asvirido          #+#    #+#             */
/*   Updated: 2017/04/26 14:06:52 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_rt.h"

t_cylinder	*create_cylinder(void)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder*)malloc(sizeof(t_cylinder) + 1);
	cylinder->position = create_vector();
	cylinder->direction = create_vector();
	return (cylinder);
}
