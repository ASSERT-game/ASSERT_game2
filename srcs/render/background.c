/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 00:25:20 by home              #+#    #+#             */
/*   Updated: 2020/05/10 00:58:07 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

unsigned char *make_background(int color, int total_pixels)
{
	int				i;
	unsigned char	*background;

	i = 0;
	background = malloc(sizeof(*background) * (total_pixels * BPP));
	while (i < total_pixels)
	{
		background[i * 4 + 0] = color >> 0;
		background[i * 4 + 1] = color >> 8;
		background[i * 4 + 2] = color >> 16;
		i++;
	}
	(void)color;
	return (background);
}

void	apply_background(unsigned char *dest, unsigned char *source, int pixels)
{
	memcpy(dest, source, pixels * BPP);
}
