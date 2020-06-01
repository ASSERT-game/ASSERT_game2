/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:40:38 by home              #+#    #+#             */
/*   Updated: 2020/05/30 04:12:44 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	color_in(t_vector_4f location, int color, t_display *display)
{
	location.vec[0] += WIN_WIDTH / 2.0;
	location.vec[1] = WIN_HEIGHT / 2.0 - location.vec[1];

	if (location.vec[0] < 0 || location.vec[0] > display->width ||
		location.vec[1] < 0 || location.vec[1] > display->height ||
		location.vec[2] < CAMERA_DEPTH || location.vec[2] > RENDER_DISTANCE ||
		display->depth_map[((int)location.vec[1]) * 1200 + ((int)location.vec[0])] < location.vec[2])
		return ;
	else
	{
		display->pixels[((int)location.vec[1]) * 1200 * BPP + ((int)location.vec[0]) * BPP + 0] = color >> 0;
		display->pixels[((int)location.vec[1]) * 1200 * BPP + ((int)location.vec[0]) * BPP + 1] = color >> 8;
		display->pixels[((int)location.vec[1]) * 1200 * BPP + ((int)location.vec[0]) * BPP + 2] = color >> 16;

		display->depth_map[((int)location.vec[1]) * 1200 + ((int)location.vec[0])] =location.vec[2];
	}
}

void	big_color_in(t_vector_4f location, int color, t_display *display)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 2;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			color_in(location, color, display);
			location.vec[1]++;
			j++;
		}
		location.vec[1] -= size;
		location.vec[0]++;
		i++;
	}
}
