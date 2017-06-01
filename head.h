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
# include "SRC/ft_math/ft_math.h"
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
# define SPHERE_RADIUS_POW 		sphere->radius_pow;
# define SIZE_OBJ 				rtv1->size_obj
# define SIZE_LIGHT 			rtv1->size_light
# define MLX_MY					rtv1->obj->mlx
# define WIN_MY					rtv1->obj->win
# define L						rtv1->light[i]
# define L_COLOR				rtv1->light[i].color
# define SCREEN					rtv1->screen[i].ray
# define X 						RT->screen2[i].ray->x
# define Y 						RT->screen2[i].ray->y
# define Z 						RT->screen2[i].ray->z

typedef struct	s_object
{
	t_sphere		*sphere;
	t_plane			*plane;
	t_cylinder		*cylinder;
	t_cone			*cone;
	t_disk			*disk;
	t_poligon		*poligon;
	t_color			color;
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

typedef struct	s_model_light
{
	double	ambient;
	double	diffuse;
	double	specular;
	double	dot;
	double	beta;
}				t_model_light;

typedef struct	s_val_vector
{
	t_vector		point;
	t_vector		n_point;
	t_vector		tmp;
	t_color			color;
	t_color			rgb[4];
	t_vector		ray;
}				t_val_vector;

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
	int				*hit;
	int				size_obj;
	int				size_light;
	int				x;
	int				y;
	int				light_off_on;
}				t_rtv1;

t_rtv1			*create_rtv1(void);
int				calc(t_rtv1 *rtv1, int (*f)());
int				calc_norm_dir(int i, t_rtv1 *rtv1);
void			init_demo(t_rtv1 *rtv1);

void			ray_tracing(t_rtv1 *rtv1);

int				module_check_in(t_rtv1 *rtv1, t_vector *pos_obj);
t_color			intersect(t_rtv1 *rtv1);
int				check_intersect_object(t_rtv1 *rt, double *t, int i, t_ray *r);

int				intersect_sphere(t_ray *ray, t_sphere *sphere, double *t);
int				intersect_plane(t_ray *ray, t_plane *plane, double *t);
int				intersect_cylinder(t_ray *ray, t_cylinder *cylinder, double *t);
int				intersect_cone(t_ray *ray, t_cone *cone, double *t);
int				intersect_disc(t_ray *ray, t_disk *disk, double *t);
int				intersect_poligon(t_ray *ray, t_poligon *poligon, double *t);

int				discriminant(double *t, t_val_math val);
int				light_intersect(t_rtv1 *rt, double *t);
t_color			ft_light(t_rtv1 *rt, double *t_min, int num_obj);
void			all_shadow(t_rtv1 *r, int num_obj, t_val_vector *val, int *hit);
void			all_light(t_rtv1 *r, t_val_vector *val, int *hit);
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

#endif
