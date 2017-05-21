/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:48:32 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/29 19:48:32 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_rt.h"

t_sphere	*create_shpere(void)
{
	t_sphere	*sphere;

	sphere = (t_sphere*)malloc(sizeof(t_sphere) + 1);
	sphere->position = create_vector();
	return (sphere);
}
