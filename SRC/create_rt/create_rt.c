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

// void 	option_init(t_rtv1 *rtv1)
// {
// 	OPTION.light_off_on = 0;
// 	OPTION.color_background = create_color(0x000000);
// 	OPTION.draft_x = 1;
// 	OPTION.draft_y = 1;
//
// 	//ANTI_ALIASING
// 	OPTION.ssaa = 0; //ЕСЛИ ВКЛ SSAA то FXAA выкл
// 	OPTION.size_ssaa = 1; //ЕСЛИ OPTION.ssaa == 0 ТОГДА OPTION.size_ssaa ДОЛЖЕН БЫТЬ ОДИН
// 	OPTION.fxaa = 0; // ЕСЛИ ВКЛ FXAA то motion blur вкл и size blur == 2
// 	//LIGHT AND SHADOW
// 	OPTION.lambert_light = 0;
// 	OPTION.view_normal = 0;
// 	OPTION.view_point = 0;
// 	OPTION.cel_shaded = 0;
// 	OPTION.blinn_fong = 1;
// 	OPTION.shadow = 1;
//
// 	// FOV
// 	OPTION.fov_on = 0;
// 	OPTION.fov = 45;
//
// 	// MOTION_BLUR
// 	OPTION.motion_blur = 0;
// 	OPTION.size_blur = 0;
//
// 	OPTION.size_x = 800;
// 	OPTION.size_y = 600;
// 	OPTION.size_screen = OPTION.size_x * OPTION.size_y;
// 	OPTION.name_win = "";
//
// 	// filters
// 	OPTION.filters = 0;
// 	OPTION.sepia = 0;
// 	OPTION.black_and_white = 1;
// 	OPTION.darkroom = 0;
// }

void 	valid_filters(t_rtv1 *rtv1)
{
	int 	size;

	size = 0;
	if (OPTION->sepia == TRUE)
		size++;
	if (OPTION->black_and_white == TRUE)
		size++;
	if (OPTION->darkroom == TRUE)
		size++;
	if (size > 1)
		error_exit("ERROR$1: too many filters\n");
}
void 	valid_option(t_rtv1 *rtv1)
{
	valid_filters(RT);
	OPTION->size_screen = OPTION->size_x * OPTION->size_y;
}

void		calc(t_rtv1 *rtv1)
{
	int			i;
	int			j;
	t_vector	tmp;

	i = -1;
	while (++i < OPTION->size_screen)
	{
		j = -1;
		RT->screen[i].dir_ssaa = (t_vector*)malloc(sizeof(t_vector) * (OPTION->size_ssaa) + 1);
		while (++j < OPTION->size_ssaa)
		{
			tmp = calc_ssaa(RT, RT->screen[i].ray, j);
			set_vector(&DIR_NORMAL, &tmp);
			printf("DIR_NORMAL x %f y %f z %f\n", DIR_NORMAL.x, DIR_NORMAL.y, DIR_NORMAL.z);
		}
	}
}

void ft_pars_err(char *str)
{
	printf("\033[1;31m_______%s_______\n\033[0m", str);
	exit(1);
}

char	*ft_read_file(t_env *e)
{
	char	*line;
	char	*str;
	char	*tmp;
	int		nb;

	line = NULL;
	if (!(str = (char*)malloc(sizeof(char))))
		return (0);
	while ((nb = get_next_line(e->fd, &line)))
	{
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, "\n\0");
		free(tmp);
		free(line);
	}
	free(line);
	if (nb < 0)
	{
		printf("fd error");
		exit(0);
	}
	return (str);
}

void	ft_init(t_env *e, char *file)
{
	if ((e->fd = open(file, O_RDONLY)) < 0)
		error_exit("scene error");
}

t_all_data		*ft_parsing(t_env *e)
{
	t_all_data	*data;
	char		*file;

	data = (t_all_data*)malloc(sizeof(t_all_data) + 1);
	file = ft_read_file(e);
	ft_json_parser_obj(file, data);
	ft_json_parser_general(file, data);
	ft_pars_lights(file, data);
	free(file);
	return (data);
}

t_rtv1			*create_rtv1(t_env *e, char *file)
{
	t_rtv1		*rtv1;

	ft_init(e, file);
	rtv1 = (t_rtv1*)malloc(sizeof(t_rtv1) + 1);
	rtv1->data = ft_parsing(e);
	rtv1->val = (t_val_vector*)malloc(sizeof(t_val_vector) * 1);
	rtv1->hit = (int*)malloc(sizeof(int) * SIZE_LIGHT + 1);
	rtv1->ray = create_ray();
	rtv1->light_ray = create_ray();
	rtv1->pos = create_vector();
	rtv1->obj = object_mlx(OPTION->size_x, OPTION->size_y, OPTION->name_win);
	rtv1->screen = create_map(OPTION->size_x, OPTION->size_y);
	////// SCREEN 2 ЗАМЕНИТЬ
	rtv1->screen2 = create_map(OPTION->size_x, OPTION->size_y);
	construct_vector(rtv1->ray->origin, OPTION->size_x / 2, OPTION->size_y / 2, -1700.99);
	t_vector tmp = add_vector(RAY_ORIGIN, &OPTION->cam_pos);
	set_vector(RAY_ORIGIN, &tmp);
	valid_option(RT);
	calc(RT);
	init_demo(RT);
	set_vector(RT->pos, RAY_ORIGIN);
	printf("ERRROR\n");
	// sleep(1000);
	return (rtv1);
}
