/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 01:13:41 by home              #+#    #+#             */
/*   Updated: 2020/05/27 16:36:37 by home             ###   ########.fr       */
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

#define LESS_THAN -1
#define GREATER_THAN 1

bool		inequality_match(double m, double h, double k, t_vector_4f p1, t_vector_4f p2)
{
	bool	result;
	int		side;
	double	y;

	side = GREATER_THAN;
	y = m * (p1.vec[0] - h) + k;
	if (y <= p1.vec[1])
		side = LESS_THAN;

	result = false;
	y = m * (p2.vec[0] - h) + k;
	if (side == LESS_THAN && y <= p2.vec[1])
		result = true;
	if (side == GREATER_THAN && y <= p2.vec[1])
		result = true;
	return (result);
}

bool		inside_screen_triangle(t_render_primative *triangle, int x, int y)
{
	bool		result;
	t_vector_4f	test;
	double		m;
	double		h;
	double		k;

	result = true;
	test.vec[0] = x;
	test.vec[1] = y;

	create_line(&(triangle->screen_A), &(triangle->screen_B), &m, &h, &k);
	result &= inequality_match(m, h, k, triangle->screen_C, test);

	create_line(&(triangle->screen_B), &(triangle->screen_C), &m, &h, &k);
	result &= inequality_match(m, h, k, triangle->screen_A, test);

	create_line(&(triangle->screen_C), &(triangle->screen_A), &m, &h, &k);
	result &= inequality_match(m, h, k, triangle->screen_B, test);

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

	int			i;
	int			j;
	t_vector_4f	pixel;

	i = triangle_area.start.x;
	while (i < triangle_area.end.x)
	{
		j = triangle_area.start.y;
		while (j < triangle_area.end.y)
		{
			if (inside_screen_triangle(triangle, i, j) == true)
			{
				pixel.vec[0] = i;
				pixel.vec[1] = j;
				pixel.vec[2] = 20;
				color_in(pixel, 0x858585, display);
			}
			j++;
		}
		i++;
	}

	draw_point(triangle->screen_A, display);
	draw_point(triangle->screen_B, display);
	draw_point(triangle->screen_C, display);
}
