/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:02:18 by user              #+#    #+#             */
/*   Updated: 2023/04/16 23:42:25 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

// void	render(t_allinfs *infs, double x, double y, double i)
// {
// 	if (i != -1)
// 	{
// 		draw_fadecolor(i, infs, (double)x, (double)y);
// 	}
// 	else
// 	{
// 		draw_fadecolor(1, infs, (double)x, (double)y);
// 	}
// }

void	draw_fadecolor(double i, t_allinfs *infs, int x, int y, t_objarr *objarr)
{
	if (obtain_shapetype(objarr) == BALL)
    	my_mlx_pixel_put(infs->drawinf, x, y, fade_color(i, 1));
	else
		my_mlx_pixel_put(infs->drawinf, x, y, fade_color(i, 2));
}

//
double  fade_color(double fade, int type)
{
    if (type == BALL)
        return ((int)(255 * fade) << 16) | ((int)(255 * fade) << 8) | (int)(255 * fade);
	else if (type == PLANE)
        return ((int)(0 * fade) << 16) | ((int)(255 * fade) << 8) | (int)(255 * fade);
    else
		return ((int)(130 << 16) | (int)(188 << 8) | (int)(20));
}

void	draw_background(t_allinfs *infs)
{
	double	back;

	back = (int)(130 << 16) | (int)(188 << 8) | (int)(20);
	my_mlx_pixel_put(infs->drawinf, infs->drawinf->x, infs->drawinf->y, back);
}

void	my_mlx_pixel_put(t_drawinf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
