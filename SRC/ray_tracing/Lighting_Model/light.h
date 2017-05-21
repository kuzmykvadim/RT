/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 22:57:13 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/09 22:57:14 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "../../mlx_src/mlx_src.h"

double	ambient(double	material, double power_light);
double	diffuse(double material, double power_light, double dot);
t_color shadow(t_color color, double power_shadow);
double	specular(double	zerkal, double power_zerkal, double dot);
t_color	bleak(t_color color, t_color l, double	alpha, double specular);
#endif
