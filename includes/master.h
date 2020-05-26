/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:55:52 by home              #+#    #+#             */
/*   Updated: 2020/05/26 01:31:13 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

# include <string.h>
# include <strings.h>

# include "debug.h"
# include "graphics_structs.h"
# include "ft_math.h"
# include "window_config.h"

# define SUCCESS 1
# define FAILURE 0

void			color_in(t_vector_4f point, int color, t_display *display);
void			draw_point(t_vector_4f point, t_display *display);

void			poll_and_toolbar(t_display *display);
void			update_state(t_display *display, t_camera *camera);

int				SDLG_setup(t_display *dest);

void			init_camera(t_camera *dest);
void			cam_proj(t_vector_4f *transform);

void			refresh_display(t_display *display);
void			apply_background(unsigned char *dest, unsigned char *source, int pixels);
unsigned char	*make_background(int color, int total_pixels);

void			fill_cube(t_vector_4f *dest, int size);
void			draw_cube(t_camera *camera, t_display *display, t_vector_4f *cube, int size);
void			display_point(t_vector_4f spot, t_camera *camera, t_display *display);
void			rasterize_triangle(t_render_primative *triangle, t_camera *camera, t_display *display);

#endif
