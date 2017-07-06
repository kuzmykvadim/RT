/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:01:51 by asvirido          #+#    #+#             */
/*   Updated: 2017/07/06 16:01:52 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 	"mlx_src.h"

t_color		get_pix(t_img *img, int x, int y)
{
	int		pix;
	t_color	color;

	if ((y >= 0 && x >= 0) && (y < SIZE_Y && x < SIZE_X))
	{
		pix = y * img->size_line + x * 4;
		if (x < SIZE_Y * SIZE_X * 4)
		{
			color.blue = img->line[pix];
			color.green = img->line[pix + 1];
			color.red = img->line[pix + 2];
		}
	}
	return (color);
}
