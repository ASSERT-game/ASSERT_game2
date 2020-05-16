/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 01:59:06 by home              #+#    #+#             */
/*   Updated: 2020/05/16 02:11:21 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	init_camera(t_camera *dest)
{
	bzero(&dest->proj.matrix, sizeof(dest->proj.matrix));

	dest->proj.matrix[0][0] = -1;
	dest->proj.matrix[1][1] = 1;
	dest->proj.matrix[2][2] = 1;
	dest->proj.matrix[3][3] = 1;
}
