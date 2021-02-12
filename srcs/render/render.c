/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 00:23:26 by home              #+#    #+#             */
/*   Updated: 2020/06/06 13:42:59 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	reset_depth_map(int *depth_map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		depth_map[i] = RENDER_DISTANCE + 1;
		i++;
	}
}

void	refresh_display(t_display *display)
{
	SDL_UpdateWindowSurface(display->window);
	apply_background(display->pixels, display->background, display->size);
	reset_depth_map(display->depth_map, display->size);
}
