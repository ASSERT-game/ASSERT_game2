/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:24:16 by home              #+#    #+#             */
/*   Updated: 2020/05/08 20:43:11 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_structs.h"
#include "window_config.h"

void	SDLG_setup(void)
{
	SDL_Window	*window;
	// SDL_Surface	*surface;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(WIN_TITLE,
				1400, SDL_WINDOWPOS_CENTERED,
				WIN_WIDTH, WIN_HEIGHT,
				SDL_WINDOW_SHOWN);
}
