/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ready.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:06:43 by user              #+#    #+#             */
/*   Updated: 2023/04/15 13:29:39 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

//鏡面反射の計算でこれを繰り返し呼ぶ予定だがあっている自信はない
void	render_ready(t_vecinf *eye2scr, t_allinfs *infs)
{
	t_objarr	*objarr;
	ssize_t		position;

	objarr = infs->fix_vecs->objarr;
	position = judge_showditem(objarr, eye2scr, infs);
	if (position != -1)
	{
		while (position != 0)
		{
			objarr = objarr->next_obj;
			position--;
		}
		if (obtain_shapetype(objarr) == BALL)
			render(infs, infs->drawinf->x, infs->drawinf->y, reanderready_ball(eye2scr, infs, objarr));
		else if (obtain_shapetype(objarr) == PLANE)
			render(infs, infs->drawinf->x, infs->drawinf->y, reanderready_plane(eye2scr, infs, objarr));
	}
	else
		render(infs, infs->drawinf->x, infs->drawinf->y, -1);
}
