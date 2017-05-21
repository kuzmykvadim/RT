/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:33:58 by asvirido          #+#    #+#             */
/*   Updated: 2017/04/13 19:33:59 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_rt.h"

t_plane		*create_plane(void)
{
	t_plane	*plane;

	plane = (t_plane*)malloc(sizeof(t_plane) + 1);
	plane->normal = create_vector();
	return (plane);
}
