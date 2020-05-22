/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_source.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 00:12:10 by home              #+#    #+#             */
/*   Updated: 2020/05/21 20:26:10 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	display_point(t_vector_4f spot, t_camera *camera, t_display *display);

void	fill_cube(t_vector_4f *dest)
{
	int	row;
	int	col;

	row = 0;
	while (row <= 8)
	{
		col = 0;
		while (col <= 8)
		{
			dest[0 * 81 + 9 * row + col].color = 0xFF0000;
			dest[1 * 81 + 9 * row + col].color = 0xAA0000;
			dest[2 * 81 + 9 * row + col].color = 0x00FF00;
			dest[3 * 81 + 9 * row + col].color = 0x00AA00;
			dest[4 * 81 + 9 * row + col].color = 0x0000FF;
			dest[5 * 81 + 9 * row + col].color = 0x0000AA;

			dest[0 * 81 + 9 * row + col].vec[0] = -80 + col * 20;
			dest[1 * 81 + 9 * row + col].vec[0] = -80 + col * 20;
			dest[2 * 81 + 9 * row + col].vec[0] = -100;
			dest[3 * 81 + 9 * row + col].vec[0] = 100;
			dest[4 * 81 + 9 * row + col].vec[0] = -80 + col * 20;
			dest[5 * 81 + 9 * row + col].vec[0] = -80 + col * 20;

			dest[0 * 81 + 9 * row + col].vec[1] = -80 + row * 20;
			dest[1 * 81 + 9 * row + col].vec[1] = -80 + row * 20;
			dest[2 * 81 + 9 * row + col].vec[1] = -80 + col * 20;
			dest[3 * 81 + 9 * row + col].vec[1] = -80 + col * 20;
			dest[4 * 81 + 9 * row + col].vec[1] = 100;
			dest[5 * 81 + 9 * row + col].vec[1] = -100;

			dest[0 * 81 + 9 * row + col].vec[2] = 30 + 0;
			dest[1 * 81 + 9 * row + col].vec[2] = 30 + 200;
			dest[2 * 81 + 9 * row + col].vec[2] = 30 + 20 + row * 20;
			dest[3 * 81 + 9 * row + col].vec[2] = 30 + 20 + row * 20;
			dest[4 * 81 + 9 * row + col].vec[2] = 30 + 20 + row * 20;
			dest[5 * 81 + 9 * row + col].vec[2] = 30 + 20 + row * 20;

			dest[0 * 81 + 9 * row + col].vec[3] = 1;
			dest[1 * 81 + 9 * row + col].vec[3] = 1;
			dest[2 * 81 + 9 * row + col].vec[3] = 1;
			dest[3 * 81 + 9 * row + col].vec[3] = 1;
			dest[4 * 81 + 9 * row + col].vec[3] = 1;
			dest[5 * 81 + 9 * row + col].vec[3] = 1;

			col++;
		}
		row++;
	}
}

void	poll_and_toolbar(t_display *display)
{
	int			i;
	t_camera	camera;

	t_vector_4f	*cube;
	t_vector_4f	vanishing;

	init_camera(&camera);
	vector4f_fill_c(&vanishing,  100,   0, 10000, 0xFFFFFF);
	cube = malloc(sizeof(*cube) * (81 * 6));
	fill_cube(cube);
	while(display->active == true)
	{
		update_state(display, &camera);
		i = 0;
		while (i < 81 * 6)
		{
			// vector4f_print(&cube[i]);
			display_point(cube[i], &camera, display);
			i++;
		}

		display_point(vanishing, &camera, display);
		refresh_display(display);
	}
}

void	display_point(t_vector_4f spot, t_camera *camera, t_display *display)
{
	int			roll;
	int			yaw;
	t_vector_4f	transform;

	if (camera->roll == 360)
		camera->roll = 0;
	if (camera->roll == -1)
		camera->roll = 359;

	if (camera->yaw == 360)
		camera->yaw = 0;
	if (camera->yaw == -1)
		camera->yaw = 359;

	yaw = camera->yaw;
	roll = camera->roll;

	camera->proj.matrix[0][0] = cosd(roll) * cosd(yaw);
	camera->proj.matrix[0][1] = sind(roll) * cosd(yaw);
	camera->proj.matrix[0][2] = sind(yaw);

	camera->proj.matrix[1][0] = -sind(roll);
	camera->proj.matrix[1][1] = cosd(roll);
	camera->proj.matrix[1][2] = 0;

	camera->proj.matrix[2][0] = -cosd(roll) * sind(yaw);
	camera->proj.matrix[2][1] = -sind(roll) * sind(yaw);
	camera->proj.matrix[2][2] = cosd(yaw);

	matrix_mult(camera->proj, spot, &transform);
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
