/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:53:49 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:47:19 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

double	specular(double zerkal, double power_zerkal, double dot)
{
	return (zerkal * dot * power_zerkal);
}
