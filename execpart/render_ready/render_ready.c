/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ready.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:06:43 by user              #+#    #+#             */
/*   Updated: 2023/04/15 12:00:02 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

double	calc_Rs(t_vecinf *eye2scr, t_vecinf	*ballmid2lgt, t_vecinf *ballmid2ballits, t_refCoeff *refcoeff_inf, double n_l)
{
	t_vecinf	reflect_vec;
	t_vecinf	rev_eye2scr;
	double		v_r;

	v_r = 0;
	t_mix_vec_all(&reflect_vec, 2 * n_l, &ballmid2ballits->u_vec, -1, &ballmid2lgt->u_vec);
	setvec_d(&rev_eye2scr, -1 * eye2scr->vec.x, -1 * eye2scr->vec.y, -1 * eye2scr->vec.z);
	v_r = map(dot_vec(&reflect_vec.vec, &rev_eye2scr.u_vec), -1, 1, 0, 1);
	if (v_r != 0)
		return (refcoeff_inf->ks * refcoeff_inf->Ii * pow(v_r, refcoeff_inf->alpha));
	return (0);
}

double	calc_lgt(t_lgtarr *lgtarr, t_vecinf *eye2scr, t_ball *ball, t_vecinf *eye_v, double t)
{
	t_vecinf	ballits_v;
	t_vecinf	ballmid2ballits;
	t_vecinf	ballmid2lgt;
	double		n_l;
	double		R_all;

	n_l = 0;
	R_all = 0;
	t_mix_vec(&ballits_v, &eye_v->vec, t, &eye2scr->vec);
	neg_vec(&ballmid2ballits, &ballits_v.vec, &ball->center_v->vec);
	while (lgtarr != NULL)
	{
		neg_vec(&ballmid2lgt, &lgtarr->lgt_v.vec, &ball->center_v->vec);
		n_l = map(dot_vec(&ballmid2ballits.u_vec, &ballmid2lgt.u_vec), -1, 1, 0, 1);
		R_all = R_all + calc_Rs(eye2scr, &ballmid2lgt, &ballmid2ballits, &ball->t_refCoeff, n_l);
		R_all = R_all + ball->t_refCoeff.kd * ball->t_refCoeff.Ii * n_l;
		R_all = R_all + ball->t_refCoeff.ka * ball->t_refCoeff.Ia;
		lgtarr = lgtarr -> next_lgt;
	}
	return (R_all);
}

double	reanderready_ball(t_vecinf *eye2scr, t_allinfs *infs, t_objarr *objarr)
{
	double		t;

	t = ray2ball_itsch(eye2scr, infs, objarr->ball);
	if (t > 0)
		return calc_lgt(infs->fix_vecs->lgtarr, eye2scr, objarr->ball, infs->fix_vecs->eye_v, t);
	return (0);
}

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
	}
	else
		render(infs, infs->drawinf->x, infs->drawinf->y, -1);
}
