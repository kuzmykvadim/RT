/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 21:48:20 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:48:28 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_color		shadow(t_color color, double power_shadow)
{
	color.red = color.red * power_shadow;
	color.green = color.green * power_shadow;
	color.blue = color.blue * power_shadow;
	return (color);
}
