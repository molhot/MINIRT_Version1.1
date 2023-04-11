/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:02:18 by user              #+#    #+#             */
/*   Updated: 2023/04/11 23:48:42 by mochitteiun      ###   ########.fr       */
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
        return ((int)(178 * fade) << 16) | ((int)(100 * fade) << 8) | (int)(2 * fade);
    return ((int)(130 << 16) | (int)(188 << 8) | (int)(20));
}

void	my_mlx_pixel_put(t_drawinf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
