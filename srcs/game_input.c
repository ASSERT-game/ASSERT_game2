/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 17:41:20 by home              #+#    #+#             */
/*   Updated: 2020/05/26 04:37:44 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

#define WALK_SPEED 15
#define STRAFE_BIAS 1.75
#define ROTATION_SPEED 3

void	update_state(t_display *display, t_camera *camera)
{
	SDL_Event	e;
	const Uint8	*keystate;

	while(SDL_PollEvent(&e) != 0)
	{
		if(e.type == SDL_QUIT)
			display->active = false;
	}
	keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_SCANCODE_D])
	{
		camera->proj.matrix[0][3] += WALK_SPEED * cosd(camera->yaw) * STRAFE_BIAS;
		camera->proj.matrix[2][3] += WALK_SPEED * sind(camera->yaw) * STRAFE_BIAS;
	}
	if (keystate[SDL_SCANCODE_A])
	{
		camera->proj.matrix[0][3] -= WALK_SPEED * cosd(camera->yaw) * STRAFE_BIAS;
		camera->proj.matrix[2][3] -= WALK_SPEED * sind(camera->yaw) * STRAFE_BIAS;
	}

	if (keystate[SDL_SCANCODE_W])
	{
		camera->proj.matrix[0][3] += WALK_SPEED * cosd(camera->yaw + 90);
		camera->proj.matrix[2][3] += WALK_SPEED * sind(camera->yaw + 90);
	}
	if (keystate[SDL_SCANCODE_S])
	{
		camera->proj.matrix[0][3] -= WALK_SPEED * cosd(camera->yaw + 90);
		camera->proj.matrix[2][3] -= WALK_SPEED * sind(camera->yaw + 90);
	}

	// if (keystate[SDL_SCANCODE_COMMA])
	// 	camera->roll += ROTATION_SPEED;
	// if (keystate[SDL_SCANCODE_PERIOD])
	// 	camera->roll -= ROTATION_SPEED;
	// if (keystate[SDL_SCANCODE_SEMICOLON])
	// 	camera->yaw += ROTATION_SPEED;
	// if (keystate[SDL_SCANCODE_L])
	// 	camera->yaw -= ROTATION_SPEED;
	if (keystate[SDL_SCANCODE_COMMA])
		camera->yaw += ROTATION_SPEED;
	if (keystate[SDL_SCANCODE_PERIOD])
		camera->yaw -= ROTATION_SPEED;
}
