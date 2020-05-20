/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:40:38 by home              #+#    #+#             */
/*   Updated: 2020/05/20 05:00:23 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	color_in(t_vector_4f location, int color, t_display *display)
{
	if (location.vec[0] < 0 || location.vec[0] > display->width ||
		location.vec[1] < 0 || location.vec[1] > display->height ||
		location.vec[2] < 0 || location.vec[2] > RENDER_DISTANCE)
		return ;
	else
	{
		display->pixels[((int)location.vec[1]) * 1200 * BPP + ((int)location.vec[0]) * BPP + 0] = color >> 0;
		display->pixels[((int)location.vec[1]) * 1200 * BPP + ((int)location.vec[0]) * BPP + 1] = color >> 8;
		display->pixels[((int)location.vec[1]) * 1200 * BPP + ((int)location.vec[0]) * BPP + 2] = color >> 16;
	}
}
