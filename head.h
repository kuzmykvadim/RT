/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:00:34 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:49:38 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# include <fcntl.h>
# include <string.h>
# include "SRC/mlx_src/mlx_src.h"
# include "SRC/create_rt/create_rt.h"
# include "SRC/ray_tracing/Lighting_Model/light.h"
# include <stdio.h>

# define RAY_ORIGIN 			rtv1->ray->origin
# define RAY_DIRECTION 			rtv1->ray->direction
# define L_RAY_ORIGIN 			rtv1->light_ray->origin
# define L_RAY_DIRECTION 		rtv1->light_ray->direction
# define CONE_COS_22			cone->two_cone_cos_two
# define CONE_COS_2				cone->cone_cos_two
# define CONE_SIN_22			cone->two_cone_sin_two
# define CONE_SIN_2				cone->cone_sin_two
# define RT_OBJ					rtv1->rt_obj[num_obj]
# define RT						rtv1
# define SPHERE_POSITION 		sphere->position
# define SPHERE_RADIUS_POW 		sphere->radius_pow
# define SIZE_OBJ 				rtv1->size_obj
# define SIZE_LIGHT 			rtv1->size_light
# define MLX_MY					rtv1->obj->mlx
# define WIN_MY					rtv1->obj->win
# define L						rtv1->light[i]
# define SCREEN					rtv1->screen[i].ray
# define BACKGROUND				rtv1->option.color_background
# define OPTION					rtv1->option
# define DIR_NORMAL 			RT->screen[i].dir_ssaa[j]
# define X 						RT->screen2[i].ray->x
# define Y 						RT->screen2[i].ray->y
# define TRUE					1
# define FALSE					0
# define SIZE					SIZE_X * SIZE_Y
typedef struct	s_object
{
	char			id;
	t_sphere		*sphere;
	t_plane			*plane;
	t_cylinder		*cylinder;
	t_cone			*cone;
	t_disk			*disk;
	t_poligon		*poligon;
	t_half_sphere	*half_sphere;
	t_plane_limit	*plane_limit;
	t_color			color;
	t_vector		*rotation;
}				t_object;

typedef struct	s_type
{
	char	*name;
}				t_type;

typedef struct	s_val_math
{
	t_vector	dist;
	double		a;
	double		b;
	double		c;
	double		d;
	double		t0;
	double		t1;
}				t_val_math;

typedef struct	s_val_intersect
{
	int		i;
	int		num_obj;
	int		hit;
}				t_val_intersect;

typedef struct	s_val_vector
{
	t_vector		point;
	t_vector		n_point;
	t_vector		tmp;
	t_color			color;
	t_color			rgb[4];
	t_vector		ray;
}				t_val_vector;

typedef struct 	s_options
{
	t_color		color_background;

	int			light_off_on;
	int			lambert_light;
	int			cel_shaded;
	int			blinn_fong;
	int			shadow;

	int 		view_normal;
	int			view_point;

	int			fov_on;
	int			fov;

	int			size_ssaa;
	int			ssaa;

	int			filters;
	int			darkroom;
	int			black_and_white;
	int			sepia;

	int			draft_x;
	int			draft_y;
}				t_options;

typedef struct	s_rtv1
{
	t_mlx			*obj;
	t_img			*img;
	t_ray			*ray;
	t_ray			*light_ray;
	t_object		*rt_obj;
	t_light			*light;
	t_screen		*screen;
	t_screen		*screen2;
	t_val_vector	*val;
	t_options		option;
	int				*hit;
	int				size_obj;
	int				size_light;
}				t_rtv1;

t_rtv1			*create_rtv1(void);
t_vector 		calc_ssaa(t_rtv1 *rtv1, t_vector *dir, int j);
void			init_demo(t_rtv1 *rtv1);

void			ray_tracing(t_rtv1 *rtv1);

int				module_check_in(t_rtv1 *rtv1, t_vector *pos_obj);
t_color			intersect(t_rtv1 *rtv1);
int				check_intersect_object(t_rtv1 *rt, double *t, int i, t_ray *r);

int				intersect_sphere(t_ray *r, t_sphere *s, double *t);
int				intersect_plane(t_ray *r, t_plane *p, double *t);
int				intersect_cylinder(t_ray *r, t_cylinder *c, double *t);
int				intersect_cone(t_ray *r, t_cone *c, double *t);
int				intersect_disc(t_ray *r, t_disk *d, double *t);
int				intersect_poligon(t_ray *r, t_poligon *p, double *t);
int				intersect_half_sphere(t_ray *r, t_half_sphere *s, double *t);
int				intersect_plane_limit(t_ray *ray, t_plane_limit *plane, double *t);

int				discriminant(double *t, t_val_math val);
int				light_intersect(t_rtv1 *rt, double *t);
t_color			ft_light(t_rtv1 *rt, double *t_min, int num_obj);
void			all_shadow(t_rtv1 *r, int num_obj, t_val_vector *val, int *hit);
void			all_light(t_rtv1 *r, t_val_vector *val, int *hit, int num_obj);
t_vector		find_point_intersect(t_rtv1 *rt, double *t);
t_vector		get_intersect_normal(t_rtv1 *rt, int num_obj, t_vector *point);
t_vector		find_normal_cylinder(t_cylinder *cylinder, t_vector *point);
t_vector		find_normal_cone(t_cone *cone, t_vector *point);
t_color			get_color(t_rtv1 *rtv1, int num_obj);

int				destroy(void);
int				event_key(int keycode, t_rtv1 *rtv1);
int				event_mouse(int keycode, int x, int y, t_rtv1 *rtv1);
int				event_camera(int keycode, t_rtv1 *rt);
void			move_left_camera(t_rtv1 *rtv1);
void			move_right_camera(t_rtv1 *rtv1);
void			move_forward_camera(t_rtv1 *rtv1);
void			move_back_camera(t_rtv1 *rtv1);
void			move_up_camera(t_rtv1 *rtv1);
void			move_down_camera(t_rtv1 *rtv1);
void			zoom(int keycode, int x, int y, t_rtv1 *rtv1);
void			rotation_x(t_rtv1 *rtv1, int keycode);
void			rotation_y(t_rtv1 *rtv1, int keycode);
void			rotation_z(t_rtv1 *rtv1, int keycode);

void			mlx_use(t_rtv1 *rtv1);
int				error_exit(char *error);

// ROTATION VECTOR
void rot_z(t_vector *v, int angle);
void rot_y(t_vector *v, int angle);
void rot_x(t_vector *v, int angle);
//

#endif
