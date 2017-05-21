/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bleak.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:47:45 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:18:07 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_color		bleak(t_color color, t_color l, double alpha, double specular)
{
	color.red = (alpha * color.red * (1 - specular) + l.red * specular);
	color.blue = (alpha * color.blue * (1 - specular) + l.blue * specular);
	color.green = (alpha * color.green * (1 - specular) + l.green * specular);
	return (color);
}
