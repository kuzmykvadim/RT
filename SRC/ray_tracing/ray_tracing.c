/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:11:53 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:25:23 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void 	effect_filtres(t_rtv1 *rtv1)
{
	int		i;
	t_color	color;

	i = -1;
	while (++i < OPTION->size_screen)
	{
		if (OPTION->sepia == TRUE)
			color = sepia(*RT->screen[i].color);
		else if (OPTION->black_and_white == TRUE)
			color = black_and_white(*RT->screen[i].color);
		else if (OPTION->darkroom == TRUE)
			color = darkroom(*RT->screen[i].color);
		else
			continue ;
		RT->screen[i].color->red = color.red;
		RT->screen[i].color->blue = color.blue;
		RT->screen[i].color->green = color.green;
	}
}

void		ft_ssaa(t_rtv1 *rtv1, int i, t_color *res)
{
	t_color		color[OPTION->size_ssaa + 1];
	int			j;

	j = -1;
	res->red = 0;
	res->green = 0;
	res->blue = 0;
	while (++j < OPTION->size_ssaa)
	{
		set_vector(RAY_ORIGIN, RT->pos);
		set_vector(RAY_DIRECTION, &DIR_NORMAL);
		color[j] = intersect(rtv1, i);
	}
	midle_color(color, OPTION->size_ssaa, res);
}
void		just_rt(t_rtv1 *rtv1, int i, t_color *res)
{
	t_color		color;
	int			j;

	j = 0;
	color.red = 0;
	color.blue = 0;
	color.green = 0;
	set_vector(RAY_DIRECTION, &DIR_NORMAL);
	set_vector(RAY_ORIGIN, RT->pos);
	if ((int)X % OPTION->draft_x == 0 && (int)Y % OPTION->draft_y == 0)
	{
		set_vector(RAY_DIRECTION, &DIR_NORMAL);
		color = intersect(rtv1, i);
	}
	res->red = color.red;
	res->blue = color.blue;
	res->green = color.green;
}

void  *thread_draw1(void *parameter)
{
  int 	x;
  int 	y;

  t_rtv1 *rtv1 = (t_rtv1*)parameter;
  x = 0;
  y = 0;
  while (y < OPTION->size_y / 2)
  {
  	x = 0;
  	while (x < OPTION->size_x / 2)
  	{
  		x++;
  		put_img(rtv1->img, x, y, RT->screen[x + y * OPTION->size_x].color);
  	}
  	y++;
  }
  return (0);
}

void  *thread_draw2(void *parameter)
{
  int 	x;
  int 	y;

  t_rtv1 *rtv1 = (t_rtv1*)parameter;
  x = 0;
  y = OPTION->size_y / 2;
  while (y < OPTION->size_y)
  {
  	x = 0;
  	while (x < OPTION->size_x / 2)
  	{
  		x++;
  		put_img(rtv1->img, x, y, RT->screen[x + y * OPTION->size_x].color);
  	}
  	y++;
  }
  return (0);
}

void  *thread_draw3(void *parameter)
{
  int 	x;
  int 	y;

  t_rtv1 *rtv1 = (t_rtv1*)parameter;
  x = 0;
  y = OPTION->size_y / 2;
  while (y < OPTION->size_y)
  {
  	x = OPTION->size_x / 2;
  	while (x < OPTION->size_x)
  	{
  		x++;
  		put_img(rtv1->img, x, y, RT->screen[x + y * OPTION->size_x].color);
  	}
  	y++;
  }
  return (0);
}

void  *thread_draw4(void *parameter)
{
  int 	x;
  int 	y;

  t_rtv1 *rtv1 = (t_rtv1*)parameter;
  x = 0;
  y = 0;
  while (y < OPTION->size_y /2)
  {
  	x = OPTION->size_x / 2;
  	while (x < OPTION->size_x)
  	{
  		x++;
  		put_img(rtv1->img, x, y, RT->screen[x + y * OPTION->size_x].color);
  	}
  	y++;
  }
  return (0);
}

// void  *thread_draw2(void *parameter)
// {
//   int i = -1;
//   int *p = (int*)parameter;
//   return (0);
// }

  // pthread_t thread_handle[2];
  // int   p = 99;
  // int ret = pthread_create(&thread_handle[0], 0, thread_func, (void*)&p);
  // if (ret != 0)
  // {
  //   printf("ERROR %d\n",ret);
  //   return (1);
  // }
  // int ret2 = pthread_create(&thread_handle[1], 0, thread_func2, (void*)&p);
  // if (ret2 != 0)
  // {
  //   printf("ERROR %d\n",ret);
  //   return (1);
  // }
  // pthread_join(thread_handle[0], 0);
  // pthread_join(thread_handle[1], 0);
  // pthread_exit(NULL);

