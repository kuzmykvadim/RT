/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:53:22 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/03 17:53:23 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

double	diffuse(double material, double power_light, double dot)
{
	return (material * dot * power_light);
}
