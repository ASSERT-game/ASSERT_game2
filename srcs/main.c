/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 21:00:54 by home              #+#    #+#             */
/*   Updated: 2020/05/15 23:04:42 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

int	main(void)
{
	t_display	display;

	SDLG_setup(&display);
	apply_background(display.pixels, display.background, display.width * display.height);

	t_point	test;

	test.x = 100;
	test.y = 100;

	draw_point(test, &display);

	test.x += 100;
	draw_point(test, &display);

	test.y += 300;
	draw_point(test, &display);

	refresh_display(&display);

	poll_and_toolbar();

	return (0);
}