void 	draw_rt(t_rtv1 *rtv1)
{
	pthread_t thread_handle[4];
   int ret = pthread_create(&thread_handle[0], 0, thread_draw1, (void*)rtv1);
   if (ret != 0)
   {
     printf("ERROR %d\n",ret);
	  exit(1);
   }
   int ret2 = pthread_create(&thread_handle[1], 0, thread_draw2, (void*)rtv1);
   if (ret2 != 0)
   {
     printf("ERROR %d\n",ret);
	  exit(1);
   }
    ret2 = pthread_create(&thread_handle[2], 0, thread_draw3, (void*)rtv1);
   if (ret2 != 0)
   {
     printf("ERROR %d\n",ret);
	  exit(1);
   }
       ret2 = pthread_create(&thread_handle[3], 0, thread_draw4, (void*)rtv1);
   if (ret2 != 0)
   {
     printf("ERROR %d\n",ret);
	  exit(1);
   }
   pthread_join(thread_handle[0], 0);
   pthread_join(thread_handle[1], 0);
   pthread_join(thread_handle[2], 0);
   pthread_join(thread_handle[3], 0);
}

void 	horizont(t_rtv1 *rtv1)
{
	int			i;

	i = -1;
	while (++i < OPTION->size_screen)
	{
		if (i + 1 < OPTION->size_screen && i - 1 >= 0 && i + OPTION->size_x < OPTION->size_screen)
		{
			if (RT->screen[i + 1].id == RT->screen[i].id
				&& RT->screen[i - 1].id == RT->screen[i].id
				&& RT->screen[i + OPTION->size_x].id == RT->screen[i].id)
			{
				RT->screen[i].w = 1;
			}
			else
				RT->screen[i].w = 0;
		}
	}
}

void carton(t_rtv1 *rtv1)
{
	int 	i;

	i = -1;
	while (++i < OPTION->size_screen)
	{
		if (RT->screen[i].w == 1)
		{
			RT->screen[i].color->red = 255;
			RT->screen[i].color->green = 255;
			RT->screen[i].color->blue = 255;
		}
		else if (RT->screen[i].w == 0)
		{
			RT->screen[i].color->red = 0;
			RT->screen[i].color->blue = 0;
			RT->screen[i].color->green = 0;
		}
	}
}

void outline(t_rtv1 *rtv1)
{
	int 	i;

	i = -1;
	while (++i < OPTION->size_screen)
	{
		if (RT->screen[i].w == 0)
		{
			RT->screen[i].color->red = OPTION->outline_color.red;
			RT->screen[i].color->blue = OPTION->outline_color.blue;
			RT->screen[i].color->green = OPTION->outline_color.green;
		}
	}
}

void	ray_tracing(t_rtv1 *rtv1)
{
	t_val_vector	val;
	int				i;

	mlx_clear_window(MLX_MY, WIN_MY);
	rtv1->img = create_img(rtv1->obj);
	system("clear");
	i = -1;
	RT->count = 0;
	RT->loading_progress = 0;
	while (++i < OPTION->size_screen)
	{
		RT->count++;
		if (RT->count == RT->procent_one)
		{
			RT->loading_progress++;
			RT->count = 0;
			printf("\r%s%s%d%s%s", GREEN, "Loading ", RT->loading_progress, "%", RESET);
			fflush(stdout);
		}
		if (OPTION->ssaa == 1)
			ft_ssaa(RT, i, RT->screen[i].color);
		else if (OPTION->ssaa == 0)
			just_rt(RT, i, RT->screen[i].color);
	}
	if (OPTION->motion_blur == TRUE)
		motion_blur(RT);
	if (OPTION->filters == TRUE)
		effect_filtres(RT);
	if (OPTION->horizont == TRUE)
	{
		horizont(RT);
		if (OPTION->carton == TRUE)
			carton(RT);
		else if (OPTION->outline == TRUE)
			outline(RT);
	}
	draw_rt(RT);
	PUT_IMG_WIN(MLX_MY, WIN_MY, rtv1->img->img, 0, 0);
	free(rtv1->img);
}
