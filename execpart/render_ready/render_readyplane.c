/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_readyplane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:28:24 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/15 23:18:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

double	calc_Rsplane(double n_l, t_vecinf *its2lgt, t_plane *plane, t_vecinf *eye2its)
{
	t_vecinf	reverse;
	t_vecinf	rev_eye;
	double		v_r;

	t_mix_vec_all(&reverse, 2 * n_l, &plane->n->vec, -1, &(its2lgt->u_vec));
	set_vec(&rev_eye, -1 * eye2its->vec.x, -1 * eye2its->vec.y, -1 * eye2its->vec.z);
	v_r = map(dot_vec(&reverse.vec, &rev_eye.vec), -1, 1, 0, 1);
	return (plane->t_refCoeff.ks * plane->t_refCoeff.ks * pow(v_r, plane->t_refCoeff.alpha));
}

double i = 0;

static	void	upgrade_t(double *t, double tmp_t, ssize_t *position_r, ssize_t position, bool *f_action)
{
	*t = tmp_t;
	*position_r = position;
	*f_action = false;
}

ssize_t	judge_showditem_2(t_objarr *objarr, t_vecinf *eye2scr, t_allinfs *infs)
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

bool	shade_ch(t_objarr *objarr, t_vecinf *its, t_vecinf *its2lgt, t_allinfs *infs, t_lgtarr *lgtarr)
{
	double		epsiron;
	t_vecinf	itsep;
	t_vecinf	itsep2lgt;

	epsiron = 1 / 512;
	t_mix_vec(&itsep, &its->vec, epsiron, &its2lgt->u_vec);
	neg_vec(&itsep2lgt, &lgtarr->lgt_v.vec, &itsep.vec);
	if (judge_showditem_2(objarr, &itsep2lgt, infs) != -1)
		return (false);
	return (true);
}

double j = 0;
double k = 0;

double	calc_lgtplane(t_allinfs *infs, t_plane *plane, t_vecinf *planeits)
{
	double		n_l;
	double		R_all;
	t_vecinf	its2lgt;
	t_vecinf	eye2its;
	t_lgtarr	*lgtarr;
	t_objarr	*objarr;

	lgtarr = infs->fix_vecs->lgtarr;
	n_l = 0;
	R_all = 0;
	neg_vec(&eye2its, &planeits->vec, &infs->fix_vecs->eye_v->vec);
	while (lgtarr != NULL)
	{
		objarr = infs->fix_vecs->objarr;
		neg_vec(&its2lgt, &lgtarr->lgt_v.vec, &planeits->vec);
		if (shade_ch(objarr, planeits, &its2lgt, infs, lgtarr) == true)
		{
			n_l = map(dot_vec(&plane->n->u_vec, &its2lgt.u_vec), -1, 1, 0, 1);
			R_all = R_all + calc_Rsplane(n_l, &its2lgt, plane, &eye2its);
			R_all = R_all + plane->t_refCoeff.kd * plane->t_refCoeff.Ii * n_l;
			R_all = R_all + plane->t_refCoeff.ka * plane->t_refCoeff.Ia;
		}
		lgtarr = lgtarr->next_lgt;
	}
	return (R_all);
}

double	reanderready_plane(t_vecinf *eye2scr, t_allinfs *infs, t_objarr *objarr)
{
	double		t;
	t_vecinf	planeits;

	t = ray2plane_itsch(eye2scr, infs, objarr->plane);
	if (t > 0)
	{
		t_mix_vec(&planeits, &infs->fix_vecs->eye_v->vec, t, &eye2scr->vec);
		return calc_lgtplane(infs, objarr->plane, &planeits);
	}
	return (0);
}