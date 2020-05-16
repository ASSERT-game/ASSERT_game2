/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:40:38 by home              #+#    #+#             */
/*   Updated: 2020/05/16 00:32:34 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	color_in(t_point location, int color, t_display *display)
{
	if (location.x < 0 || location.x > display->height ||
		location.y < 0 || location.y > display->width)
		return ;
	else
	{
		display->pixels[location.x * 1200 * BPP + location.y * BPP + 0] = color >> 0;
		display->pixels[location.x * 1200 * BPP + location.y * BPP + 1] = color >> 8;
		display->pixels[location.x * 1200 * BPP + location.y * BPP + 2] = color >> 16;
	}
}
