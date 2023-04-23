/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:56:45 by user              #+#    #+#             */
/*   Updated: 2023/04/22 17:58:04 by user             ###   ########.fr       */
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

double draw_anyobj(ssize_t position, t_vecinf *eye2scr, t_allinfs *infs)
{
	t_objarr	*objarr;
	double		R_ALL;

	objarr = infs->fix_vecs->objarr;
	if (position == -1)
		return (-1);
	while (position != 0)
	{
		objarr = objarr->next_obj;
		position--;
	}
	R_ALL = 0;
	if (obtain_shapetype(objarr) == BALL)
		R_ALL = reanderready_ball(eye2scr, infs, objarr);
	else if (obtain_shapetype(objarr) == PLANE)
		R_ALL = reanderready_plane(eye2scr, infs, objarr);
	return (R_ALL);
}

void    exec(t_allinfs *infs)
{
	t_vecinf	eye2scr;
	ssize_t		position;
	t_objarr	*objarr;
	double		R_ALL;
	int			x;
	int			y;

	x = 0;
	y = 0;
    while (y != infs->drawinf->height)
	{
		while (x != infs->drawinf->width)
		{
			#ifdef TEST
			if ((x > 50 && y > 100) && )
			{
				infs->drawinf->x = x;
				infs->drawinf->y = y;
				dim2tdim(infs->fix_vecs->scr_v, x, y, (double)infs->drawinf->width, (double)infs->drawinf->height);
				neg_vec(&eye2scr, &infs->fix_vecs->scr_v->vec, &infs->fix_vecs->eye_v->vec);
				position = grasp_position(&eye2scr, infs);
				if (position == -1)
					draw_background(infs);
				else
				{
					R_ALL = draw_anyobj(position, &eye2scr, infs);
					if (R_ALL != -1)
					{
						objarr = infs->fix_vecs->objarr;
						while (position != 0)
						{
							objarr = objarr->next_obj;
							position--;
						}
						draw_fadecolor(R_ALL, infs, x, y, objarr);
					}
					else
						draw_background(infs);
				}
			}
			#endif
			#ifndef TEST
			infs->drawinf->x = x;
			infs->drawinf->y = y;
			dim2tdim(infs->fix_vecs->scr_v, x, y, (double)infs->drawinf->width, (double)infs->drawinf->height);
			neg_vec(&eye2scr, &infs->fix_vecs->scr_v->vec, &infs->fix_vecs->eye_v->vec);
			position = grasp_position(&eye2scr, infs);
			if (position == -1)
				draw_background(infs);
			else
			{
				R_ALL = draw_anyobj(position, &eye2scr, infs);
				if (R_ALL != -1)
				{
					objarr = infs->fix_vecs->objarr;
					while (position != 0)
					{
						objarr = objarr->next_obj;
						position--;
					}
					draw_fadecolor(R_ALL, infs, x, y, objarr);
				}
				else
					draw_background(infs);
			}
			#endif
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(infs->drawinf->mlx, infs->drawinf->mlx_win, infs->drawinf->img, 0, 0);
	mlx_loop(infs->drawinf->mlx);
}