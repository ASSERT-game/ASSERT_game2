/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 17:41:20 by home              #+#    #+#             */
/*   Updated: 2020/05/21 17:52:41 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

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
		camera->proj.matrix[0][3]--;
	if (keystate[SDL_SCANCODE_A])
		camera->proj.matrix[0][3]++;
	if (keystate[SDL_SCANCODE_W])
		camera->proj.matrix[1][3]++;
	if (keystate[SDL_SCANCODE_S])
		camera->proj.matrix[1][3]--;
	if (keystate[SDL_SCANCODE_COMMA])
		camera->roll++;
	if (keystate[SDL_SCANCODE_PERIOD])
		camera->roll--;
	if (keystate[SDL_SCANCODE_SEMICOLON])
		camera->yaw++;
	if (keystate[SDL_SCANCODE_L])
		camera->yaw--;
}
