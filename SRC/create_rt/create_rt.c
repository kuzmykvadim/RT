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
	OPTION.lambert_light = 0;
	OPTION.view_normal = 0;
	OPTION.view_point = 0;
	OPTION.cel_shaded = 0;
	OPTION.blinn_fong = 1;
	OPTION.shadow = 1;
	OPTION.fov_on = 0;
	OPTION.fov = 45;
	OPTION.filters = 0;
	OPTION.sepia = 0;
	OPTION.black_and_white = 0;
	OPTION.darkroom = 0;
}

static t_vector add(t_vector a, float b, float c)
{
	t_vector res;

	res.x = a.x + b;
	res.y = a.y + c;
	res.z = a.z;
	return	(res);
}

#define SIZE_SSAA 4

static t_vector x2_anti_alias(t_vector temp, int j)
{
	if (j == 1)
		temp = add(temp, 0, -0.5);
	else if (j == 2)
		temp = add(temp, 0, 0.5);
	return (temp);
}

static t_vector x4_anti_alias(t_vector temp, int j)
{
	if (j == 1 || j == 5)
		temp = add(temp, 0.25, 0.25);
	else if (j == 2 || j == 6)
		temp = add(temp, 0.25, -0.25);
	else if (j == 3)
		temp = add(temp, -0.25, 0.25);
	else if (j == 4)
		temp = add(temp, -.25, -0.25);
	return (temp);
}

static t_vector x8_anti_alias( t_vector temp, int j)
{
	if (j <= 2)
		temp = x2_anti_alias(temp, j);
	if (j >= 3 && j <= 6)
		temp = x4_anti_alias(temp, j);
	if (j == 7)
		temp = add(temp, -0.5, 0);
	if (j == 8)
		temp = add(temp, 0.5, 0);
	return (temp);
}

static t_vector anti_alias(t_rtv1 *rtv1, t_vector *dir, int j)
{
	t_vector res;
	t_vector temp;

	temp = sub_vector(dir, RAY_ORIGIN);
	if (SIZE_SSAA == 2)
		temp = x2_anti_alias(temp, j);
	if (SIZE_SSAA == 4)
		temp = x4_anti_alias(temp, j);
	if (SIZE_SSAA == 8)
		temp = x8_anti_alias(temp, j);
	res = normal_vector(temp);
	return (res);
}

int		calc(t_rtv1 *rtv1)
{
	int			size;
	int			i;
	t_vector	tmp;

	size = SIZE_X * SIZE_Y;
	i = 0;
	while (i < size)
	{
		tmp = normal_vector(sub_vector(RT->screen[i].ray, RAY_ORIGIN));
		RT->screen[i].dir_normal->x = tmp.x;
		RT->screen[i].dir_normal->y = tmp.y;
		RT->screen[i].dir_normal->z = tmp.z;
		i++;
	}
	return (1);
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
	rtv1->obj = object_mlx();
	rtv1->light = create_all_light(rtv1->size_light);
	rtv1->screen = create_map();
	rtv1->screen2 = create_map();
	init_demo(rtv1);
	calc(RT);
	return (rtv1);
}
