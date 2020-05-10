/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:55:52 by home              #+#    #+#             */
/*   Updated: 2020/05/10 00:49:52 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

# include <stdbool.h>
# include <string.h>

# include "debug.h"
# include "graphics_structs.h"
# include "ft_math.h"
# include "window_config.h"

# define SUCCESS 1
# define FAILURE 0

void			poll_and_toolbar(void);

int				SDLG_setup(t_display *dest);

void			refresh_display(t_display *display);
void			apply_background(unsigned char *dest, unsigned char *source, int pixels);
unsigned char	*make_background(int color, int total_pixels);

#endif
