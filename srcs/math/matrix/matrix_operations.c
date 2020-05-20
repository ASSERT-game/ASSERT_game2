/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:42:29 by home              #+#    #+#             */
/*   Updated: 2020/05/20 04:57:13 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

void	matrix_mult(t_matrix_4x4f A, t_vector_4f B, t_vector_4f *result)
{
	result->vec[0] = A.matrix[0][0] * B.vec[0] + A.matrix[0][1] * B.vec[1] +
					 A.matrix[0][2] * B.vec[2] + A.matrix[0][3] * B.vec[3];

	result->vec[1] = A.matrix[1][0] * B.vec[0] + A.matrix[1][1] * B.vec[1] +
					 A.matrix[1][2] * B.vec[2] + A.matrix[1][3] * B.vec[3];

	result->vec[2] = A.matrix[2][0] * B.vec[0] + A.matrix[2][1] * B.vec[1] +
					 A.matrix[2][2] * B.vec[2] + A.matrix[2][3] * B.vec[3];

	result->vec[3] = A.matrix[3][0] * B.vec[0] + A.matrix[3][1] * B.vec[1] +
					 A.matrix[3][2] * B.vec[2] + A.matrix[3][3] * B.vec[3];
}
