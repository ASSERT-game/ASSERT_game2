/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 17:41:20 by home              #+#    #+#             */
/*   Updated: 2020/11/23 15:19:40 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

#define WALK_SPEED 15
#define STRAFE_BIAS 1.75
#define ROTATION_SPEED 1

void	update_state(t_display *display, t_camera *camera)
{
	static int	jump;
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

	if (keystate[SDL_SCANCODE_DOWN])
	{
		camera->proj.matrix[1][3] -= WALK_SPEED;
		// camera->proj.matrix[2][3] += WALK_SPEED * sind(camera->yaw + 90);
	}
	if (keystate[SDL_SCANCODE_UP])
	{
		camera->proj.matrix[1][3] += WALK_SPEED;
		// camera->proj.matrix[2][3] -= WALK_SPEED * sind(camera->yaw + 90);
	}

	if (keystate[SDL_SCANCODE_SPACE] && jump == 0)
	{
		jump = 20;
		// camera->proj.matrix[2][3] -= WALK_SPEED * sind(camera->yaw + 90);
	}

	if (jump > 0)
	{
		camera->proj.matrix[1][3] = -2 * (jump - 0) * (jump - 20) + 100;
		jump--;
	}

	if (keystate[SDL_SCANCODE_COMMA])
		camera->roll += ROTATION_SPEED;
	if (keystate[SDL_SCANCODE_PERIOD])
		camera->roll -= ROTATION_SPEED;

	if (keystate[SDL_SCANCODE_LEFT])
		camera->yaw += ROTATION_SPEED;
	if (keystate[SDL_SCANCODE_RIGHT])
		camera->yaw -= ROTATION_SPEED;
}
