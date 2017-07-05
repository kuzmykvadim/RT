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

void		init_sphere_1(t_rtv1 *rtv1)
{
	double	radius;

	radius = 29;
	rtv1->rt_obj[0].sphere->radius = radius;
	rtv1->rt_obj[0].sphere->radius_pow = radius * radius;
	construct_vector(rtv1->rt_obj[0].sphere->position, 200, 10, 400);
	radius = 150;
	rtv1->rt_obj[1].sphere->radius = radius;
	rtv1->rt_obj[1].sphere->radius_pow = radius * radius;
	construct_vector(rtv1->rt_obj[1].sphere->position, 400, 400, 200);
	radius = 50;
	rtv1->rt_obj[2].sphere->radius = radius;
	rtv1->rt_obj[2].sphere->radius_pow = radius * radius;
	construct_vector(rtv1->rt_obj[2].sphere->position, 200, 50, 400);
}

void		init_2(t_rtv1 *rtv1)
{
	double		radius;
	t_vector	tmp;

	radius = 50;
	construct_vector(rtv1->rt_obj[5].cylinder->position, 400, 600, 200);
	construct_vector(rtv1->rt_obj[5].cylinder->direction, 0, 0, 1);
	rtv1->rt_obj[5].cylinder->radius = radius;
	rtv1->rt_obj[5].cylinder->radius_pow = radius * radius;
	rtv1->rt_obj[3].plane->distance = -900;
	rtv1->rt_obj[4].plane->distance = -900.1;
	construct_vector(rtv1->rt_obj[3].plane->normal, 0, 1, 0);
	construct_vector(rtv1->rt_obj[4].plane->normal, 0, 1, 0);
	tmp = normal_vector(*rtv1->rt_obj[3].plane->normal);
	set_vector(rtv1->rt_obj[3].plane->normal, &tmp);
	tmp = normal_vector(*rtv1->rt_obj[4].plane->normal);
	set_vector(rtv1->rt_obj[4].plane->normal, &tmp);
	tmp = normal_vector(*rtv1->rt_obj[5].cylinder->direction);
	set_vector(rtv1->rt_obj[5].cylinder->direction, &tmp);
}

void		init_1(t_rtv1 *rtv1)
{
	t_vector	tmp;

	rtv1->rt_obj[7].plane->distance = -600;
	rtv1->rt_obj[8].plane->distance = -600.1;
	construct_vector(rtv1->rt_obj[7].plane->normal, 0, 0, 1);
	construct_vector(rtv1->rt_obj[8].plane->normal, 0, 0, 1);
	tmp = normal_vector(*rtv1->rt_obj[7].plane->normal);
	set_vector(rtv1->rt_obj[7].plane->normal, &tmp);
	tmp = normal_vector(*rtv1->rt_obj[8].plane->normal);
	set_vector(rtv1->rt_obj[8].plane->normal, &tmp);
	construct_vector(rtv1->rt_obj[9].disk->normal, 0, 1, 0);
	construct_vector(rtv1->rt_obj[9].disk->position, 0, 400, -2000);
	rtv1->rt_obj[9].disk->radius = 600;
}

void 	calc_normal_poligon(t_poligon *p)
{
	t_vector	res_1;
	t_vector	res_2;
	t_vector	n;

	res_1 = sub_vector(p->v1, p->v0);
	res_2 = sub_vector(p->v2, p->v0);
	n = product_vectors(&res_1, &res_2);
	set_vector(p->normal, &n);
}

