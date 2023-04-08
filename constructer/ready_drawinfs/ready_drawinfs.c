/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_drawinfs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:25:35 by user              #+#    #+#             */
/*   Updated: 2023/04/08 14:38:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

void    ready_drawinf(t_allinfs *infs)
{
    t_drawinf   *draw_inf;
    
    infs->drawinf = malloc(sizeof(t_drawinf) * 1);
    draw_inf = infs->drawinf;
	draw_inf->width = 525;
	draw_inf->height = 525;
	draw_inf->mlx = mlx_init();
	draw_inf->mlx_win = mlx_new_window(draw_inf->mlx, draw_inf->width, draw_inf->height, "miniRT!");
	draw_inf->img = mlx_new_image(draw_inf->mlx, draw_inf->width, draw_inf->height);
	draw_inf->addr = mlx_get_data_addr(
		draw_inf->img, &draw_inf->bits_per_pixel, &draw_inf->line_length, &draw_inf->endian);
}