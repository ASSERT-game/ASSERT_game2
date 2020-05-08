/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_structs.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:49:36 by home              #+#    #+#             */
/*   Updated: 2020/05/07 22:52:17 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_STRUCTS_H
# define GRAPHICS_STRUCTS_H

#include <SDL2/SDL.h>
#include "math_structs.h"

typedef struct	s_window
{
	t_rect			shape;

	SDL_Renderer	*renderer;
}				t_window;

#endif
