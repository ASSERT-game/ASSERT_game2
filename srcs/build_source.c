/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_source.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 00:12:10 by home              #+#    #+#             */
/*   Updated: 2020/05/16 02:12:47 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	poll_and_toolbar(t_display *display)
{
	bool	quit;
	SDL_Event	e;
	t_camera	camera;

	quit = false;

	init_camera(&camera);
	apply_background(display->pixels, display->background, display->size);

	while(!quit)
	{
		while( SDL_PollEvent( &e ) != 0 )
		{
			if( e.type == SDL_QUIT )
				quit = true;

		}
		refresh_display(display);
	}
}

void	draw_point(t_vector_4i point, t_display *display)
{
	//transform

	int	x_screen;
	int	y_screen;

	x_screen = point.vec[0];
	y_screen = point.vec[1];

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
