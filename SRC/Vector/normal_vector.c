/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 21:39:32 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:29:39 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	normal_vector(t_vector v)
{
	double		lenght;
	t_vector	new;

	lenght = module_vector(&v);
	new = division_vector(&v, lenght);
	return (new);
}
