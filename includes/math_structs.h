/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:45:17 by home              #+#    #+#             */
/*   Updated: 2020/05/20 23:02:33 by home             ###   ########.fr       */
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

typedef struct	s_vector_4f
{
	double		vec[4];
	int			color;
}				t_vector_4f;

typedef struct	s_matrix_4x4f
{
	double		matrix[4][4];
}				t_matrix_4x4f;

#endif
