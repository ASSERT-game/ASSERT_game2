/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 00:18:48 by home              #+#    #+#             */
/*   Updated: 2020/05/08 20:17:08 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

void	rect_fill(t_rect *dest, t_point *start, t_point *end)
{
	dest->start.x = start->x;
	dest->start.y = start->y;

	dest->end.x = end->x;
	dest->end.y = end->y;

	dest->width = ((dest->end).x) - ((dest->start).x);
	dest->height = ((dest->end).y) - ((dest->start).y);
}

void	rect_update(t_rect *self, void *change)
{
	void	*diff;
	t_rect	anchor;
	void	*change_type;

	diff = change - (int)self;
	change_type = &anchor + (int)diff;

	if (change_type == &anchor.end || change_type == &anchor.start)
	{
		self->width = ((self->end).x) - ((self->start).x);
		self->height = ((self->end).y) - ((self->start).y);
	}
	else if (change_type == &anchor.height || change_type == &anchor.width)
	{
		self->end.x = self->start.x + self->width;
		self->end.y = self->start.y +  self->height;
	}
}

void	rect_print(t_rect *rect)
{
	printf("Rect: (%d, %d) + (%d, %d) = (%d, %d)\n",
				rect->start.x, rect->start.y,
				rect->width, rect->height,
				rect->end.x, rect->end.y);
}
