/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 00:29:21 by home              #+#    #+#             */
/*   Updated: 2021/02/11 17:32:39 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	fill_cube(t_vector_4f *dest, int size)
{
	int	row;
	int	col;

	int	delta;
	int	edge;
	int	face;

	edge = size - 1;
	face = edge * edge;
	delta = 200 / (size);
	row = 0;
	while (row <= size - 2)
	{
		col = 0;
		while (col <= size - 2)
		{
			dest[0 * (face) + (edge) * row + col].color = 0xFF0000;
			dest[1 * (face) + (edge) * row + col].color = 0x550000;
			dest[2 * (face) + (edge) * row + col].color = 0x00FF00;
			dest[3 * (face) + (edge) * row + col].color = 0x005500;
			dest[4 * (face) + (edge) * row + col].color = 0x0000FF;
			dest[5 * (face) + (edge) * row + col].color = 0x000055;

			dest[0 * (face) + (edge) * row + col].vec[0] = -100 + delta + col * delta;
			dest[1 * (face) + (edge) * row + col].vec[0] = -100 + delta + col * delta;
			dest[2 * (face) + (edge) * row + col].vec[0] = -100;
			dest[3 * (face) + (edge) * row + col].vec[0] = 100;
			dest[4 * (face) + (edge) * row + col].vec[0] = -100 + delta + col * delta;
			dest[5 * (face) + (edge) * row + col].vec[0] = -100 + delta + col * delta;

			dest[0 * (face) + (edge) * row + col].vec[1] = 0 + delta + row * delta;
			dest[1 * (face) + (edge) * row + col].vec[1] = 0 + delta + row * delta;
			dest[2 * (face) + (edge) * row + col].vec[1] = 0 + delta + col * delta;
			dest[3 * (face) + (edge) * row + col].vec[1] = 0 + delta + col * delta;
			dest[4 * (face) + (edge) * row + col].vec[1] = 200;
			dest[5 * (face) + (edge) * row + col].vec[1] = 0;

			dest[0 * (face) + (edge) * row + col].vec[2] = 130 + 0;
			dest[1 * (face) + (edge) * row + col].vec[2] = 130 + 200;
			dest[2 * (face) + (edge) * row + col].vec[2] = 130 + delta + row * delta;
			dest[3 * (face) + (edge) * row + col].vec[2] = 130 + delta + row * delta;
			dest[4 * (face) + (edge) * row + col].vec[2] = 130 + delta + row * delta;
			dest[5 * (face) + (edge) * row + col].vec[2] = 130 + delta + row * delta;

			dest[0 * (face) + (edge) * row + col].vec[3] = 1;
			dest[1 * (face) + (edge) * row + col].vec[3] = 1;
			dest[2 * (face) + (edge) * row + col].vec[3] = 1;
			dest[3 * (face) + (edge) * row + col].vec[3] = 1;
			dest[4 * (face) + (edge) * row + col].vec[3] = 1;
			dest[5 * (face) + (edge) * row + col].vec[3] = 1;

			col++;
		}
		row++;
	}
}

void	draw_cube(t_camera *camera, t_display *display, t_vector_4f *cube, int size)
{
	int	i;

	i = 0;
	while (i < ((size - 1) * (size - 1)) * 6)
	{
		display_point(cube[i], camera, display);
		i++;
	}
}

void	fill_render_primitive(t_render_primitive *dest,
	t_vector_4f A, t_vector_4f B, t_vector_4f C)
{
	dest->A = A;
	dest->B = B;
	dest->C = C;

	dest->screen_A.color = dest->A.color;
	dest->screen_B.color = dest->B.color;
	dest->screen_C.color = dest->C.color;

	vector4f_fill(&dest->uv_A, 0, 1, 0);
	vector4f_fill(&dest->uv_B, 0, 0, 0);
	vector4f_fill(&dest->uv_C, 1, 0, 0);
}

t_render_primitive	*cube_mesh(t_vector_4f *pos)
{
	t_render_primitive	*mesh;

	mesh = malloc(sizeof(*mesh) * (6 * 2));

	t_vector_4f	v1;
	t_vector_4f	v2;
	t_vector_4f	v3;
	t_vector_4f	v4;
	t_vector_4f	v5;
	t_vector_4f	v6;
	t_vector_4f	v7;
	t_vector_4f	v8;

	vector4f_fill_c(&v1, -100 + 300, 200 + 50, -100 + 450, 0x048ed9);
	vector4f_fill_c(&v2, -100 + 300, 200 + 50,  100 + 450, 0xd40647);
	vector4f_fill_c(&v3,  100 + 300, 200 + 50, -100 + 450, 0x0bd604);
	vector4f_fill_c(&v4,  100 + 300, 200 + 50,  100 + 450, 0xd90ba2);
	vector4f_fill_c(&v5, -100 + 300,   0 + 50, -100 + 450, 0x6d0bde);
	vector4f_fill_c(&v6, -100 + 300,   0 + 50,  100 + 450, 0xd90ba2);
	vector4f_fill_c(&v7,  100 + 300,   0 + 50, -100 + 450, 0x6d0bde);
	vector4f_fill_c(&v8,  100 + 300,   0 + 50,  100 + 450, 0xd90ba2);

	fill_render_primitive(&mesh[0], v1, v2, v3);
	fill_render_primitive(&mesh[1], v2, v3, v4);

	fill_render_primitive(&mesh[2], v1, v2, v5);
	fill_render_primitive(&mesh[3], v2, v5, v6);

	fill_render_primitive(&mesh[4], v3, v4, v7);
	fill_render_primitive(&mesh[5], v4, v7, v8);

	fill_render_primitive(&mesh[6], v1, v3, v5);
	fill_render_primitive(&mesh[7], v3, v5, v7);

	fill_render_primitive(&mesh[8], v2, v4, v6);
	fill_render_primitive(&mesh[9], v4, v6, v8);

	fill_render_primitive(&mesh[10], v5, v6, v7);
	fill_render_primitive(&mesh[11], v6, v7, v8);
	(void)pos;

	return (mesh);
}
