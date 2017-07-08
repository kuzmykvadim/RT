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

	type = (t_type*)malloc(sizeof(t_type) * size + 1);
	type[0].name = "Sphere";
	type[1].name = "Sphere";
	type[2].name = "Sphere";
	type[3].name = "Plane";
	type[4].name = "Plane";
	type[5].name = "Cylinder";
	type[6].name = "Cone";
	type[7].name = "Plane";
	type[8].name = "Plane";
	type[9].name = "Disk";
	type[10].name = "Poligon";
	type[11].name = "Half_sphere";
	type[12].name = "Plane_Limit";
	return (type);
}

t_disk	*create_disk(void)
{
	t_disk	*disk;

	disk = (t_disk*)malloc(sizeof(t_disk) * 2);
	disk->position = create_vector();
	disk->normal = create_vector();
	return (disk);
}

t_half_sphere	*create_half_sphere(void)
{
	t_half_sphere 	*new;

	new = (t_half_sphere*)malloc(sizeof(t_half_sphere) + 1);
	new->position = create_vector();
	new->normal = create_vector();
	return (new);
}

t_poligon 	*create_poligon(void)
{
	t_poligon *poligon;

	poligon = (t_poligon*)malloc(sizeof(t_poligon) + 1);
	poligon->v0 = create_vector();
	poligon->v1 = create_vector();
	poligon->v2 = create_vector();
	poligon->normal = create_vector();
	return (poligon);
}

t_plane_limit	*create_plane_limit(void)
{
	t_plane_limit 	*new;

	new = (t_plane_limit*)malloc(sizeof(t_plane_limit) + 1);
	new->position = create_vector();
	new->rotation = create_vector();
	new->normal = create_vector();
	new->normal->y = 1;
	return (new);
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
		{
			new[i].sphere = create_shpere();
			new[i].id = 's';
			new[i].rotation = create_vector();
		}
		else if (strcmp(type[i].name, "Plane") == 0)
		{
			new[i].id = 'p';
			new[i].plane = create_plane();
			new[i].rotation = create_vector();
		}
		else if (strcmp(type[i].name, "Cone") == 0)
		{
			new[i].id = 'c';
			new[i].cone = create_cone();
			new[i].rotation = create_vector();
		}
		else if (strcmp(type[i].name, "Cylinder") == 0)
		{
			new[i].id = 'C';
			new[i].cylinder = create_cylinder();
			new[i].rotation = create_vector();
		}
		else if (strcmp(type[i].name, "Disk") == 0)
		{
			new[i].id = 'd';
			new[i].disk = create_disk();
			new[i].rotation = create_vector();
		}
		else if (strcmp(type[i].name, "Poligon") == 0)
		{
			new[i].id = 't';
			new[i].poligon = create_poligon();
			new[i].rotation = create_vector();
		}
		else if (strcmp(type[i].name, "Half_sphere") == 0)
		{
			new[i].id = 'h';
			new[i].half_sphere = create_half_sphere();
			new[i].rotation = create_vector();
		}
		else if (strcmp(type[i].name, "Plane_Limit") == 0)
		{
			new[i].id = 'l';
			new[i].plane_limit = create_plane_limit();
			new[i].rotation = create_vector();
		}
		i++;
	}
	free(type);
	return (new);
}

void 	option_init(t_rtv1 *rtv1)
{
	OPTION.light_off_on = 0;
	OPTION.color_background = create_color(0x000000);
	OPTION.draft_x = 1;
	OPTION.draft_y = 1;

	// ANTI_ALIASING
	OPTION.ssaa = 0; // ЕСЛИ ВКЛ SSAA то FXAA выкл
	OPTION.size_ssaa = 1; // ЕСЛИ OPTION.ssaa == 0 ТОГДА OPTION.size_ssaa ДОЛЖЕН БЫТЬ ОДИН
	OPTION.fxaa = 0; // ЕСЛИ ВКЛ FXAA то motion blur вкл и size blur == 2
	// LIGHT AND SHADOW
	OPTION.lambert_light = 0;
	OPTION.view_normal = 0;
	OPTION.view_point = 0;
	OPTION.cel_shaded = 0;
	OPTION.blinn_fong = 1;
	OPTION.shadow = 1;

	// FOV
	OPTION.fov_on = 0;
	OPTION.fov = 45;

	// MOTION_BLUR
	OPTION.motion_blur = 1;
	OPTION.size_blur = 15;

	OPTION.size_x = 800;
	OPTION.size_y = 600;
	OPTION.size_screen = OPTION.size_x * OPTION.size_y;
	OPTION.name_win = "RT";

	// filters
	OPTION.filters = 1;
	OPTION.sepia = 0;
	OPTION.black_and_white = 1;
	OPTION.darkroom = 0;
}

void 	valid_filters(t_rtv1 *rtv1)
{
	int 	size;

	size = 0;
	if (OPTION.sepia == TRUE)
		size++;
	if (OPTION.black_and_white == TRUE)
		size++;
	if (OPTION.darkroom == TRUE)
		size++;
	if (size > 1)
		error_exit("ERROR$1: too many filters\n");
}

void 	valid_option(t_rtv1 *rtv1)
{
	valid_filters(RT);
}

void		calc(t_rtv1 *rtv1)
{
	int			i;
	int			j;
	t_vector	tmp;

	i = -1;
	while (++i < OPTION.size_screen)
	{
		j = -1;
		RT->screen[i].dir_ssaa = (t_vector*)malloc(sizeof(t_vector) * (OPTION.size_ssaa) + 1);
		while (++j < OPTION.size_ssaa)
		{
			tmp = calc_ssaa(RT, RT->screen[i].ray, j);
			set_vector(&DIR_NORMAL, &tmp);
		}
	}
}

t_rtv1			*create_rtv1(void)
{
	t_rtv1		*rtv1;

	rtv1 = (t_rtv1*)malloc(sizeof(t_rtv1) + 1);
	rtv1->size_obj = 13;
	rtv1->size_light = 3;
	option_init(RT);
	rtv1->val = (t_val_vector*)malloc(sizeof(t_val_vector) * 1);
	rtv1->hit = (int*)malloc(sizeof(int) * SIZE_LIGHT * 1);

	rtv1->ray = create_ray();
	rtv1->light_ray = create_ray();

	rtv1->rt_obj = create_rt_obj(rtv1->size_obj);
	rtv1->light = create_all_light(rtv1->size_light);

	rtv1->obj = object_mlx(OPTION.size_x, OPTION.size_y, OPTION.name_win);
	rtv1->screen = create_map(OPTION.size_x, OPTION.size_y);
	// SCREEN 2 ЗАМЕНИТЬ
	rtv1->screen2 = create_map(OPTION.size_x, OPTION.size_y);
	init_demo(rtv1);
	calc(RT);
	valid_option(RT);
	return (rtv1);
}
