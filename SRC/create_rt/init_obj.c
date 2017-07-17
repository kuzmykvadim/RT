/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 22:39:27 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/18 18:09:44 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

// double 	find_half_radius(double radius_sphere_two, double len_two)
// {
// 	return (sqrt(radius_sphere_two - len_two));
// }
//
// // 	t_vector	tmp3 = sub_vector(rtv1->rt_obj[11].half_sphere->position, rtv1->rt_obj[11].half_sphere->position);
// // 	rtv1->rt_obj[11].half_sphere->len = module_vector(&tmp3);
// // 	rtv1->rt_obj[11].half_sphere->len_two = module_vector(&tmp3) * module_vector(&tmp3);
// // 	rtv1->rt_obj[11].half_sphere->radius_disc = find_half_radius(rtv1->rt_obj[11].half_sphere->radius_pow, rtv1->rt_obj[11].half_sphere->len_two);


void 	parsing_color(t_rtv1 *rtv1)
{
	int 	num_obj;

	num_obj = -1;
	while (++num_obj <= SIZE_OBJ)
	{
		RT_OBJ.color.red *= 0.00255;
		RT_OBJ.color.blue *= 0.00255;
		RT_OBJ.color.green *= 0.00255;
	}
}

void 	parsing_direction(t_rtv1 *rtv1)
{
	int			num_obj;
	t_vector	tmp;

	num_obj = -1;
	while (++num_obj < SIZE_OBJ)
	{
		tmp = normal_vector(RT_OBJ.direction);
		set_vector(&RT_OBJ.direction, &tmp);
	}
}

void 	parcing_size_pow(t_rtv1 *rtv1)
{
	int		num_obj;

	num_obj = -1;
	while (++num_obj < SIZE_OBJ)
		RT_OBJ.size_pow = RT_OBJ.size * RT_OBJ.size;
}

// double 	find_half_radius(double radius_sphere_two, double len_two)
// {
// 	return (sqrt(radius_sphere_two - len_two));
// }
//
// // 	t_vector	tmp3 = sub_vector(rtv1->rt_obj[11].half_sphere->position, rtv1->rt_obj[11].half_sphere->position);
// // 	rtv1->rt_obj[11].half_sphere->len = module_vector(&tmp3);
// // 	rtv1->rt_obj[11].half_sphere->len_two = module_vector(&tmp3) * module_vector(&tmp3);
// // 	rtv1->rt_obj[11].half_sphere->radius_disc = find_half_radius(rtv1->rt_obj[11].half_sphere->radius_pow, rtv1->rt_obj[11].half_sphere->len_two);

void 	parcing_half_sphere(t_rtv1 *rtv1)
{
	int		num_obj;
	t_vector	tmp;
	double	len;

	num_obj = -1;
	while (++num_obj < SIZE_OBJ)
	{
		if (RT_OBJ.id == HALF_SPHERE)
		{
			tmp = sub_vector(&RT_OBJ.position, &RT_OBJ.position);
			len = module_vector(&tmp) * module_vector(&tmp);
			RT_OBJ.radius_disc = sqrt(RT_OBJ.size_pow - len);
		}
	}
}

void 	parcing_cone(t_rtv1 *rtv1)
{
	int		num_obj;
	double	angle;

	num_obj = -1;
	while (++num_obj < SIZE_OBJ)
	{
		if (RT_OBJ.id == CONE)
		{
			angle = RT_OBJ.size * RAD;
			RT_OBJ.cone_cos_two = cos(angle) * cos(angle);
			RT_OBJ.cone_sin_two = sin(angle) * sin(angle);
			RT_OBJ.two_cone_cos_two = 2 * (cos(angle) * cos(angle));
			RT_OBJ.two_cone_sin_two = 2 * (sin(angle) * sin(angle));
		}
	}
}

void 	parcing_cylinder_limit(t_rtv1 *rtv1)
{
	int		num_obj;
	double	angle;

	num_obj = -1;
	while (++num_obj < SIZE_OBJ)
	{
		if (RT_OBJ.id == CYLINDER)
		{
			set_vector(&RT_OBJ.position2, &RT_OBJ.position);
			set_vector(&RT_OBJ.position1, &RT_OBJ.position);
			RT_OBJ.position1.y -= RT_OBJ.height / 2;
			RT_OBJ.position2.y += RT_OBJ.height / 2;
		}
	}
}


void		init_demo(t_rtv1 *rtv1)
{
	parsing_color(RT);
	parcing_size_pow(RT);
	parsing_direction(RT);
	parcing_cone(RT);
	parcing_half_sphere(RT);
}
