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

	vect.x = (x + 0.1) / OPTION.size_x;
	vect.y = (y + 0.1) / OPTION.size_y;
	vect.x = (2 * vect.x) - 1;
	vect.y = 1 - (2 * vect.y);
	vect.x *= (OPTION.size_x / (double)OPTION.size_y) * tan((OPTION.fov / 2) * RAD);
	vect.y *= tan((OPTION.fov / 2) * RAD);
	vect.z = 1;
	set_vector(RAY_DIRECTION, &vect);
}

void 	effect_filtres(t_rtv1 *rtv1)
{
	int		i;
	t_color	color;

	i = -1;
	while (++i < OPTION.size_screen)
	{
		if (OPTION.sepia == TRUE)
			color = sepia(*RT->screen[i].color);
		else if (OPTION.black_and_white == TRUE)
			color = black_and_white(*RT->screen[i].color);
		else if (OPTION.darkroom == TRUE)
			color = darkroom(*RT->screen[i].color);
		else
			continue ;
		RT->screen[i].color->red = color.red;
		RT->screen[i].color->blue = color.blue;
		RT->screen[i].color->green = color.green;
	}
}

void		ft_ssaa(t_rtv1 *rtv1, int i, t_color *res)
{
	t_color		color[OPTION.size_ssaa + 1];
	int			j;

	j = -1;
	res->red = 0;
	res->green = 0;
	res->blue = 0;
	while (++j < OPTION.size_ssaa)
	{
		set_vector(RAY_DIRECTION, &DIR_NORMAL);
		color[j] = intersect(rtv1);
	}
	midle_color(color, OPTION.size_ssaa, res);
}

void		just_rt(t_rtv1 *rtv1, int i, t_color *res)
{
	t_color		color;
	int			j;

	j = 0;
	color.red = 0;
	color.blue = 0;
	color.green = 0;
	set_vector(RAY_DIRECTION, &DIR_NORMAL);
	if ((int)X % OPTION.draft_x == 0 && (int)Y % OPTION.draft_y == 0)
	{
		(OPTION.fov_on == TRUE ? fov(RT, X, Y) : 0);
		color = intersect(rtv1);
	}
	res->red = color.red;
	res->blue = color.blue;
	res->green = color.green;
}

void 	motion_blur(t_rtv1 *rtv1)
{
	int			i;
	int			k;
	int			y;
	int			len;
	t_color		blur[OPTION.size_blur + 1];

	i = -1;
	while (++i < OPTION.size_screen)
	{
		k = -1;
		y = RT->screen[i].ray->y;
		while (++k < OPTION.size_blur)
		{
			len = i + k;
			if (len >= OPTION.size_screen || RT->screen[len].ray->y != y)
				len = i;
			blur[k].red = RT->screen[len].color->red;
			blur[k].green = RT->screen[len].color->green;
			blur[k].blue = RT->screen[len].color->blue;
		}
		midle_color(blur, k, RT->screen[i].color);
	}
}

void 	draw_rt(t_rtv1 *rtv1)
{
	int		i;

	i = -1;
	while (++i < OPTION.size_screen)
		put_img(rtv1->img, X, Y, RT->screen[i].color);
}

void	ray_tracing(t_rtv1 *rtv1)
{
	t_val_vector	val;
	int				i;

	mlx_clear_window(MLX_MY, WIN_MY);
	rtv1->img = create_img(rtv1->obj);
	i = -1;
	if (module_check_in(rtv1, RAY_ORIGIN) == 1)
	{
		while (++i < OPTION.size_screen)
		{
			if (OPTION.ssaa == 1)
				ft_ssaa(RT, i, RT->screen[i].color);
			else if (OPTION.ssaa == 0)
				just_rt(RT, i, RT->screen[i].color);
		}
	}
	if (OPTION.motion_blur == TRUE)
		motion_blur(RT);
	if (OPTION.filters == TRUE)
		effect_filtres(RT);
	draw_rt(RT);
	PUT_IMG_WIN(MLX_MY, WIN_MY, rtv1->img->img, 0, 0);
	free(rtv1->img);
}
