/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 00:23:26 by home              #+#    #+#             */
/*   Updated: 2020/05/17 17:06:57 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	refresh_display(t_display *display)
{
	SDL_UpdateWindowSurface(display->window);
	apply_background(display->pixels, display->background, display->size);
}
