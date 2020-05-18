/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:40:38 by home              #+#    #+#             */
/*   Updated: 2020/05/17 21:43:23 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	color_in(t_point location, int color, t_display *display)
{
	location.y = (WIN_HEIGHT - location.y);

	if (location.x < 0 || location.x > display->width ||
		location.y < 0 || location.y > display->height)
		return ;
	else
	{
		display->pixels[location.y * 1200 * BPP + location.x * BPP + 0] = color >> 0;
		display->pixels[location.y * 1200 * BPP + location.x * BPP + 1] = color >> 8;
		display->pixels[location.y * 1200 * BPP + location.x * BPP + 2] = color >> 16;
	}
}

void	camera_print(t_camera *camera)
{
	printf("Camera\n");
	printf("[ %3d, %3d, %3d, %3d \n",	camera->proj.matrix[0][0],
										camera->proj.matrix[0][1],
										camera->proj.matrix[0][2],
										camera->proj.matrix[0][3]);

	printf("[ %3d, %3d, %3d, %3d \n",	camera->proj.matrix[1][0],
										camera->proj.matrix[1][1],
										camera->proj.matrix[1][2],
										camera->proj.matrix[1][3]);

	printf("[ %3d, %3d, %3d, %3d \n",	camera->proj.matrix[2][0],
										camera->proj.matrix[2][1],
										camera->proj.matrix[2][2],
										camera->proj.matrix[2][3]);

	printf("[ %3d, %3d, %3d, %3d \n",	camera->proj.matrix[3][0],
										camera->proj.matrix[3][1],
										camera->proj.matrix[3][2],
										camera->proj.matrix[3][3]);
}
