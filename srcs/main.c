/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 21:00:54 by home              #+#    #+#             */
/*   Updated: 2020/05/07 20:37:32 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <SDL2/SDL.h>

void	prints(void);

int	main(void)
{
	SDL_Window	*window = NULL;
	SDL_Surface	*surface = NULL;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("SDL Tut",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_CENTERED,
			100, 100, SDL_WINDOW_SHOWN);

	surface = SDL_GetWindowSurface(window);
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);

	SDL_Delay(20000);

	SDL_DestroyWindow(window);
	SDL_Quit();

	prints();
	printf("Testing\n");
	(void)window;
	(void)surface;
	return (0);
}
