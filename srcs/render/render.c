/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 00:23:26 by home              #+#    #+#             */
/*   Updated: 2020/05/10 00:45:05 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	refresh_display(t_display *display)
{
	apply_background(display->pixels, display->background,
					display->width * display->height);
	SDL_UpdateWindowSurface(display->window);
}
