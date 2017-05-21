/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:45:36 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 21:43:50 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

static t_type	*create_demo(int size)
{
	t_type		*type;
	int			i;

	type = (t_type*)malloc(sizeof(t_type) * size + 1);
	i = 0;
	type[0].name = "Sphere";
	type[1].name = "Sphere";
	type[2].name = "Sphere";
	type[3].name = "Plane";
	type[4].name = "Plane";
	type[5].name = "Cylinder";
	type[6].name = "Cone";
	type[7].name = "Plane";
	type[8].name = "Plane";
	return (type);
}

static void		demo_init(t_rtv1 *rtv1)
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

t_object		*create_rt_obj(int size_obj)
{
	t_object	*new;
	t_type		*type;
	int			i;

	new = (t_object*)malloc(sizeof(t_object) * size_obj + 1);
	type = create_demo(size_obj);
	i = 0;
	while (i < size_obj)
	{
		if (strcmp(type[i].name, "Sphere") == 0)
			new[i].sphere = create_shpere();
		else if (strcmp(type[i].name, "Plane") == 0)
			new[i].plane = create_plane();
		else if (strcmp(type[i].name, "Cone") == 0)
			new[i].cone = create_cone();
		else if (strcmp(type[i].name, "Cylinder") == 0)
			new[i].cylinder = create_cylinder();
		i++;
	}
	free(type);
	return (new);
}

t_rtv1			*create_rtv1(void)
{
	t_rtv1		*rtv1;

	rtv1 = (t_rtv1*)malloc(sizeof(t_rtv1));
	rtv1->size_obj = 9;
	rtv1->size_light = 3;
	rtv1->light_off_on = 0;
	rtv1->ray = create_ray();
	rtv1->light_ray = create_ray();
	rtv1->rt_obj = create_rt_obj(rtv1->size_obj);
	rtv1->obj = object_mlx();
	rtv1->light = create_all_light(rtv1->size_light);
	rtv1->screen = create_map();
	rtv1->screen2 = create_map();
	init_demo(rtv1);
	demo_init(rtv1);
	calc(RT, calc_norm_dir);
	return (rtv1);
}
