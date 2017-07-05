/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:34:27 by asvirido          #+#    #+#             */
/*   Updated: 2017/06/17 16:34:28 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_src.h"

t_color		sepia(t_color a)
{
	t_color		new;

	new.red = (a.red * 0.393) + (a.green * 0.769) + (a.blue * 0.189);
	new.green = (a.red * 0.349) + (a.green * 0.689) + (a.blue * 0.168);
	new.blue = (a.red * 0.272) + (a.green * 0.534) + (a.blue * 0.131);
	protected_color(&new);
	return (new);
}
