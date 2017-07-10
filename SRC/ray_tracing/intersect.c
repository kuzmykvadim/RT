/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:57:54 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:37:39 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

t_color		recur(t_rtv1 *rtv1, t_vector *origin, t_vector *dir, int depth, t_color color)
{
	int 		i;
	int			num_obj;
	int			hit;
	double		t0;
	double		t1;
	double		cos_i;
	// t_color		color;
	t_vector	normal;
	t_vector	point;
	t_vector	dir_point;

	i = -1;
	num_obj = -1;
	t0 = 2000000.0f;

	if (depth > 2)
		return (color);

	set_vector(RAY_ORIGIN, origin);
	set_vector(RAY_DIRECTION, dir);
	while (++i < SIZE_OBJ)
	{
		t1 = 2000000.0f;
		hit = check_intersect_object(RT, &t1, i, RT->ray);
		if (hit != 0 && t1 < t0)
		{
			t0 = t1;
			num_obj = i;
		}
	}
	if (num_obj == -1) // ЕСЛИ ПЕРЕСЕЧЕНИЕ НЕТУ ВЕРНУТЬ ПРЕДИДУЩИЙ
		return (color);
	else if (num_obj != -1)/// ЕСЛИ ПЕРЕСЕЧЕНИЕ ЕСТЬ УСТАНОВИТЬ НОВЫЙ ЦВЕТ
		color = ft_light(RT, &t0, num_obj);
	if (RT->rt_obj[num_obj].id == 's') // ЕСЛИ ОБЬЕКТ ТИПО ОТЗЕРКАЛИВАЕТ ТО ВЫЧИСЛИТЬ новый дир и поинт
	{
		point = find_point_intersect(RT, &t0);
		normal = get_intersect_normal(RT, num_obj, &point);
		cos_i = dot_vector(&normal, RAY_DIRECTION);
		t_vector hui = scalar_vector(2 * cos_i, &normal);
		dir_point = sub_vector(&point, &hui);
		dir_point = normal_vector(dir_point);
		set_vector(dir, &dir_point);
		set_vector(origin, &point);
		return (recur(rtv1, origin, dir, (depth + 1), color));
	}
	return (color);
}

t_color		intersect(t_rtv1 *rtv1)
{

	t_val_intersect	val;
	t_val_math		val_t;
	t_color			color;

	color.red = 0;
	color.blue = 0;
	color.green = 0;
	color = recur(rtv1, RAY_ORIGIN, RAY_DIRECTION, 1, color);
	color.red = MIN(color.red * 255.0f, 255.0f);
	color.blue = MIN(color.blue * 255.0f, 255.0f);
	color.green = MIN(color.green * 255.0f, 255.0f);
	return (color);
}

// t_color		intersect(t_rtv1 *rtv1)
// {
// 	t_val_intersect	val;
// 	t_val_math		val_t;
// 	t_color			color;
//
// 	val.i = -1;
// 	val.num_obj = -1;
// 	val_t.t0 = 2000000.0f;
// 	while (++val.i < SIZE_OBJ)
// 	{
// 		val_t.t1 = 2000000.0f;
// 		val.hit = check_intersect_object(RT, &val_t.t1, val.i, RT->ray);
// 		if (val.hit != 0 && val_t.t1 < val_t.t0)
// 		{
// 			val_t.t0 = val_t.t1;
// 			val.num_obj = val.i;
// 		}
// 	}
// 	 if (val.num_obj != -1 && OPTION.light_off_on == 1)
// 		color = ft_light(RT, &val_t.t0, val.num_obj);
// 	else if (val.num_obj != -1 && OPTION.light_off_on == 0)
// 		color = get_color(RT, val.num_obj);
// 	else
// 		set_color(&color, BACKGROUND.red, BACKGROUND.blue, BACKGROUND.green);
// 	color.red = MIN(color.red * 255.0f, 255.0f);
// 	color.blue = MIN(color.blue * 255.0f, 255.0f);
// 	color.green = MIN(color.green * 255.0f, 255.0f);
// 	return (color);
// }
