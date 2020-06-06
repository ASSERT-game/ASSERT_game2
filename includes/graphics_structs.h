/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_structs.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:49:36 by home              #+#    #+#             */
/*   Updated: 2020/06/02 03:16:37 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_STRUCTS_H
# define GRAPHICS_STRUCTS_H

# include <SDL2/SDL.h>
# include "math_structs.h"
# include <stdbool.h>

typedef struct	s_display
{
	SDL_Window		*window;
	unsigned char	*pixels;

	t_rect			shape;
	int				width;
	int				height;
	int				size;

	unsigned char	*background;
	int				*depth_map;

	bool			active;

}				t_display;

typedef struct	s_camera
{
	t_matrix_4x4f	proj;
	int				roll;
	int				yaw;
}				t_camera;

typedef struct	s_render_primative
{
	//texture
	//uv_triangle
	//world_triangle

	t_vector_4f	A;
	t_vector_4f	B;
	t_vector_4f	C;

	t_vector_4f	screen_A;
	t_vector_4f	screen_B;
	t_vector_4f	screen_C;

	t_vector_4f	uv_A;
	t_vector_4f	uv_B;
	t_vector_4f	uv_C;


}				t_render_primative;

#endif
