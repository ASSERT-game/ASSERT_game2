/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 01:13:41 by home              #+#    #+#             */
/*   Updated: 2020/05/27 16:12:56 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	convert_to_frame_of_reference(t_render_primative *triangle, t_camera *frame)
{
	t_vector_4f	origin;
	t_vector_4f	temp;

	origin.vec[0] = frame->proj.matrix[0][3];
	origin.vec[1] = frame->proj.matrix[1][3];
	origin.vec[2] = frame->proj.matrix[2][3];

	vector4f_subtract(&(triangle->A), &origin, &(temp));
	matrix_mult_rel(frame->proj, temp, &(triangle->screen_A));
	cam_proj(&(triangle->screen_A));

	vector4f_subtract(&(triangle->B), &origin, &(temp));
	matrix_mult_rel(frame->proj, temp, &(triangle->screen_B));
	cam_proj(&(triangle->screen_B));

	vector4f_subtract(&(triangle->C), &origin, &(temp));
	matrix_mult_rel(frame->proj, temp, &(triangle->screen_C));
	cam_proj(&(triangle->screen_C));
}

void	create_line(t_vector_4f *p1, t_vector_4f *p2, double *m, double *h, double *k)
{
	*m = (p2->vec[1] - p1->vec[1]) / (p2->vec[0] - p1->vec[0]);

	*h = (p1->vec[0]);
	*k = (p1->vec[1]);
}

bool		inside_screen_triangle(t_render_primative *triangle, int x, int y)
{
	bool	result;
	double	m;
	double	h;
	double	k;

	create_line(&(triangle->A), &(triangle->B), &m, &h, &k);

	result = false;
	if (x < y)
		result = true;

	return (result);
}

void	rasterize_triangle(t_render_primative *triangle, t_camera *camera, t_display *display)
{
	t_rect	triangle_area;

	convert_to_frame_of_reference(triangle, camera);

	triangle_area.start.x = min_of_threef(triangle->screen_A.vec[0], triangle->screen_B.vec[0], triangle->screen_C.vec[0]);
	triangle_area.start.y = min_of_threef(triangle->screen_A.vec[1], triangle->screen_B.vec[1], triangle->screen_C.vec[1]);

	triangle_area.end.x = max_of_threef(triangle->screen_A.vec[0], triangle->screen_B.vec[0], triangle->screen_C.vec[0]);
	triangle_area.end.y = max_of_threef(triangle->screen_A.vec[1], triangle->screen_B.vec[1], triangle->screen_C.vec[1]);

	if (triangle_area.start.x < 0)
		triangle_area.start.x = 0;
	if (triangle_area.start.y < 0)
		triangle_area.start.y = 0;

	if (triangle_area.end.x > WIN_WIDTH)
		triangle_area.end.x = WIN_WIDTH;
	if (triangle_area.end.y > WIN_WIDTH)
		triangle_area.end.y = WIN_WIDTH;

	rect_print(&triangle_area);

	draw_point(triangle->screen_A, display);
	draw_point(triangle->screen_B, display);
	draw_point(triangle->screen_C, display);
}
