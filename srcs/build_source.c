/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_source.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 00:12:10 by home              #+#    #+#             */
/*   Updated: 2020/05/15 22:58:12 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	poll_and_toolbar(void)
{
	bool	quit;
	SDL_Event	e;

	quit = false;
	while(!quit)
	{
		while( SDL_PollEvent( &e ) != 0 )
			if( e.type == SDL_QUIT )
				quit = true;
	}
}

void	draw_point(t_point point, t_display *display)
{
	//transform

	int	x_screen;
	int	y_screen;

	x_screen = point.x;
	y_screen = point.y;

	color_in((t_point){x_screen - 1, y_screen - 1}, 0xFF0000, display);
	color_in((t_point){x_screen + 0, y_screen - 1}, 0xFF0000, display);
	color_in((t_point){x_screen + 1, y_screen - 1}, 0xFF0000, display);

	color_in((t_point){x_screen - 1, y_screen + 0}, 0xFF0000, display);
	color_in((t_point){x_screen + 0, y_screen + 0}, 0xFF0000, display);
	color_in((t_point){x_screen + 1, y_screen + 0}, 0xFF0000, display);

	color_in((t_point){x_screen - 1, y_screen + 1}, 0xFF0000, display);
	color_in((t_point){x_screen + 0, y_screen + 1}, 0xFF0000, display);
	color_in((t_point){x_screen + 1, y_screen + 1}, 0xFF0000, display);
}