void		init_cone_1(t_rtv1 *rtv1)
{
	double		angle;
	t_vector	tmp;

	angle = 35;
	construct_vector(rtv1->rt_obj[6].cone->position, 100, 300, 500);
	construct_vector(rtv1->rt_obj[6].cone->direction, 0, 1, 0);
	rtv1->rt_obj[6].cone->angle = angle;
	angle *= RAD;
	rtv1->rt_obj[6].cone->cone_cos_two = cos(angle) * cos(angle);
	rtv1->rt_obj[6].cone->cone_sin_two = sin(angle) * sin(angle);
	rtv1->rt_obj[6].cone->two_cone_cos_two = 2 * (cos(angle) * cos(angle));
	rtv1->rt_obj[6].cone->two_cone_sin_two = 2 * (sin(angle) * sin(angle));
	tmp = normal_vector(*rtv1->rt_obj[6].cone->direction);
	set_vector(rtv1->rt_obj[6].cone->direction, &tmp);

	//POLIGON
	// construct_vector(rtv1->rt_obj[10].poligon->v0, 400, 600, 400);
	// construct_vector(rtv1->rt_obj[10].poligon->v1, 200, 400, 400);
	// construct_vector(rtv1->rt_obj[10].poligon->v2, 600, 500, 400);
	construct_vector(rtv1->rt_obj[10].poligon->v0, 400, 600, 400);
	construct_vector(rtv1->rt_obj[10].poligon->v1, 200, 400, 400);
	construct_vector(rtv1->rt_obj[10].poligon->v2, 600, 500, 400);
	// construct_vector(rtv1->rt_obj[10].poligon->v0, 500, 500, -600);
	// construct_vector(rtv1->rt_obj[10].poligon->v1, 300, 600, -600);
	// construct_vector(rtv1->rt_obj[10].poligon->v2, 700, 600, -600);
	calc_normal_poligon(rtv1->rt_obj[10].poligon);
	/////////////////////////////////////////////////
	// HALF_SPHERE	///////////////////
	/////////////////////////////////
	///
	double	r = 150;
	rtv1->rt_obj[11].half_sphere->radius = r;
	rtv1->rt_obj[11].half_sphere->n = 1;
	rtv1->rt_obj[11].half_sphere->radius_pow = r * r;
	construct_vector(rtv1->rt_obj[11].half_sphere->position, 200, 400, -9000);
	construct_vector(rtv1->rt_obj[11].half_sphere->normal, 1, 0, 0);
	t_vector	tmp1;

	tmp1 = normal_vector(*rtv1->rt_obj[11].half_sphere->normal);
	set_vector(rtv1->rt_obj[11].half_sphere->normal, &tmp1);
	//// PLANE LIMIT ////////////
	/////////////////////
//	construct_vector(rtv1->rt_obj[13].plane_limit->position, 0, 600, -1200);
	construct_vector(rtv1->rt_obj[12].plane_limit->position, 800, 600, -800);
//	construct_vector(rtv1->rt_obj[13].plane_limit->rotation, 30, 0, 0);
	rtv1->rt_obj[12].plane_limit->height = 50000;
	rtv1->rt_obj[12].plane_limit->weight = 50000;
	//////////////////////////////////
}

void 	init_color(t_rtv1 *rtv1)
{
	rtv1->rt_obj[0].color = create_color(0x990077);
	rtv1->rt_obj[1].color = create_color(0x990077);
	rtv1->rt_obj[2].color = create_color(0xfffa00);
	rtv1->rt_obj[3].color = create_color(0x4F4F4F);
	rtv1->rt_obj[4].color = create_color(0x4F4F4F);
	rtv1->rt_obj[5].color = create_color(0x991111);
	rtv1->rt_obj[6].color = create_color(0xCC001B);
	rtv1->rt_obj[7].color = create_color(0x000077);
	rtv1->rt_obj[8].color = create_color(0x000077);
	rtv1->rt_obj[9].color = create_color(0x991111);
	rtv1->rt_obj[10].color = create_color(0x008800);
	rtv1->rt_obj[11].color = create_color(0x6546e2);
	rtv1->rt_obj[12].color = create_color(0xFFFFFF);
	int i = 0;
	while (i <= 12)
	{
		rtv1->rt_obj[i].color.red *= 0.00255;
		rtv1->rt_obj[i].color.blue *= 0.00255;
		rtv1->rt_obj[i].color.green *= 0.00255;
		i++;
	}
}

void 	init_rotation(t_rtv1 *rtv1)
{
	construct_vector(RT->rt_obj[0].rotation, 0, 0, 0);
	construct_vector(RT->rt_obj[1].rotation, 0, 0, 0);
	construct_vector(RT->rt_obj[2].rotation, 0, 0, 0);
	construct_vector(RT->rt_obj[3].rotation, 0, 0, 0);
	construct_vector(RT->rt_obj[4].rotation, 0, 0, 0);
	construct_vector(RT->rt_obj[5].rotation, 0, 0, 0);
	construct_vector(RT->rt_obj[6].rotation, 15, 0, 0);
	construct_vector(RT->rt_obj[7].rotation, 0, 0, 0);
	construct_vector(RT->rt_obj[8].rotation, 0, 0, 0);
	construct_vector(RT->rt_obj[9].rotation, 0, 0, 0);
	construct_vector(RT->rt_obj[10].rotation, 0, 0, 0);
	construct_vector(RT->rt_obj[11].rotation, 0, 0, 0);
	construct_vector(RT->rt_obj[12].rotation, 0, 0, 0);
}

void		init_demo(t_rtv1 *rtv1)
{
	init_sphere_1(rtv1);
	init_2(rtv1);
	init_1(rtv1);
	init_cone_1(rtv1);
	init_color(RT);
	init_rotation(RT);
	construct_vector(rtv1->ray->origin, 400.99, 400.99, -900.99);
	construct_vector(rtv1->light[0].position, 400.99, 400.99, -800.99);
	rtv1->light[0].color = create_color(0xFFFFFF);
	construct_vector(rtv1->light[1].position, 0.99, 0.99, -800.99);
	rtv1->light[1].color = create_color(0xffffff);
	construct_vector(rtv1->light[2].position, 800.99, 0.99, -900.99);
	rtv1->light[2].color = create_color(0xffffff);
}
