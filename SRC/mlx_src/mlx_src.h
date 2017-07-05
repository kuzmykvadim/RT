/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_src.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 16:37:35 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:41:33 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_SRC_H
# define MLX_SRC_H
# define CREATE_IMAGE mlx_get_data_addr
# define MLX_XPM_FILE mlx_xpm_file_to_image
# define PUT_IMG_WIN mlx_put_image_to_window
# define SIZE_Y 800
# define SIZE_X 800
# define BUTTON_W 13
# define BUTTON_A 0
# define BUTTON_D 2
# define BUTTON_S 1
# include <mlx.h>
# include <stdlib.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef	struct	s_color
{
	double			red;
	double			blue;
	double			green;
	double			trans;
}				t_color;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct	s_img
{
	int		bits;
	int		size_line;
	int		end;
	char	*line;
	void	*img;
}				t_img;

typedef struct	s_xpm
{
	int		width;
	int		height;
	int		bits;
	int		size_line;
	int		end;
	char	*data;
	void	*xpm;
}				t_xpm;

t_mlx			*object_mlx(void);
t_img			*create_img(t_mlx *obj);
t_xpm			*create_xpm(t_mlx *obj, char *file);
void			put_img(t_img *img, int x, int y, t_color *color);
t_color			create_color(int color);
void			protected_color(t_color *color);
void			midle_color(t_color *color, int size, t_color *new);
void			set_color(t_color *color, double r, double g, double b);
t_color			darkroom(t_color a);
t_color			sepia(t_color a);
t_color			black_and_white(t_color a);
#endif
