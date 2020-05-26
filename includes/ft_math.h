/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 00:07:52 by home              #+#    #+#             */
/*   Updated: 2020/05/25 20:06:36 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <stdio.h>
# include <math.h>

#include "math_structs.h"

void	vector4f_fill(t_vector_4f *dest, int x, int y, int z);
void	vector4f_fill_c(t_vector_4f *dest, int x, int y, int z, int hex_color);
void	vector4f_print(t_vector_4f *point);

void	point_fill(t_point *dest, int x, int y);
void	point_fill_c(t_point *dest, int x, int y, int hex_color);
void	point_print(t_point *point);

void	rect_update(t_rect *self, void *change);
void	rect_fill(t_rect *dest, t_point *start, t_point *end);
void	rect_print(t_rect *rect);

double	toRadians(int degree);
double	sind(int degree);
double	cosd(int degree);

void	matrix_mult(t_matrix_4x4f A, t_vector_4f B, t_vector_4f *result);
void	matrix_mult_rel(t_matrix_4x4f A, t_vector_4f B, t_vector_4f *result);

#endif
