/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 01:59:06 by home              #+#    #+#             */
/*   Updated: 2020/05/17 21:43:52 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

#define CAMERA_WIDTH 400
#define CAMERA_HEIGHT 200

void	init_camera(t_camera *dest)
{
	bzero(&dest->proj.matrix, sizeof(dest->proj.matrix));

	dest->proj.matrix[0][0] = 1;
	dest->proj.matrix[1][1] = 1;
	dest->proj.matrix[2][2] = 1;
	dest->proj.matrix[3][3] = 1;

	// dest->proj.matrix[1][3] = WIN_HEIGHT / 2;
}

void	cam_proj(t_vector_4i *transform)
{
	double scale;

	scale = CAMERA_DEPTH / (double)transform->vec[2];

	transform->vec[0] = transform->vec[0] * scale + (WIN_WIDTH / 2);
	transform->vec[1] = transform->vec[1] * scale + (WIN_HEIGHT / 2);
}
