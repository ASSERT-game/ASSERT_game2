/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 03:58:20 by home              #+#    #+#             */
/*   Updated: 2020/05/20 08:52:52 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

double	toRadians(int degree)
{
	double angle;

	angle = (degree * M_PI) / (180);
	return (angle);
}

double	sind(int degree)
{
	double radian;

	radian = toRadians(degree);
	return (sin(radian));
}

double	cosd(int degree)
{
	double radian;

	radian = toRadians(degree);
	return (cos(radian));
}
