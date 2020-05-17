/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 00:07:52 by home              #+#    #+#             */
/*   Updated: 2020/05/17 15:16:04 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

#include <stdio.h>

#include "math_structs.h"

void	vector4i_fill(t_vector_4i *dest, int x, int y, int z);
void	vector4i_print(t_vector_4i *point);

void	point_fill(t_point *dest, int x, int y);
void	point_print(t_point *point);

void	rect_update(t_rect *self, void *change);
void	rect_fill(t_rect *dest, t_point *start, t_point *end);
void	rect_print(t_rect *rect);


void	matrix_mult(t_matrix_4x4i A, t_vector_4i B, t_vector_4i *result);

#endif
