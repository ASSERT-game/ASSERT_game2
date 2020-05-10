/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 21:00:54 by home              #+#    #+#             */
/*   Updated: 2020/05/10 00:14:40 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

int	main(void)
{
	int i;
	t_display	display;

	SDLG_setup(&display);

	i = 0;
	while (i < 1000 * 500 * 4)
	{
		display.pixels[i] = 150;
		i++;
	}

	i = 100;
	while (i < 200)
	{
		display.pixels[1000 * 100 * 4 + i * 4 + 0] = 250;
		display.pixels[1000 * 100 * 4 + i * 4 + 1] = 0;
		display.pixels[1000 * 100 * 4 + i * 4 + 2] = 0;

		display.pixels[1000 * 200 * 4 + i * 4 + 0] = 250;
		display.pixels[1000 * 200 * 4 + i * 4 + 1] = 0;
		display.pixels[1000 * 200 * 4 + i * 4 + 2] = 0;

		display.pixels[1000 * 300 * 4 + i * 4 + 0] = 250;
		display.pixels[1000 * 300 * 4 + i * 4 + 1] = 0;
		display.pixels[1000 * 300 * 4 + i * 4 + 2] = 0;
		i++;
	}
	SDL_UpdateWindowSurface(display.window);

	poll_and_toolbar();

	return (0);
}
