/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 02:33:29 by home              #+#    #+#             */
/*   Updated: 2020/05/17 15:10:04 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

void	vector4i_fill(t_vector_4i *dest, int x, int y, int z)
{
	dest->vec[0] = x;
	dest->vec[1] = y;
	dest->vec[2] = z;
	dest->vec[3] = 1;
}

void	vector4i_print(t_vector_4i *point)
{
	printf("Vector: (%d, %d, %d)\n", point->vec[0], point->vec[1], point->vec[2]);
}
