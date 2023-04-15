/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:56:45 by user              #+#    #+#             */
/*   Updated: 2023/04/15 23:14:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"
#include <unistd.h>

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
			infs->drawinf->x = x;
			infs->drawinf->y = y;
			// if ((x >= 250 && x <= 400) && ( y >= 380 && y <= 450))
			// {
			// 	printf("x %d, y %d\n", x, y);
				dim2tdim(infs->fix_vecs->scr_v, x, y, (double)infs->drawinf->width, (double)infs->drawinf->height);
				neg_vec(&eye2scr, &infs->fix_vecs->scr_v->vec, &infs->fix_vecs->eye_v->vec);
				render_ready(&eye2scr, infs);
			// }
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(infs->drawinf->mlx, infs->drawinf->mlx_win, infs->drawinf->img, 0, 0);
	mlx_loop(infs->drawinf->mlx);
}