/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_source.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 00:12:10 by home              #+#    #+#             */
/*   Updated: 2020/05/17 15:37:44 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	poll_and_toolbar(t_display *display)
{
	bool	quit;
	SDL_Event	e;
	t_camera	camera;
	t_vector_4i	spot;
	t_vector_4i	transform;

	quit = false;

	vector4i_fill(&spot, 100, 100, 5);

	init_camera(&camera);
	apply_background(display->pixels, display->background, display->size);

	while(!quit)
	{
		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
				quit = true;
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_d)
					camera.proj.matrix[0][3]++;
				else if (e.key.keysym.sym == SDLK_a)
					camera.proj.matrix[0][3]--;
				else if (e.key.keysym.sym == SDLK_w)
					camera.proj.matrix[1][3]++;
				else if (e.key.keysym.sym == SDLK_s)
					camera.proj.matrix[1][3]--;
			}
		}

		matrix_mult(camera.proj, spot, &transform);
		draw_point(transform, display);

		printf("\n\n\nSPACE\n");
		vector4i_print(&transform);

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
