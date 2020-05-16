/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:24:16 by home              #+#    #+#             */
/*   Updated: 2020/05/16 01:57:23 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

int		SDLG_setup(t_display *dest)
{
	SDL_Window	*window;
	SDL_Surface	*surface;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(WIN_TITLE,
				1400, SDL_WINDOWPOS_CENTERED,
				WIN_WIDTH, WIN_HEIGHT,
				SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);

	dest->window = window;
	dest->pixels = surface->pixels;
	dest->background = make_background(0x1ee397, WIN_WIDTH * WIN_HEIGHT);

	rect_fill(&dest->shape, &(t_point){0, 0}, &(t_point){WIN_WIDTH, WIN_HEIGHT});
	dest->width = WIN_WIDTH;
	dest->height = WIN_HEIGHT;
	dest->size = dest->width * dest->height;


	return (SUCCESS);
}
