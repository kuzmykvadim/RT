/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:14:08 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 21:31:52 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

int		main(int argc, char **argv)
{
	t_rtv1		*rtv1;

	// (argc != 2 ? error_exit("Wrong argv") : 0);
	rtv1 = create_rtv1();
	ray_tracing(rtv1);
	mlx_use(rtv1);
	return (0);
}
