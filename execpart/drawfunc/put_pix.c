/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:02:18 by user              #+#    #+#             */
/*   Updated: 2023/04/09 13:51:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

void	draw_fadecolor(double i, t_allinfs *infs, int x, int y)
{
	if (i > 1)
    {
		i = 1;
    }
    if (i <= 0)
    {
        i = 0;
    }
	my_mlx_pixel_put(infs->drawinf, x, y, fade_color(i));
}

//
double  fade_color(double fade)
{
    return ((int)(255 * fade) << 16) | ((int)(5 * fade) << 8) | (int)(255 * fade);
}

void	my_mlx_pixel_put(t_drawinf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
