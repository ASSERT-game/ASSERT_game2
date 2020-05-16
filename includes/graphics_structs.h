/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_structs.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:49:36 by home              #+#    #+#             */
/*   Updated: 2020/05/16 00:26:58 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_STRUCTS_H
# define GRAPHICS_STRUCTS_H

#include <SDL2/SDL.h>
#include "math_structs.h"

typedef struct	s_display
{
	SDL_Window		*window;
	unsigned char	*pixels;

	t_rect			shape;
	int				width;
	int				height;
	int				size;

	unsigned char	*background;

}				t_display;

typedef struct	s_camera
{
	t_matrix_4x4i	proj;
}				t_camera;

#endif
