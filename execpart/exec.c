/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:56:45 by user              #+#    #+#             */
/*   Updated: 2023/04/09 23:09:11 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static  void	dim2tdim(t_vecinf *dim_vec, double x, double y, double width, double height)
{
	double	tdim_x;
	double	tdim_y;
	double	tdim_z;

	tdim_x = (2 * x / (width - 1)) - 1;
	tdim_y = (-2 * y / (height - 1)) + 1;
	tdim_z = 0;
	setvec_d(dim_vec, tdim_x, tdim_y, tdim_z);
}

static void	render(t_allinfs *infs, double x, double y, double i)
{
	if (i == 1)
		my_mlx_pixel_put(infs->drawinf, x, y, ((int)(100) << 16) | ((int)(5) << 8) | (int)(255));
	else
		draw_fadecolor(1, infs, (double)x, (double)y);
}

void    exec(t_allinfs *infs)
{
	t_vecinf	eye2scr;
	int			x;
	int			y;

	x = 0;
	y = 0;
    while (y != infs->drawinf->height)
	{
		while (x != infs->drawinf->width)
		{
			dim2tdim(infs->fix_vecs->scr_v, x, y, (double)infs->drawinf->width, (double)infs->drawinf->height);
			//show_vec(infs->fix_vecs->scr_v);
			neg_vec(&eye2scr, &infs->fix_vecs->scr_v->vec, &infs->fix_vecs->eye_v->vec);
			render(infs, x, y, render_ready(&eye2scr, infs));
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(infs->drawinf->mlx, infs->drawinf->mlx_win, infs->drawinf->img, 0, 0);
	mlx_loop(infs->drawinf->mlx);
}