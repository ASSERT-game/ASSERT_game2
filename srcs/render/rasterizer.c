/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 01:13:41 by home              #+#    #+#             */
/*   Updated: 2020/05/26 01:30:51 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	rasterize_triangle(t_render_primative *triangle, t_camera *camera, t_display *display)
{
	display_point(triangle->A, camera, display);
	display_point(triangle->B, camera, display);
	display_point(triangle->C, camera, display);
}
