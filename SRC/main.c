/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:14:08 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 21:31:52 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

void	ft_migr(t_rtv1 *rtv1, int keycode)
{
	if (keycode == 126)
		move_forward_camera(rtv1);
	else if (keycode == 125)
		move_back_camera(rtv1);
	else if (keycode == 123)
		move_right_camera(rtv1);
	else if (keycode == 124)
		move_left_camera(rtv1);
	else if (keycode == 69)
		move_down_camera(rtv1);
	else if (keycode == 78)
		move_up_camera(rtv1);
	else if (keycode == 16 || keycode == 4)
		rotation_x(rtv1, keycode);
	else if (keycode == 13 || keycode == 1)
		rotation_y(rtv1, keycode);
	else if (keycode == 0 || keycode == 2)
		rotation_z(rtv1, keycode);
	ray_tracing(rtv1);
}

int		plus(int keycode, t_rtv1 *rt)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124
		|| keycode == 69 || keycode == 78 || keycode == 4 || keycode == 16
		|| keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		ft_migr(rt, keycode);
	return (1);
}

void	mlx_use(t_rtv1 *rtv1)
{
	mlx_key_hook(WIN_MY, event_key, rtv1);
	mlx_hook(WIN_MY, 2, 5, plus, rtv1);
	mlx_mouse_hook(WIN_MY, event_mouse, rtv1);
	mlx_hook(WIN_MY, 17, 0, destroy, 0);
	mlx_loop(MLX_MY);
}

int		main(void)
{
	t_rtv1		*rtv1;

	rtv1 = create_rtv1();
	ray_tracing(rtv1);
	mlx_use(rtv1);
	return (0);
}
