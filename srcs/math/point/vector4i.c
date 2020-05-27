/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 02:33:29 by home              #+#    #+#             */
/*   Updated: 2020/05/26 19:07:28 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

void	vector4f_fill(t_vector_4f *dest, int x, int y, int z)
{
	dest->vec[0] = x;
	dest->vec[1] = y;
	dest->vec[2] = z;
	dest->vec[3] = 1;
}

void	vector4f_fill_c(t_vector_4f *dest, int x, int y, int z, int hex_color)
{
	dest->vec[0] = x;
	dest->vec[1] = y;
	dest->vec[2] = z;
	dest->vec[3] = 1;

	dest->color = hex_color;
}

void	vector4f_subtract(t_vector_4f *start, t_vector_4f *minus, t_vector_4f *dest)
{
	dest->vec[0] = start->vec[0] - minus->vec[0];
	dest->vec[1] = start->vec[1] - minus->vec[1];
	dest->vec[2] = start->vec[2] - minus->vec[2];
	dest->vec[3] = start->vec[3] - minus->vec[3];
}

void	vector4f_print(t_vector_4f *point)
{
	printf("Vector: (%f, %f, %f)\n", point->vec[0], point->vec[1], point->vec[2]);
}
