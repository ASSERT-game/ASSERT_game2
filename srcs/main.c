/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 21:00:54 by home              #+#    #+#             */
/*   Updated: 2020/05/08 20:18:30 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	prints(void);

int	main(void)
{
	t_rect	rect;

	point_fill(&(rect.start), 0, 0);
	point_fill(&(rect.end), 100, 100);
	rect_print(&rect);
	rect_update(&rect, &(rect.start));
	rect_print(&rect);
	SDLG_setup();

	SDL_Delay(4000);

	return (0);
}
