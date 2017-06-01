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

void	ray_tracing(t_rtv1 *rtv1)
{
	t_val_vector	val;
	int				size;
	int				i;

	mlx_clear_window(MLX_MY, WIN_MY);
	rtv1->img = create_img(rtv1->obj);
	size = SIZE_X * SIZE_Y;
	i = 0;
	printf("start ray_tracing\n");
	if (module_check_in(rtv1, RAY_ORIGIN) == 1)
	{
		while (i < size)
		{
			RT->x = X;
			RT->y = Y;
			RAY_DIRECTION->x = RT->screen[i].dir_normal->x;
			RAY_DIRECTION->y = RT->screen[i].dir_normal->y;
			RAY_DIRECTION->z = RT->screen[i].dir_normal->z;
			val.color = intersect(rtv1);
			put_img(rtv1->img, X, Y, &val.color);
			i++;
		}
	}
	PUT_IMG_WIN(MLX_MY, WIN_MY, rtv1->img->img, 0, 0);
	free(rtv1->img);
	printf("end ray_tracing\n");
}
