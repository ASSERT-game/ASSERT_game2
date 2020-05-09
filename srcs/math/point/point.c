/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 01:47:08 by home              #+#    #+#             */
/*   Updated: 2020/05/08 20:18:10 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

void	point_fill(t_point *dest, int x, int y)
{
	dest->x = x;
	dest->y = y;
}

void	point_print(t_point *point)
{
	printf("Point: (%d, %d)\n", point->x, point->y);
}
