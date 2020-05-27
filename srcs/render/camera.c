/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 01:59:06 by home              #+#    #+#             */
/*   Updated: 2020/05/26 18:07:32 by home             ###   ########.fr       */
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

	dest->proj.matrix[1][3] = 100;

	dest->roll = 0;
	dest->yaw = 0;
}

void	cam_proj(t_vector_4f *transform)
{
	double scale;

	scale = CAMERA_DEPTH / (double)transform->vec[2];
	scale *= 50;

	transform->vec[0] = (transform->vec[0] * scale + (WIN_WIDTH / 2));
	transform->vec[1] = WIN_HEIGHT - (transform->vec[1] * scale + (WIN_HEIGHT / 2));
}

void	camera_update(t_camera *camera)
{
	int	roll;
	int	yaw;

	if (camera->roll == 360)
		camera->roll = 0;
	if (camera->roll == -1)
		camera->roll = 359;

	if (camera->yaw == 360)
		camera->yaw = 0;
	if (camera->yaw == -1)
		camera->yaw = 359;

	yaw = camera->yaw;
	roll = camera->roll;

	camera->proj.matrix[0][0] = cosd(roll) * cosd(yaw);
	camera->proj.matrix[0][1] = sind(roll) * cosd(yaw);
	camera->proj.matrix[0][2] = sind(yaw);

	camera->proj.matrix[1][0] = -sind(roll);
	camera->proj.matrix[1][1] = cosd(roll);
	camera->proj.matrix[1][2] = 0;

	camera->proj.matrix[2][0] = -cosd(roll) * sind(yaw);
	camera->proj.matrix[2][1] = -sind(roll) * sind(yaw);
	camera->proj.matrix[2][2] = cosd(yaw);
}

void	camera_print(t_camera *camera)
{
	printf("Camera\n");
	printf("[ %3f, %3f, %3f, %3f \n",	camera->proj.matrix[0][0],
										camera->proj.matrix[0][1],
										camera->proj.matrix[0][2],
										camera->proj.matrix[0][3]);

	printf("[ %3f, %3f, %3f, %3f \n",	camera->proj.matrix[1][0],
										camera->proj.matrix[1][1],
										camera->proj.matrix[1][2],
										camera->proj.matrix[1][3]);

	printf("[ %3f, %3f, %3f, %3f \n",	camera->proj.matrix[2][0],
										camera->proj.matrix[2][1],
										camera->proj.matrix[2][2],
										camera->proj.matrix[2][3]);

	printf("[ %3f, %3f, %3f, %3f \n",	camera->proj.matrix[3][0],
										camera->proj.matrix[3][1],
										camera->proj.matrix[3][2],
										camera->proj.matrix[3][3]);
}
