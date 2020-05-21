/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_source.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 00:12:10 by home              #+#    #+#             */
/*   Updated: 2020/05/20 20:12:24 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	display_point(t_vector_4f spot, t_camera *camera, t_display *display);

void	poll_and_toolbar(t_display *display)
{
	bool	quit;
	SDL_Event	e;
	t_camera	camera;
	t_vector_4f	spot1;
	t_vector_4f	spot2;
	t_vector_4f	spot3;
	t_vector_4f	spot4;

	t_vector_4f	spot5;
	t_vector_4f	spot6;
	t_vector_4f	spot7;
	t_vector_4f	spot8;

	t_vector_4f	spot9;
	t_vector_4f	spot10;
	t_vector_4f	spot11;
	t_vector_4f	spot12;

	t_vector_4f	vanishing;

	const Uint8	*keystate;

	quit = false;

	vector4f_fill(&spot1, -100, 200, 50);
	vector4f_fill(&spot2,  100, 200, 50);
	vector4f_fill(&spot3, -100,   0, 50);
	vector4f_fill(&spot4,  100,   0, 50);

	vector4f_fill(&spot5, -100, 200, 75);
	vector4f_fill(&spot6,  100, 200, 75);
	vector4f_fill(&spot7, -100,   0, 75);
	vector4f_fill(&spot8,  100,   0, 75);

	vector4f_fill(&spot9,  -100, 200, 120);
	vector4f_fill(&spot10,  100, 200, 120);
	vector4f_fill(&spot11, -100,   0, 120);
	vector4f_fill(&spot12,  100,   0, 120);

	vector4f_fill(&vanishing,  100,   0, 10000);

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
		if (keystate[SDL_SCANCODE_COMMA])
			camera.roll++;
		if (keystate[SDL_SCANCODE_PERIOD])
			camera.roll--;
		if (keystate[SDL_SCANCODE_SEMICOLON])
			camera.yaw++;
		if (keystate[SDL_SCANCODE_L])
			camera.yaw--;

		printf("Front Set\n");
		display_point(spot1, &camera, display);
		display_point(spot2, &camera, display);
		display_point(spot3, &camera, display);
		display_point(spot4, &camera, display);

		printf("Back Set\n");
		display_point(spot5, &camera, display);
		display_point(spot6, &camera, display);
		display_point(spot7, &camera, display);
		display_point(spot8, &camera, display);

		display_point(spot9, &camera, display);
		display_point(spot10, &camera, display);
		display_point(spot11, &camera, display);
		display_point(spot12, &camera, display);
		printf("END\n");

		display_point(vanishing, &camera, display);

		refresh_display(display);
	}
}

void	display_point(t_vector_4f spot, t_camera *camera, t_display *display)
{
	int			roll;
	int			yaw;
	t_vector_4f	transform;

	if (camera->roll == 360)
		camera->roll = 0;
	if (camera->roll == -1)
		camera->roll = 359;

	if (camera->yaw == 360)
		camera->yaw = 0;
	if (camera->yaw == -1)
		camera->yaw = 359;

	yaw = camera->yaw;
	roll = camera->roll;

	camera->proj.matrix[0][0] = cosd(roll) * cosd(yaw);
	camera->proj.matrix[0][1] = sind(roll) * cosd(yaw);
	camera->proj.matrix[0][2] = sind(yaw);

	camera->proj.matrix[1][0] = -sind(roll);
	camera->proj.matrix[1][1] = cosd(roll);
	camera->proj.matrix[1][2] = 0;

	camera->proj.matrix[2][0] = -cosd(roll) * sind(yaw);
	camera->proj.matrix[2][1] = -sind(roll) * sind(yaw);
	camera->proj.matrix[2][2] = cosd(yaw);

	matrix_mult(camera->proj, spot, &transform);
	cam_proj(&transform);
	draw_point(transform, display);

	// vector4f_print(&transform);
}

void	draw_point(t_vector_4f point, t_display *display)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 3;
	point.vec[0] -= (size / 2);
	point.vec[1] -= (size / 2);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			color_in(point, 0xFF0000, display);
			point.vec[1]++;
			j++;
		}
		point.vec[1] -= size;
		point.vec[0]++;
		i++;
	}
}
