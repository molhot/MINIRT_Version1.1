/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:56:45 by user              #+#    #+#             */
/*   Updated: 2023/04/09 15:03:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static	void	render_ready(t_allinfs *infs, double x, double y)
{
	t_vecinf	eye2scr;
	t_objarr	*objarr;

	dim2tdim(infs->fix_vecs->scr_v, x, y, infs->drawinf->width, infs->drawinf->height);
	neg_vec(&eye2scr, &infs->fix_vecs->scr_v->vec, &infs->fix_vecs->eye_v->vec);
	objarr = infs->fix_vecs->objarr;
	while (objarr != NULL)
		objarr = objarr->next_obj;
	(void)eye2scr;
	(void)objarr;
}

static void	render(t_allinfs *infs, double x, double y)
{
	draw_fadecolor(1, infs, (double)x, (double)y);
}

void    exec(t_allinfs *infs, double x, double y)
{
    while (y != infs->drawinf->height)
	{
		while (x != infs->drawinf->width)
		{
			render_ready(infs, x, y);
			render(infs, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(infs->drawinf->mlx, infs->drawinf->mlx_win, infs->drawinf->img, 0, 0);
	mlx_loop(infs->drawinf->mlx);
}