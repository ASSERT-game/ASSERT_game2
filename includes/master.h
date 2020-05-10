/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:55:52 by home              #+#    #+#             */
/*   Updated: 2020/05/10 00:14:07 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

#include <stdbool.h>

# include "debug.h"
# include "graphics_structs.h"
# include "ft_math.h"
# include "window_config.h"

# define SUCCESS 1
# define FAILURE 0

int		SDLG_setup(t_display *dest);

void	poll_and_toolbar(void);

#endif
