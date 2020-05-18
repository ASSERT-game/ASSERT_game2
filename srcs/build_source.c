/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_source.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 00:12:10 by home              #+#    #+#             */
/*   Updated: 2020/05/17 21:06:58 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	display_point(t_vector_4i spot, t_camera *camera, t_display *display);

void	poll_and_toolbar(t_display *display)
{
	bool	quit;
	SDL_Event	e;
	t_camera	camera;
	t_vector_4i	spot1;
	t_vector_4i	spot2;
	t_vector_4i	spot3;
	t_vector_4i	spot4;

	t_vector_4i	spot5;
	t_vector_4i	spot6;
	t_vector_4i	spot7;
	t_vector_4i	spot8;

	const Uint8	*keystate;

	quit = false;

	vector4i_fill(&spot1, -100, 200, 50);
	vector4i_fill(&spot2,  100, 200, 50);
	vector4i_fill(&spot3, -100,   0, 50);
	vector4i_fill(&spot4,  100,   0, 50);

	vector4i_fill(&spot5, -100, 200, 70);
	vector4i_fill(&spot6,  100, 200, 70);
	vector4i_fill(&spot7, -100,   0, 70);
	vector4i_fill(&spot8,  100,   0, 70);

	init_camera(&camera);
	apply_background(display->pixels, display->background, display->size);

	while(!quit)
	{
		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
				quit = true;
		}
		keystate = SDL_GetKeyboardState(NULL);
		if (keystate[SDL_SCANCODE_D])
			camera.proj.matrix[0][3]--;
		if (keystate[SDL_SCANCODE_A])
			camera.proj.matrix[0][3]++;
		if (keystate[SDL_SCANCODE_W])
			camera.proj.matrix[1][3]++;
		if (keystate[SDL_SCANCODE_S])
			camera.proj.matrix[1][3]--;

		printf("Front Set\n");
		display_point(spot1, &camera, display);
		display_point(spot2, &camera, display);
		display_point(spot3, &camera, display);
		display_point(spot4, &camera, display);

		printf("Back Set\n'");
		display_point(spot5, &camera, display);
		display_point(spot6, &camera, display);
		display_point(spot7, &camera, display);
		display_point(spot8, &camera, display);
		printf("END\n");

		refresh_display(display);
	}
}

void	display_point(t_vector_4i spot, t_camera *camera, t_display *display)
{
	t_vector_4i	transform;

	matrix_mult(camera->proj, spot, &transform);
	cam_proj(&transform);
	draw_point(transform, display);

	vector4i_print(&transform);
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
