/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:45:17 by home              #+#    #+#             */
/*   Updated: 2020/05/16 00:24:14 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_STRUCTS_H
# define MATH_STRUCTS_H

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_rect
{
	t_point		start;
	t_point		end;

	int			width;
	int			height;
}				t_rect;

typedef struct	s_vector_4i
{
	int			vec[4];
}				t_vector_4i;

typedef struct	s_matrix_4x4i
{
	int			matrix[4][4];
}				t_matrix_4x4i;

#endif
