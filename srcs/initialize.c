/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:24:16 by home              #+#    #+#             */
/*   Updated: 2020/05/21 17:45:16 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

int		SDLG_setup(t_display *dest)
{
	SDL_Window	*window;
	SDL_Surface	*surface;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(WIN_TITLE,
				2000, 100,
				WIN_WIDTH, WIN_HEIGHT,
				SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);

	dest->window = window;
	dest->pixels = surface->pixels;
	dest->background = make_background(0x000000, WIN_WIDTH * WIN_HEIGHT);

	rect_fill(&dest->shape, &(t_point){0, 0}, &(t_point){WIN_WIDTH, WIN_HEIGHT});
	dest->width = WIN_WIDTH;
	dest->height = WIN_HEIGHT;
	dest->size = dest->width * dest->height;

	dest->depth_map = malloc(sizeof(*(dest->depth_map)) * (dest->size));

	dest->active = true;

	return (SUCCESS);
}
