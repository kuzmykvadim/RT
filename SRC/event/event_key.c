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

int			event_key(int keycode, t_rtv1 *rt)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 36)
	{
		rt->option.light_off_on = (rt->option.light_off_on == 0 ? 1 : 0);
		ray_tracing(rt);
	}
	return (1);
}
