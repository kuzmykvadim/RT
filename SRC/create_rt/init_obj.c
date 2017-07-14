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

// void		init_size(t_rtv1 *rtv1)
// {
// 	rtv1->rt_obj[0].size = 29;//  S
// 	rtv1->rt_obj[1].size = 150;// S
// 	rtv1->rt_obj[2].size = 50; // S
// 	rtv1->rt_obj[3].size = 300;// CYLINDER
// 	rtv1->rt_obj[4].size = 1;// CONE
// 	rtv1->rt_obj[5].size = 300; // DICK
// }
// double 	find_half_radius(double radius_sphere_two, double len_two)
// {
// 	return (sqrt(radius_sphere_two - len_two));
// }

// 	t_vector	tmp3 = sub_vector(rtv1->rt_obj[11].half_sphere->position, rtv1->rt_obj[11].half_sphere->position);
// 	rtv1->rt_obj[11].half_sphere->len = module_vector(&tmp3);
// 	rtv1->rt_obj[11].half_sphere->len_two = module_vector(&tmp3) * module_vector(&tmp3);
// 	rtv1->rt_obj[11].half_sphere->radius_disc = find_half_radius(rtv1->rt_obj[11].half_sphere->radius_pow, rtv1->rt_obj[11].half_sphere->len_two);

// void 	init_position(t_rtv1 *rtv1)
// {
// 	construct_vector(rtv1->rt_obj[0].position, 200, 10, 400); // s
// 	construct_vector(rtv1->rt_obj[1].position, -100, 400, -900);// s
// 	construct_vector(rtv1->rt_obj[2].position, 200, 50, 400); // s
// 	construct_vector(rtv1->rt_obj[3].position, 0, 0, 0); // CYLINDER
// 	construct_vector(rtv1->rt_obj[4].position, 100, 300, 500); // CONE
// 	construct_vector(rtv1->rt_obj[5].position, -400, 200, -2500); // D
// 	construct_vector(rtv1->rt_obj[6].position, 0, 0, 0);
// 	construct_vector(rtv1->rt_obj[7].position, 0, 0, 0);
// 	construct_vector(rtv1->rt_obj[8].position, 400, 600, 200); // P
// }

// void 	init_direction(t_rtv1 *rtv1)
// {
// 	construct_vector(rtv1->rt_obj[0].direction, 0, 0, 0); // s
// 	construct_vector(rtv1->rt_obj[1].direction, 0, 0, 0);// s
// 	construct_vector(rtv1->rt_obj[2].direction, 0, 0, 0); // s
// 	construct_vector(rtv1->rt_obj[3].direction, 0, 0, 1); // CYLINDER
// 	construct_vector(rtv1->rt_obj[4].direction, 0, 1, 0); // CONE
// 	construct_vector(rtv1->rt_obj[5].direction, 0, 1, 0); // D
// 	construct_vector(rtv1->rt_obj[6].direction, 0, 0, 0);
// 	construct_vector(rtv1->rt_obj[7].direction, 0, 0, 0);
// 	construct_vector(rtv1->rt_obj[8].direction, 0, 1, 0); // P
// }


// void 	init_color(t_rtv1 *rtv1)
// {
// 	rtv1->rt_obj[0].color = create_color(0x990077);
// 	rtv1->rt_obj[1].color = create_color(0x990077);
// 	rtv1->rt_obj[2].color = create_color(0xfffa00);
// 	rtv1->rt_obj[3].color = create_color(0xFFAA55);
// 	rtv1->rt_obj[4].color = create_color(0x99FFAA);
// 	rtv1->rt_obj[5].color = create_color(0x991111);
// 	rtv1->rt_obj[6].color = create_color(0xCC001B);
// 	rtv1->rt_obj[7].color = create_color(0x000077);
// 	rtv1->rt_obj[8].color = create_color(0xFFFFFF);
// }

// void 	init_rotation(t_rtv1 *rtv1)
// {
// 	construct_vector(RT->rt_obj[0].rotation, 0, 0, 0);
// 	construct_vector(RT->rt_obj[1].rotation, 0, 0, 0);
// 	construct_vector(RT->rt_obj[2].rotation, 0, 0, 0);
// 	construct_vector(RT->rt_obj[3].rotation, 0, 0, 0);
// 	construct_vector(RT->rt_obj[4].rotation, 0, 0, 0);
// 	construct_vector(RT->rt_obj[5].rotation, 0, 0, 0);
// 	construct_vector(RT->rt_obj[6].rotation, 0, 0, 0);
// 	construct_vector(RT->rt_obj[7].rotation, 0, 0, 0);
// 	construct_vector(RT->rt_obj[8].rotation, 0, 0, 0);
// }

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
//
// void 	debiging(t_object object)
// {
// 	printf("id %d\n", object.id);
// 	printf("position[%f][%f][%f]\n",object.position->x,object.position->y,object.position->z);
// 	printf("direction[%f][%f][%f]\n",object.direction->x,object.direction->y,object.direction->z);
// 	printf("rotation[%f][%f][%f]\n",object.rotation->x,object.rotation->y,object.rotation->z);
// 	printf("color[%f][%f][%f]\n",object.color.red,object.color.green,object.color.blue);
// 	printf("size %f size_pow %f\n",object.size, object.size_pow);
// 	printf("cone_cos_two %f cone_sin_two %f\n",object.cone_cos_two, object.cone_sin_two);
// 	printf("2cone_cos_two %f 2cone_sin_two %f\n",object.two_cone_cos_two, object.two_cone_sin_two);
// }

void		init_demo(t_rtv1 *rtv1)
{
	// init_size(rtv1);
	// init_position(RT);
	// init_color(RT);
	// init_rotation(RT);
	// init_direction(RT);

	// construct_vector(rtv1->ray->origin, 400.99, 400.99, -1700.99);

	// construct_vector(rtv1->light[0].position, 400.99, 450.99, -2500.99);
	// construct_vector(rtv1->light[1].position, 0.99, 0.99, -800.99);
	// construct_vector(rtv1->light[2].position, 800.99, 0.99, -900.99);

	parsing_color(RT);
	parsing_direction(RT);
	parcing_size_pow(RT);
	parcing_cone(RT);
}
