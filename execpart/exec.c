/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:56:45 by user              #+#    #+#             */
/*   Updated: 2023/04/09 14:18:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static	void	dim2tdim(t_vecinf *dim_vec, double x, double y, double width, double height)
{
	double	tdim_x;
	double	tdim_y;

	tdim_x = (2 * x / (width - 1)) - 1;
	tdim_y = (-2 * y / (height - 1)) + 1;
	setvec_d(dim_vec, tdim_x, tdim_y, 0);
}

void    exec(t_allinfs *infs, double x, double y)
{
    while (y != infs->drawinf->height)
	{
		while (x != infs->drawinf->width)
		{
			dim2tdim(infs->fix_vecs->scr_v, x, y, infs->drawinf->width, infs->drawinf->height);
			draw_fadecolor(1, infs, (double)x, (double)y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(infs->drawinf->mlx, infs->drawinf->mlx_win, infs->drawinf->img, 0, 0);
	mlx_loop(infs->drawinf->mlx);
}