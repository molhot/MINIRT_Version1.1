/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:02:18 by user              #+#    #+#             */
/*   Updated: 2023/04/10 10:48:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

void	draw_fadecolor(double i, t_allinfs *infs, int x, int y, int type)
{
    my_mlx_pixel_put(infs->drawinf, x, y, fade_color(i, type));
}

//
double  fade_color(double fade, int type)
{
    if (type == BALL)
        return ((int)(255 * fade) << 16) | ((int)(5 * fade) << 8) | (int)(255 * fade);
    return ((int)(255 << 16) | (int)(255 << 8) | (int)(255));
}

void	my_mlx_pixel_put(t_drawinf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
