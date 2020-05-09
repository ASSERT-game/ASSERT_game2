/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 21:00:54 by home              #+#    #+#             */
/*   Updated: 2020/05/08 21:19:16 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

// #include <SDL2/SDL.h>

void	prints(void);

int	main(void)
{
	bool	quit;
	t_rect	rect;
	SDL_Window	*win;
	SDL_Event	e;


	point_fill(&(rect.start), 0, 0);
	point_fill(&(rect.end), 100, 100);
	rect_print(&rect);
	rect_update(&rect, &(rect.start));
	rect_print(&rect);
	SDLG_setup();

	quit = false;
	while(!quit)
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
		}
	}
	(void)win;
	return (0);
}
