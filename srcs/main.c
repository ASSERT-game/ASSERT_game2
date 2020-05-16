/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 21:00:54 by home              #+#    #+#             */
/*   Updated: 2020/05/16 00:31:05 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

int	main(void)
{
	t_display	display;

	SDLG_setup(&display);
	apply_background(display.pixels, display.background, display.width * display.height);

	t_vector_4i	test;

	test.vec[0] = 100;
	test.vec[1] = 100;

	draw_point(test, &display);

	test.vec[0] += 100;
	draw_point(test, &display);

	test.vec[1] += 300;
	draw_point(test, &display);

	refresh_display(&display);

	poll_and_toolbar();

	return (0);
}
