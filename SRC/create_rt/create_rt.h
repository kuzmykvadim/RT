/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:51:49 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/29 19:51:51 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_RT_H
# define CREATE_RT_H

# include "../Vector/vector.h"
# include "../mlx_src/mlx_src.h"

typedef struct	s_light
{
	t_vector	*position;
	t_color		color;
}				t_light;

typedef	struct	s_cylinder
{
	t_vector	*position;
	t_vector	*direction;
	double		radius;
	double		radius_pow;
}				t_cylinder;

typedef	struct	s_cone
{
	t_vector	*position;
	t_vector	*direction;
	double		angle;
	double		cone_cos_two;
	double		cone_sin_two;
	double		two_cone_cos_two;
	double		two_cone_sin_two;
}				t_cone;

typedef	struct	s_half_sphere
{
	t_vector	*position;
	double		radius;
	double		radius_pow;
	t_vector	*normal;
	int			n;
	int			light_n;
}				t_half_sphere;

typedef	struct	s_sphere
{
	t_vector	*position;
	double		radius;
	double		radius_pow;
}				t_sphere;

typedef	struct	s_poligon
{
	t_vector	*v0;
	t_vector	*v1;
	t_vector	*v2;
	t_vector	*normal;
}				t_poligon;

typedef struct	s_plane
{
	double		distance;
	t_vector	*normal;
}				t_plane;

typedef struct	s_plane_limit
{
	t_vector	*position;
	t_vector	*normal;
	t_vector	*rotation;
	double		height;
	double		weight;
}				t_plane_limit;

typedef	struct	s_ray
{
	t_vector	*origin;
	t_vector	*direction;
	double		scalar_ray_direction;
}				t_ray;

typedef struct	s_disk
{
	t_vector	*normal;
	t_vector	*position;
	double		radius;
}				t_disk;

typedef struct	s_screen
{
	t_vector	*ray;
	t_vector	*dir_normal;
}				t_screen;

t_sphere		*create_shpere(void);
t_ray			*create_ray(void);
t_plane			*create_plane(void);
t_cylinder		*create_cylinder(void);
t_cone			*create_cone(void);
t_screen		*create_map(void);
t_light			*create_all_light(int size);

#endif
