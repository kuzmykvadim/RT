/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:53:07 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:47:41 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

double	ambient(double material, double power_light)
{
	return (material * power_light);
}
