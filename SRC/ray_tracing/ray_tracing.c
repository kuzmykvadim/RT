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

void 	effect_filtres(t_rtv1 *rtv1)
{
	int		i;
	t_color	color;

	i = -1;
	while (++i < OPTION->size_screen)
	{
		if (OPTION->sepia == TRUE)
			color = sepia(*RT->screen[i].color);
		else if (OPTION->black_and_white == TRUE)
			color = black_and_white(*RT->screen[i].color);
		else if (OPTION->darkroom == TRUE)
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
	t_color		color[OPTION->size_ssaa + 1];
	int			j;

	j = -1;
	res->red = 0;
	res->green = 0;
	res->blue = 0;
	while (++j < OPTION->size_ssaa)
	{
		set_vector(RAY_ORIGIN, RT->pos);
		set_vector(RAY_DIRECTION, &DIR_NORMAL);
		color[j] = intersect(rtv1);
	}
	midle_color(color, OPTION->size_ssaa, res);
}
#include <unistd.h>
void		just_rt(t_rtv1 *rtv1, int i, t_color *res)
{
	t_color		color;
	int			j;

	j = 0;
	color.red = 0;
	color.blue = 0;
	color.green = 0;
	set_vector(RAY_DIRECTION, &DIR_NORMAL);
	set_vector(RAY_ORIGIN, RT->pos);
	if ((int)X % OPTION->draft_x == 0 && (int)Y % OPTION->draft_y == 0)
	{
		// (OPTION->fov_on == TRUE ? fov(RT, X, Y) : 0);
		color = intersect(rtv1);
	}
	res->red = color.red;
	res->blue = color.blue;
	res->green = color.green;
}

void 	draw_rt(t_rtv1 *rtv1)
{
	int		i;

	i = -1;
	while (++i < OPTION->size_screen)
		put_img(rtv1->img, X, Y, RT->screen[i].color);
}

void	ray_tracing(t_rtv1 *rtv1)
{
	t_val_vector	val;
	int				i;

	mlx_clear_window(MLX_MY, WIN_MY);
	rtv1->img = create_img(rtv1->obj);
	system("clear");
	i = -1;
	RT->count = 0;
	RT->loading_progress = 0;
	while (++i < OPTION->size_screen)
	{
		RT->count++;
		if (RT->count == RT->procent_one)
		{
			RT->loading_progress++;
			RT->count = 0;
			printf("\r%s%s%d%s", GREEN, "Loading % ", RT->loading_progress, RESET);
			fflush(stdout);
		}
		if (OPTION->ssaa == 1)
			ft_ssaa(RT, i, RT->screen[i].color);
		else if (OPTION->ssaa == 0)
			just_rt(RT, i, RT->screen[i].color);
	}
	if (OPTION->motion_blur == TRUE)
		motion_blur(RT);
	if (OPTION->filters == TRUE)
		effect_filtres(RT);
	draw_rt(RT);
	PUT_IMG_WIN(MLX_MY, WIN_MY, rtv1->img->img, 0, 0);
	free(rtv1->img);
}
