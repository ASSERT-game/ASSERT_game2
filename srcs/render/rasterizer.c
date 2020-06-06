/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 01:13:41 by home              #+#    #+#             */
/*   Updated: 2020/06/03 07:11:24 by home             ###   ########.fr       */
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
	origin.vec[3] = frame->proj.matrix[3][3];

	vector4f_subtract(&(triangle->A), &origin, &(temp));
	matrix_mult_rel(frame->proj, temp, &(triangle->screen_A));

	vector4f_subtract(&(triangle->B), &origin, &(temp));
	matrix_mult_rel(frame->proj, temp, &(triangle->screen_B));

	vector4f_subtract(&(triangle->C), &origin, &(temp));
	matrix_mult_rel(frame->proj, temp, &(triangle->screen_C));


	// if (triangle->screen_A.vec[2] < 0)
	// {
	// 	triangle->screen_A.vec[0] = triangle->screen_C.vec[0] + triangle->screen_C.vec[0] - triangle->screen_A.vec[0];
	// 	triangle->screen_A.vec[1] = triangle->screen_C.vec[1] + triangle->screen_C.vec[1] - triangle->screen_A.vec[1];
	// }

	// if (triangle->screen_B.vec[2] < 0)
	// {
	// 	triangle->screen_B.vec[0] = triangle->screen_C.vec[0] + triangle->screen_C.vec[0] - triangle->screen_B.vec[0];
	// 	triangle->screen_B.vec[1] = triangle->screen_C.vec[1] + triangle->screen_C.vec[1] - triangle->screen_B.vec[1];
	// }

	// if (triangle->screen_C.vec[2] < 0)
	// {
	// 	triangle->screen_C.vec[0] = triangle->screen_B.vec[0] + triangle->screen_B.vec[0] - triangle->screen_C.vec[0];
	// 	triangle->screen_C.vec[1] = triangle->screen_B.vec[1] + triangle->screen_B.vec[1] - triangle->screen_C.vec[1];
	// }

	cam_proj(&(triangle->screen_A));
	cam_proj(&(triangle->screen_B));
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
	if (side == GREATER_THAN && y > p2.vec[1])
		result = true;
	return (result);
}

bool		inside_screen_triangle(t_render_primative *triangle, int x, int y)
{
	t_vector_4f	test;
	double		m;
	double		h;
	double		k;

	test.vec[0] = x;
	test.vec[1] = y;

	create_line(&(triangle->screen_A), &(triangle->screen_B), &m, &h, &k);
	if (inequality_match(m, h, k, triangle->screen_C, test) == false)
		return (false);

	create_line(&(triangle->screen_B), &(triangle->screen_C), &m, &h, &k);
	if (inequality_match(m, h, k, triangle->screen_A, test) == false)
		return (false);

	create_line(&(triangle->screen_C), &(triangle->screen_A), &m, &h, &k);
	if (inequality_match(m, h, k, triangle->screen_B, test) == false)
		return (false);

	return (true);
}

t_vector_4f	*top_vertex(t_render_primative *triangle)
{
	t_vector_4f	*top;

	top = &(triangle->screen_A);

	if (top->vec[1] < triangle->screen_B.vec[1])
		top = &(triangle->screen_B);
	else if (top->vec[1] == triangle->screen_B.vec[1] && top->vec[0] > triangle->screen_B.vec[0])
		top = &(triangle->screen_B);

	if (top->vec[1] < triangle->screen_C.vec[1])
		top = &(triangle->screen_C);
	else if (top->vec[1] == triangle->screen_C.vec[1] && top->vec[0] > triangle->screen_C.vec[0])
		top = &(triangle->screen_B);

	return (top);
}

t_vector_4f	*bottom_vertex(t_render_primative *triangle)
{
	t_vector_4f	*bottom;

	bottom = &(triangle->screen_A);

	if (bottom->vec[1] > triangle->screen_B.vec[1])
		bottom = &(triangle->screen_B);
	else if (bottom->vec[1] == triangle->screen_B.vec[1] && bottom->vec[0] < triangle->screen_B.vec[0])
		bottom = &(triangle->screen_B);

	if (bottom->vec[1] > triangle->screen_C.vec[1])
		bottom = &(triangle->screen_C);
	else if (bottom->vec[1] == triangle->screen_C.vec[1] && bottom->vec[0] < triangle->screen_C.vec[0])
		bottom = &(triangle->screen_B);

	return (bottom);
}

