/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:23:14 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:21:20 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void 	lambert_light(t_rtv1 *rtv1, t_val_vector *val, int *hit)
{
	int			i;
	double		dot;
	double		lambert_component;
	t_vector	l_dir;

	i = -1;
	while (++i < SIZE_LIGHT)
	{
		l_dir = normal_vector(sub_vector(&val->point, L.position));
		dot = cos_vector(&val->n_point, &l_dir);
		lambert_component = MAX(dot, 0.0);
		val->rgb[i].red *= lambert_component;
		val->rgb[i].green *= lambert_component;
		val->rgb[i].blue *= lambert_component;
	}
}

static void 	color_multi(t_color *color, double a)
{
	color->red *= a;
	color->blue *= a;
	color->green *= a;
}

void 	cel_shaded(t_rtv1 *rtv1, t_val_vector *val, int *hit)
{
	int			i;
	double		dot;
	double		lambert_component;
	t_vector	l_dir;

	i = -1;
	while (++i < SIZE_LIGHT)
	{
		l_dir = normal_vector(sub_vector(&val->point, L.position));
		dot = cos_vector(&val->n_point, &l_dir);
		lambert_component = MAX(dot, 0.0);
		if (lambert_component > 0.95)
			continue ;
		else if (lambert_component > 0.5)
			color_multi(&val->rgb[i], 0.7);
		else if (lambert_component > 0.2)
			color_multi(&val->rgb[i], 0.2);
		else
			color_multi(&val->rgb[i], 0.05);
	}
}


void	view_point_or_normal(t_rtv1 *rtv1, t_val_vector *val)
{
	t_color		color;
	t_vector	n_point;
	int			i;

	i = -1;
	if (OPTION.view_point == TRUE)
		n_point = normal_vector(val->point);
	else
		set_vector(&n_point, &val->n_point);
	while (++i < SIZE_LIGHT)
	{
		val->rgb[i].red = fabs(n_point.x);
		val->rgb[i].green = fabs(n_point.y);
		val->rgb[i].blue = fabs(n_point.z);
	}
}

void 	blinn_fong_light(t_rtv1 *rtv1, t_val_vector *val, int *hit)
{
	// t_color 		ambient_light_color;
	// double shiness = 64;
	// ambient_light_color.red = 0.1;
	// ambient_light_color.green = 0.1;
	// ambient_light_color.blue = 0.1;
		///// БЛИННА
	// 	if (hit[i] == 0)
	// 			continue ;
	// 	 t_vector L_DIR = normal_vector(sub_vector(L.position, &val->point));
	// 	 L_DIR.x = -L_DIR.x;
	// 	 L_DIR.z = -L_DIR.z;
	// 	 L_DIR.y = -L_DIR.y;
	// 	double dot = cos_vector(&val->n_point, &L_DIR);
	// 	 double lambert_component = MAX(dot, 0.0);
	// 	 if (lambert_component >= 1)
	// 	 	lambert_component = 1;
	//
	// 	 t_color diffuse_light;
	// 	 diffuse_light.red = val->rgb[i].red * lambert_component;
	// 	 diffuse_light.blue = val->rgb[i].blue * lambert_component;
	// 	 diffuse_light.green = val->rgb[i].green * lambert_component;
	//
	// 	 t_vector eye_vec;
	// 	 eye_vec.x = -val->point.x;
	// 	 eye_vec.y = -val->point.y;
	// 	 eye_vec.z = -val->point.z;
	//
	// 	 t_vector R = normal_vector(eye_vec);
	// 	 t_vector halfwayVector = normal_vector(add_vector(&L_DIR, &R));
	// 	 float specular = pow(MAX(dot_vector(&halfwayVector, &val->n_point), 0.001f), shiness);
	// 	 if (specular >= 1)
	// 	 	specular = 1;
	// 	// t_color specular_light;
	// 	// specular_light.red = val->rgb[i].red * specular;
	// 	// specular_light.green = val->rgb[i].green * specular;
	// 	// specular_light.blue = val->rgb[i].blue * specular;
	// 	// val->rgb[i].red = (ambient_light_color.red  + diffuse_light.red + specular_light.red);
	// 	// val->rgb[i].green = (ambient_light_color.green  + diffuse_light.green + specular_light.green);
	// 	// val->rgb[i].blue = (ambient_light_color.blue  + diffuse_light.blue + specular_light.blue);
	// 	val->rgb[i].red =val->rgb[i].red * (0.1 + lambert_component + specular);
	// 	val->rgb[i].green = val->rgb[i].green * (0.1 + lambert_component + specular);
	// 	val->rgb[i].blue = val->rgb[i].blue * (0.1 + lambert_component + specular);
	// }
}

void	all_light(t_rtv1 *rtv1, t_val_vector *val, int *hit, int num_obj)
{
	if (OPTION.lambert_light == TRUE)
		lambert_light(RT, val, hit);
	else if (OPTION.cel_shaded == TRUE)
		cel_shaded(RT, val, hit);
	else if (OPTION.blinn_fong == TRUE)
		blinn_fong_light(RT, val, hit);
	else if (OPTION.view_normal || OPTION.view_point)
		view_point_or_normal(RT, val);
}
