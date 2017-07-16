/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json_parser_general.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:50:14 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/07/13 15:37:16 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	ft_json_parser_general1(t_options *o, t_options_json *oj)
{
	if (!cJSON_IsBool(oj->light_off_on))
		ft_pars_err("light parameter error");
	o->light_off_on = oj->light_off_on->valueint;
	oj->lambert_light = cJSON_GetObjectItemCaseSensitive(oj->opt,
			"lambert_light");
	if (!cJSON_IsBool(oj->lambert_light))
		ft_pars_err("lambert light parameter error");
	o->lambert_light = oj->lambert_light->valueint;
	oj->cel_shaded = cJSON_GetObjectItemCaseSensitive(oj->opt, "cel_shaded");
	if (!cJSON_IsBool(oj->cel_shaded))
		ft_pars_err("cel_shaded parameter error");
	o->cel_shaded = oj->cel_shaded->valueint;
	oj->blinn_fong = cJSON_GetObjectItemCaseSensitive(oj->opt, "blinn_fong");
	if (!cJSON_IsBool(oj->blinn_fong))
		ft_pars_err("blinn_fong  error");
	o->blinn_fong = oj->blinn_fong->valueint;
	oj->shadow = cJSON_GetObjectItemCaseSensitive(oj->opt, "shadow");
	if (!cJSON_IsBool(oj->shadow))
		ft_pars_err("shadow parameter error");
	o->shadow = oj->shadow->valueint;
}

void	ft_json_parser_general2(t_options *o, t_options_json *oj)
{
	oj->view_normal = cJSON_GetObjectItemCaseSensitive(oj->opt, "view_normal");
	if (!cJSON_IsBool(oj->view_normal))
		ft_pars_err("view_normal parameter error");
	o->view_normal = oj->view_normal->valueint;
	oj->view_point = cJSON_GetObjectItemCaseSensitive(oj->opt, "view_point");
	if (!cJSON_IsBool(oj->view_point))
		ft_pars_err("view_point parameter error");
	o->view_point = oj->view_point->valueint;
	oj->ssaa = cJSON_GetObjectItemCaseSensitive(oj->opt, "ssaa");
	if (!cJSON_IsBool(oj->ssaa))
		ft_pars_err("ssaa parameter error");
	o->ssaa = oj->ssaa->valueint;
	oj->size_ssaa = cJSON_GetObjectItemCaseSensitive(oj->opt, "size_ssaa");
	if (!cJSON_IsNumber(oj->size_ssaa))
		ft_pars_err("size_ssaa ssaa error");
	o->size_ssaa = oj->size_ssaa->valueint;
	oj->fxaa = cJSON_GetObjectItemCaseSensitive(oj->opt, "fxaa");
	if (!cJSON_IsBool(oj->fxaa))
		ft_pars_err("fxaa parameter error");
	o->fxaa = oj->fxaa->valueint;
	oj->filters = cJSON_GetObjectItemCaseSensitive(oj->opt, "filters");
	if (!cJSON_IsBool(oj->filters))
		ft_pars_err("filters parameter error");
}

void	ft_json_parser_general3(t_options *o, t_options_json *oj)
{
	o->filters = oj->filters->valueint;
	oj->darkroom = cJSON_GetObjectItemCaseSensitive(oj->opt, "darkroom");
	if (!cJSON_IsBool(oj->darkroom))
		ft_pars_err("darkroom parameter error");
	o->darkroom = oj->darkroom->valueint;
	oj->black_and_white = cJSON_GetObjectItemCaseSensitive(oj->opt,
			"black_and_white");
	if (!cJSON_IsBool(oj->black_and_white))
		ft_pars_err("black_and_white parameter error");
	o->black_and_white = oj->black_and_white->valueint;
	oj->sepia = cJSON_GetObjectItemCaseSensitive(oj->opt, "sepia");
	if (!cJSON_IsBool(oj->sepia))
		ft_pars_err("sepia parameter error");
	o->sepia = oj->sepia->valueint;
	oj->motion_blur = cJSON_GetObjectItemCaseSensitive(oj->opt, "motion_blur");
	if (!cJSON_IsBool(oj->motion_blur))
		ft_pars_err("motion_blur parameter error");
	o->motion_blur = oj->motion_blur->valueint;
	oj->size_blur = cJSON_GetObjectItemCaseSensitive(oj->opt, "size_blur");
	if (!cJSON_IsNumber(oj->size_blur))
		ft_pars_err("size_blur ssaa error");
	o->size_blur = oj->size_blur->valueint;
	oj->fov_on = cJSON_GetObjectItemCaseSensitive(oj->opt, "fov_on");
}

