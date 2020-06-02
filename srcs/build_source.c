/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_source.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 00:12:10 by home              #+#    #+#             */
/*   Updated: 2020/06/01 05:00:51 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	poll_and_toolbar(t_display *display)
{
	t_camera	camera;

	t_vector_4f	vanishing;
	t_vector_4f	origin;


	int i;
	t_render_primative	*cube_m;
	cube_m = cube_mesh(&vanishing);

	t_render_primative	triangle;
	fill_render_primitive(&triangle,
			(t_vector_4f){{ 100,    0, 700, 1}, 0xff0000},
			(t_vector_4f){{ 100,  150, 700, 1}, 0x00ff00},
			(t_vector_4f){{   0,  100, 760, 1}, 0x0000ff}
	);

	init_camera(&camera);
	vector4f_fill_c(&vanishing,  100,   0, 10000, 0xFFFFFF);
	vector4f_fill_c(&origin,       0,   0,     0, 0x0000FF);


	while(display->active == true)
	{
		update_state(display, &camera);
		camera_update(&camera);

		i = 0;
		// while (i < 12)
		// {
		// 	rasterize_triangle(&cube_m[i], &camera, display);
		// 	i++;
		// }

		rasterize_triangle(&triangle, &camera, display);

		display_point(vanishing, &camera, display);
		display_point(origin, &camera, display);
		refresh_display(display);
	}
}

void	display_point(t_vector_4f spot, t_camera *camera, t_display *display)
{
	t_vector_4f	transform;

	spot.vec[0] -= camera->proj.matrix[0][3];
	spot.vec[1] -= camera->proj.matrix[1][3];
	spot.vec[2] -= camera->proj.matrix[2][3];

	matrix_mult_rel(camera->proj, spot, &transform);
	cam_proj(&transform);
	transform.color = spot.color;
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
			color_in(point, point.color, display);
			point.vec[1]++;
			j++;
		}
		point.vec[1] -= size;
		point.vec[0]++;
		i++;
	}
}
