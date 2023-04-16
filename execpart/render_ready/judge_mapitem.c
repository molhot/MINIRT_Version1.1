/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge_mapitem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:57:41 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/16 13:26:30 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

static	void	upgrade_t(double *t, double tmp_t, ssize_t *position_r, ssize_t position, bool *f_action)
{
	*t = tmp_t;
	*position_r = position;
	*f_action = false;
}

ssize_t	judge_showditem(t_objarr *objarr, t_vecinf *eye2scr, t_allinfs *infs)
{
	double	tmp_t;
	double	t;
	bool	f_action;
	ssize_t	position;
	ssize_t	position_r;

	f_action = true;
	position = 0;
	t = 0;
	while (objarr != NULL)
	{
		if (obtain_shapetype(objarr) == BALL)
			tmp_t = ray2ball_itsch(eye2scr, infs, objarr->ball);
		else if (obtain_shapetype(objarr) == PLANE)
			tmp_t = ray2plane_itsch(eye2scr, infs, objarr->plane);
		if (f_action == true && tmp_t > 0)
			upgrade_t(&t, tmp_t, &position_r, position, &f_action);
		else
		{
			if (t > tmp_t && tmp_t > 0)
				upgrade_t(&t, tmp_t, &position_r, position, &f_action);
		}
		objarr = objarr->next_obj;
		position++;
	}
	if (f_action == true)
		return (-1);
	else
		return (position_r);
}
