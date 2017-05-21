/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:30:27 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 21:53:18 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void		demo_init_scene_1(t_rtv1 *rtv1, int keycode)
{
	if (keycode == 18)
	{
		rtv1->rt_obj[1].of_on = 1;
		rtv1->rt_obj[0].of_on = 0;
		rtv1->rt_obj[2].of_on = 0;
		rtv1->rt_obj[3].of_on = 0;
		rtv1->rt_obj[4].of_on = 0;
		rtv1->rt_obj[5].of_on = 0;
		rtv1->rt_obj[6].of_on = 0;
		rtv1->rt_obj[7].of_on = 0;
		rtv1->rt_obj[8].of_on = 0;
	}
	else if (keycode == 19)
	{
		rtv1->rt_obj[1].of_on = 1;
		rtv1->rt_obj[0].of_on = 1;
		rtv1->rt_obj[2].of_on = 1;
		rtv1->rt_obj[3].of_on = 0;
		rtv1->rt_obj[4].of_on = 0;
		rtv1->rt_obj[5].of_on = 0;
		rtv1->rt_obj[6].of_on = 0;
		rtv1->rt_obj[7].of_on = 0;
		rtv1->rt_obj[8].of_on = 0;
	}
}

void		demo_init_scene_2(t_rtv1 *rtv1, int keycode)
{
	if (keycode == 21)
	{
		rtv1->rt_obj[1].of_on = 0;
		rtv1->rt_obj[0].of_on = 0;
		rtv1->rt_obj[2].of_on = 0;
		rtv1->rt_obj[3].of_on = 0;
		rtv1->rt_obj[4].of_on = 0;
		rtv1->rt_obj[5].of_on = 0;
		rtv1->rt_obj[6].of_on = 1;
		rtv1->rt_obj[7].of_on = 0;
		rtv1->rt_obj[8].of_on = 0;
	}
	else if (keycode == 20)
	{
		rtv1->rt_obj[0].of_on = 0;
		rtv1->rt_obj[1].of_on = 0;
		rtv1->rt_obj[2].of_on = 0;
		rtv1->rt_obj[3].of_on = 0;
		rtv1->rt_obj[4].of_on = 0;
		rtv1->rt_obj[5].of_on = 1;
		rtv1->rt_obj[6].of_on = 0;
		rtv1->rt_obj[7].of_on = 0;
		rtv1->rt_obj[8].of_on = 0;
	}
}

void		demo_init_scene_3(t_rtv1 *rtv1, int keycode)
{
	if (keycode == 22)
	{
		rtv1->rt_obj[1].of_on = 1;
		rtv1->rt_obj[0].of_on = 0;
		rtv1->rt_obj[2].of_on = 0;
		rtv1->rt_obj[3].of_on = 1;
		rtv1->rt_obj[4].of_on = 1;
		rtv1->rt_obj[5].of_on = 0;
		rtv1->rt_obj[6].of_on = 0;
		rtv1->rt_obj[7].of_on = 1;
		rtv1->rt_obj[8].of_on = 1;
	}
	else if (keycode == 23)
	{
		rtv1->rt_obj[0].of_on = 1;
		rtv1->rt_obj[1].of_on = 1;
		rtv1->rt_obj[2].of_on = 1;
		rtv1->rt_obj[3].of_on = 1;
		rtv1->rt_obj[4].of_on = 1;
		rtv1->rt_obj[5].of_on = 1;
		rtv1->rt_obj[6].of_on = 1;
		rtv1->rt_obj[7].of_on = 1;
		rtv1->rt_obj[8].of_on = 1;
	}
}

int			event_key(int keycode, t_rtv1 *rt)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 36)
	{
		rt->light_off_on = (rt->light_off_on == 0 ? 1 : 0);
		ray_tracing(rt);
	}
	else if (keycode == 18 || keycode == 19)
	{
		demo_init_scene_1(rt, keycode);
		ray_tracing(rt);
	}
	else if (keycode == 20 || keycode == 21)
	{
		demo_init_scene_2(rt, keycode);
		ray_tracing(rt);
	}
	else if (keycode == 22 || keycode == 23)
	{
		demo_init_scene_3(rt, keycode);
		ray_tracing(rt);
	}
	return (1);
}