void	ft_json_parser_general4(t_options *o, t_options_json *oj)
{
	if (!cJSON_IsBool(oj->fov_on))
		ft_pars_err("fov_on parameter error");
	o->fov_on = oj->fov_on->valueint;
	oj->fieldofview = cJSON_GetObjectItemCaseSensitive(oj->opt, "fieldofview");
	if (!cJSON_IsNumber(oj->fieldofview))
		ft_pars_err("fieldofview ssaa error");
	o->fieldofview = oj->fieldofview->valueint;
	oj->draft_x = cJSON_GetObjectItemCaseSensitive(oj->opt, "draft_x");
	o->draft_x = oj->draft_x->valueint;
	oj->draft_y = cJSON_GetObjectItemCaseSensitive(oj->opt, "draft_y");
	if (!cJSON_IsNumber(oj->draft_y) || !cJSON_IsNumber(oj->draft_x))
		ft_pars_err("draft ssaa error");
	o->draft_y = oj->draft_y->valueint;
	oj->camera_position = cJSON_GetObjectItemCaseSensitive(oj->opt,
			"camera_position");
	oj->cam_x = cJSON_GetObjectItemCaseSensitive(oj->camera_position, "x");
	oj->cam_y = cJSON_GetObjectItemCaseSensitive(oj->camera_position, "y");
	oj->cam_z = cJSON_GetObjectItemCaseSensitive(oj->camera_position, "z");
	if (!cJSON_IsNumber(oj->cam_x) || !cJSON_IsNumber(oj->cam_y) ||
			!cJSON_IsNumber(oj->cam_z))
		ft_pars_err("Camera parameters error");
	o->cam_pos.x = oj->cam_x->valuedouble;
	o->cam_pos.y = oj->cam_y->valuedouble;
	o->cam_pos.z = oj->cam_z->valuedouble;


	oj->j_screen_size = cJSON_GetObjectItemCaseSensitive(oj->opt,
			"screen_size");
	oj->j_size_x = cJSON_GetObjectItemCaseSensitive(oj->j_screen_size, "width");
	oj->j_size_y = cJSON_GetObjectItemCaseSensitive(oj->j_screen_size, "height");
	if (!cJSON_IsNumber(oj->j_size_y) || !cJSON_IsNumber(oj->j_size_x))
		ft_pars_err("Screen size parameters error");
	o->size_y = oj->j_size_y->valueint;
	o->size_x = oj->j_size_x->valueint;
}

void	ft_json_parser_general5(t_options *o, t_options_json *oj)
{
	oj->j_bg_color = cJSON_GetObjectItemCaseSensitive(oj->opt,
			"background_color");
	oj->l_col_r = cJSON_GetObjectItemCaseSensitive(oj->j_bg_color, "r");
	oj->l_col_g = cJSON_GetObjectItemCaseSensitive(oj->j_bg_color, "g");
	oj->l_col_b = cJSON_GetObjectItemCaseSensitive(oj->j_bg_color, "b");
	if (!cJSON_IsNumber(oj->l_col_r) || !cJSON_IsNumber(oj->l_col_g)
			|| !cJSON_IsNumber(oj->l_col_b))
		ft_pars_err("Lights color parameters error");
	o->bg_color.red = oj->l_col_r->valuedouble;
	o->bg_color.green = oj->l_col_g->valuedouble;
	o->bg_color.blue = oj->l_col_b->valuedouble;
	if (o->bg_color.red > 255 || o->bg_color.red < 0 ||
			o->bg_color.green > 255 || o->bg_color.green < 0 ||
			o->bg_color.blue > 255 || o->bg_color.blue < 0)
		ft_pars_err("Background color parameters error, use from 0 to 255");
	oj->j_depth_rec = cJSON_GetObjectItemCaseSensitive(oj->opt, "depth_rec");
	if (!cJSON_IsNumber(oj->j_depth_rec))
		ft_pars_err("depth_rec error");
	o->depth_rec = oj->j_depth_rec->valueint;
	oj->j_speed = cJSON_GetObjectItemCaseSensitive(oj->opt, "speed");
	if (!cJSON_IsNumber(oj->j_speed))
		ft_pars_err("speed error");
	o->speed = oj->j_speed->valueint;
}

void	ft_json_parser_general(char *file, t_all_data *data)
{
	t_options		*o;
	t_options_json	*oj;

	o = (t_options*)ft_memalloc(sizeof(t_options) + 1);
	oj = (t_options_json*)ft_memalloc(sizeof(t_options_json) + 1);
	oj->root = cJSON_Parse(file);
	oj->opt = cJSON_GetObjectItemCaseSensitive(oj->root, "general");
	if (!cJSON_IsObject(oj->opt))
		ft_pars_err("General parameters error");
	oj->name_win = cJSON_GetObjectItemCaseSensitive(oj->opt, "name_win");
	o->name_win = oj->name_win->valuestring;
	oj->light_off_on = cJSON_GetObjectItemCaseSensitive(oj->opt,
			"light_off_on");
	ft_json_parser_general1(o, oj);
	ft_json_parser_general2(o, oj);
	ft_json_parser_general3(o, oj);
	ft_json_parser_general4(o, oj);
	ft_json_parser_general5(o, oj);
	data->all_opt = ft_copy(o, sizeof(t_options));
	data->all_opt->objects_count = data->all_obj->obj_count;
	free(o);
	free(oj);
}
