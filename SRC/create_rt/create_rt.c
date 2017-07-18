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

// 	//ANTI_ALIASING
// 	OPTION.ssaa = 0; //ЕСЛИ ВКЛ SSAA то FXAA выкл
// 	OPTION.size_ssaa = 1; //ЕСЛИ OPTION.ssaa == 0 ТОГДА OPTION.size_ssaa ДОЛЖЕН БЫТЬ ОДИН
// 	OPTION.fxaa = 0; // ЕСЛИ ВКЛ FXAA то motion blur вкл и size blur == 2

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
		error_exit("ERROR$1: too many filters");
	if (OPTION->filters == FALSE && size == 1)
		error_exit("ERROR: filters == FALSE and to many filters");
	if (OPTION->filters == TRUE && size == 0)
		error_exit("ERROR$7: filters == TRUE and too small filters");
}

void 	valid_size_ssaa(t_rtv1 *rtv1)
{
	if (OPTION->ssaa == TRUE)
	{
		if (OPTION->size_ssaa <= 0)
			error_exit("ERROR$4: too small size SSAA; size ssaa[1,2,4,8]");
		if (OPTION->size_ssaa != 2 && OPTION->size_ssaa != 1)
			if (OPTION->size_ssaa != 4 && OPTION->size_ssaa != 8)
				error_exit("ERROR$3: too big size SSAA; size ssaa[1,2,4,8]");
	}
}

void 	valid_light(t_rtv1 *rtv1)
{
	int size;

	size = 0;
	(OPTION->lambert_light == TRUE ? size += 1 : 0);
	(OPTION->blinn_fong == TRUE ? size += 1 : 0);
	(OPTION->cel_shaded == TRUE ? size += 1 : 0);
	(OPTION->view_point == TRUE ? size += 1 : 0);
	(OPTION->view_normal == TRUE ? size += 1 : 0);
	if (size > 1)
		error_exit("ERROR$5: too many model light:)");
}

void 	valid_antialiasing(t_rtv1 *rtv1)
{
	int size;

	size = 0;
	(OPTION->ssaa == TRUE ? size += 1 : 0);
	(OPTION->fxaa == TRUE ? size += 1 : 0);
	if (size > 1)
		error_exit("ERROR$2: too many ANTI_ALIASING");
	if (OPTION->fxaa == TRUE && OPTION->motion_blur != FALSE)
	{
		OPTION->motion_blur = TRUE;
		OPTION->size_blur = 4;
	}
	if (OPTION->ssaa == FALSE)
		OPTION->size_ssaa = 1;
	if (OPTION->size_blur <= 0)
		error_exit("ERROR$4: too small size Motion Blur; size_blur[1-49]");
	if (OPTION->size_blur >= 50)
		error_exit("ERROR$6: too big size Motion Blur; size_blur[1-49]");
	valid_size_ssaa(RT);
}

void 	valid_draft(t_rtv1 *rtv1)
{
	if (OPTION->ssaa == TRUE || OPTION->fxaa == TRUE || OPTION->motion_blur == 1)
	{
		if (OPTION->draft_x != 1 && OPTION->draft_y != 1)
			error_exit("Sorry: ERROR$8 draft dont work");
	}
	if (OPTION->draft_x < 1 || OPTION->draft_x > 5)
		error_exit("ERROR$9 draft_x{1-5}");
	if (OPTION->draft_y < 1 || OPTION->draft_y > 5)
		error_exit("ERROR$10 draft_y{1-5}");
}

void 	valid_camera(t_rtv1 *rtv1) //FOV DONT WORK
{
	printf("%d\n",OPTION->fieldofview);
	if (OPTION->fov_on == TRUE)
	{
		if (OPTION->fieldofview <= 0 || OPTION->fieldofview >= 360)
			error_exit("ERROR$11 fieldofview[1-359]");
	}
	if (OPTION->speed <= 0 || OPTION->speed >= 1000)
		error_exit("ERRRO12 camera speed[1-999]");
}

void 	valid_option(t_rtv1 *rtv1)
{
	valid_filters(RT);
	OPTION->size_screen = OPTION->size_x * OPTION->size_y;
	valid_antialiasing(RT);
	valid_light(RT);
	valid_draft(RT);
	valid_camera(RT);
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
		RT->screen[i].dir_ssaa = (t_vector*)malloc(sizeof(t_vector) * (OPTION->size_ssaa + 1));
		while (++j < OPTION->size_ssaa)
		{
			tmp = calc_ssaa(RT, RT->screen[i].ray, j);
			set_vector(&DIR_NORMAL, &tmp);
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
	while ((nb = get_next_line(e->fd, &line)) && nb != -1)
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
	rtv1->val = (t_val_vector*)malloc(sizeof(t_val_vector) + 1);
	rtv1->hit = (int*)malloc(sizeof(int) * (SIZE_LIGHT));
	rtv1->val->rgb = (t_color*)malloc(sizeof(t_color) * SIZE_LIGHT + 1);
	rtv1->ray = create_ray();
	rtv1->light_ray = create_ray();
	rtv1->pos = create_vector();
	rtv1->obj = object_mlx(OPTION->size_x, OPTION->size_y, OPTION->name_win);
	rtv1->screen = create_map(OPTION->size_x, OPTION->size_y);
	rtv1->screen2 = create_map(OPTION->size_x, OPTION->size_y);
	construct_vector(rtv1->ray->origin, (OPTION->size_x / 2) + 0.99, (OPTION->size_y / 2) + 0.99, -1700.99);
	t_vector tmp = sub_vector(RAY_ORIGIN, &OPTION->cam_pos);
	set_vector(RAY_ORIGIN, &tmp);
	valid_option(RT);
	calc(RT);
	init_demo(RT);
	set_vector(RT->pos, RAY_ORIGIN);
	RT->procent_one = (OPTION->size_screen) * 0.01;
	return (rtv1);
}
