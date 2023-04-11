/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ready.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:06:43 by user              #+#    #+#             */
/*   Updated: 2023/04/11 08:28:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

double	something(t_lgtarr *lgtarr, t_vecinf *eye2scr, t_ball *ball, t_vecinf *eye_v, double t)
{
	t_vecinf	ballits_v;
	t_vecinf	ballmid2ballits;
	t_vecinf	ballmid2lgt;
	double		n_l;

	n_l = 0;
	while (lgtarr != NULL)
	{
		t_mix_vec(&ballits_v, &eye_v->vec, t, &eye2scr->vec);
		neg_vec(&ballmid2ballits, &ballits_v.vec, &ball->center_v->vec);
		neg_vec(&ballmid2lgt, &lgtarr->lgt_v.vec, &ball->center_v->vec);
		//if (3 < t && t < 4)
		//{
			//printf("%f\n", dot_vec(&ballmid2ballits.u_vec, &ballmid2lgt.u_vec));
			//show_vec(&ballmid2ballits);
			//show_vec(&ballmid2lgt);
		//}
		n_l = n_l + dot_vec(&ballmid2ballits.u_vec, &ballmid2lgt.u_vec);
	}
	return (n_l);
}

double	reanderready_ball(t_vecinf *eye2scr, t_allinfs *infs, t_objarr *objarr)
{
	double		t;
	double		n_l;

	n_l = 0;
	t = ray2ball_itsch(eye2scr, infs, objarr->ball);
	if (t > 0)
		n_l = something(infs->fix_vecs->lgtarr, eye2scr, objarr->ball, infs->fix_vecs->eye_v, t);
	return (map(n_l, -1, 1, 0, 1));
}

//鏡面反射の計算でこれを繰り返し呼ぶ予定だがあっている自信はない
double	render_ready(t_vecinf *eye2scr, t_allinfs *infs)
{
	t_objarr	*objarr;

	//check用
	double		n_l;
	//

	objarr = infs->fix_vecs->objarr;
	n_l = 0;
	while (objarr != NULL)
	{
		if (obtain_shapetype(objarr) == BALL)
			n_l = reanderready_ball(eye2scr, infs, objarr);
		objarr = objarr->next_obj;
	}
	return (n_l);
}
