/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 00:29:21 by home              #+#    #+#             */
/*   Updated: 2020/05/26 00:55:19 by home             ###   ########.fr       */
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
