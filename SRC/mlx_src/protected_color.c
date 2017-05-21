/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:54:38 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:31:27 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_src.h"

void	protected_color(t_color *color)
{
	if (color->red > 255)
		color->red = 255;
	if (color->blue > 255)
		color->blue = 255;
	if (color->green > 255)
		color->green = 255;
}