t_vector_4f *middle_vertex(t_render_primative *triangle, t_vector_4f *top, t_vector_4f *bottom)
{
	t_vector_4f	*middle;

	if (top != &(triangle->screen_A) && bottom != &(triangle->screen_A))
		middle = &(triangle->screen_A);
	else if (top != &(triangle->screen_B) && bottom != &(triangle->screen_B))
		middle = &(triangle->screen_B);
	else
		middle = &(triangle->screen_C);
	return (middle);
}

void	rasterize_triangle(t_render_primative *triangle, t_camera *camera, t_display *display)
{
	t_rect	triangle_area;

	convert_to_frame_of_reference(triangle, camera);

	if (triangle->screen_A.vec[2] < 200 && triangle->screen_B.vec[2] < 200 && triangle->screen_C.vec[2] < 200)
		return ;

	triangle_area.start.x = min_of_threef(triangle->screen_A.vec[0], triangle->screen_B.vec[0], triangle->screen_C.vec[0]);
	triangle_area.start.y = min_of_threef(triangle->screen_A.vec[1], triangle->screen_B.vec[1], triangle->screen_C.vec[1]);

	triangle_area.end.x = max_of_threef(triangle->screen_A.vec[0], triangle->screen_B.vec[0], triangle->screen_C.vec[0]);
	triangle_area.end.y = max_of_threef(triangle->screen_A.vec[1], triangle->screen_B.vec[1], triangle->screen_C.vec[1]);

	if (triangle_area.start.x < -(WIN_WIDTH / 2))
		triangle_area.start.x = -(WIN_WIDTH / 2);
	if (triangle_area.start.y < -(WIN_HEIGHT / 2))
		triangle_area.start.y = -(WIN_HEIGHT / 2);

	if (triangle_area.end.x > (WIN_WIDTH / 2))
		triangle_area.end.x = (WIN_WIDTH / 2);
	if (triangle_area.end.y > (WIN_WIDTH / 2))
		triangle_area.end.y = (WIN_WIDTH / 2);

	int			i;
	int			j;
	t_vector_4f	pixel;

	i = triangle_area.start.x - 2;
	while (i < triangle_area.end.x + 2)
	{
		j = triangle_area.start.y;
		while (j < triangle_area.end.y)
		{
			pixel.vec[0] = i;
			pixel.vec[1] = j;
			if (inside_screen_triangle(triangle, i, j) == true)
			{
				pixel.vec[2] = (triangle->screen_A.vec[2] + triangle->screen_B.vec[2] + triangle->screen_C.vec[2]) / 3;
				big_color_in(pixel, triangle->A.color, display);
			}
			j += 2;
		}
		i += 2;
	}

	t_vector_4f *top;
	t_vector_4f *middle;
	t_vector_4f *bottom;

	top = top_vertex(triangle);
	bottom = bottom_vertex(triangle);
	middle = middle_vertex(triangle, top, bottom);

	// printf("TOP: \n");
	// vector4f_print(top);
	// printf("MIDDLE: \n");
	// vector4f_print(middle);
	// vector4f_print(bottom);

	// double	start;
	// double	start_delta;

	// double	end;
	// double	end_delta;

	// int		iter;
	// int		iter_delta;

	// i = top->vec[1];
	// end = top->vec[0];
	// start = top->vec[0];

	// start_delta = (middle->vec[0] - top->vec[0]) / (top->vec[1] - middle->vec[1]);
	// if (-.05 < top->vec[1] - middle->vec[1] && top->vec[1] - middle->vec[1] < .05)
	// 	start_delta = 0;

	// end_delta = (bottom->vec[0] - top->vec[0]) / (top->vec[1] - bottom->vec[1]);
	// if (-.05 < top->vec[1] - bottom->vec[1] && top->vec[1] - bottom->vec[1] < .05)
	// 	end_delta = 0;

	// // printf("BOTTOM: %f with %f\n", end_delta, top->vec[1] - middle->vec[1]);
	// while (i > (int)(middle->vec[1]))
	// {
	// 	iter = (int)start;

	// 	if (start < end)
	// 		iter_delta = PIXEL_SIZE;
	// 	else
	// 		iter_delta = -PIXEL_SIZE;

	// 	// printf("%d and %d and %d\n", iter, (int)end, iter_delta);
	// 	while (abs(iter - (int)end) > PIXEL_SIZE)
	// 	{
	// 		pixel.vec[0] = iter;
	// 		pixel.vec[1] = i;
	// 		pixel.vec[2] = 13;
	// 		big_color_in(pixel, 0x0000FF, display);
	// 		iter += iter_delta;
	// 	}
	// 	start += start_delta * PIXEL_SIZE;
	// 	end += end_delta * PIXEL_SIZE;
	// 	i -= PIXEL_SIZE;
	// }
}
