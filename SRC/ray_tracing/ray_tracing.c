/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:11:53 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:25:23 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void 	fov(t_rtv1 *rtv1, int x, int y)
{
	t_vector vect;

	vect.x = (x + 0.1) / SIZE_X;
	vect.y = (y + 0.1) / SIZE_Y;
	vect.x = (2 * vect.x) - 1;
	vect.y = 1 - (2 * vect.y);
	vect.x *= (SIZE_X / (double)SIZE_Y) * tan((OPTION.fov / 2) * RAD);
	vect.y *= tan((OPTION.fov / 2) * RAD);
	vect.z = 1;
	set_vector(RAY_DIRECTION, &vect);
}

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

t_color 	effect_filtres(t_rtv1 *rtv1, t_color color)
{
	t_color new;

	new.red = 0;
	new.green = 0;
	new.blue = 0;
	if (OPTION.sepia == TRUE)
		new = sepia(color);
	else if (OPTION.black_and_white == TRUE)
		new = black_and_white(color);
	else if (OPTION.darkroom == TRUE)
		new = darkroom(color);
	return (new);
}

void	ray_tracing(t_rtv1 *rtv1)
{
	t_val_vector	val;
	t_vector		tmp;
	int				i;

	mlx_clear_window(MLX_MY, WIN_MY);
	rtv1->img = create_img(rtv1->obj);
	i = 0;
	if (module_check_in(rtv1, RAY_ORIGIN) == 1)
	{
		while (i < SIZE)
		{
			//t_vector tmp = normal_vector(sub_vector(RT->screen[i].ray, RAY_ORIGIN));
			set_vector(RAY_DIRECTION, DIR_NORMAL);
			(OPTION.fov_on == TRUE ? fov(RT, X, Y) : 0);
			if ((int)X % OPTION.draft_x == 0 && (int)Y % OPTION.draft_y == 0)
			{
				val.color = intersect(rtv1);
				if (OPTION.filters == TRUE)
					val.color = effect_filtres(RT, val.color);
				put_img(rtv1->img, X, Y, &val.color);
			 }
			i++;
		}
	}
	PUT_IMG_WIN(MLX_MY, WIN_MY, rtv1->img->img, 0, 0);
	free(rtv1->img);
}
