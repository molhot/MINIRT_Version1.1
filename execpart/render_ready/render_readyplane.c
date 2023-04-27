/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_readyplane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:28:24 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/24 21:57:57 by mochitteiun      ###   ########.fr       */
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

bool	judge_showditem_2(t_objarr *objarr, t_vecinf *itsep2lgt, t_allinfs *infs, t_vecinf *its)
{
	while (objarr != NULL)
	{
		if (obtain_shapetype(objarr) == BALL)
		{
			if (itsray2otherball_itsch(itsep2lgt, objarr->ball, its) > 0)
				return (false);
		}
		else if (obtain_shapetype(objarr) == PLANE)
		{
			if (ray2plane_itsch(itsep2lgt, infs, objarr->plane) > 0)
				return (false);
		}
		objarr = objarr->next_obj;
	}
	return (true);
}

bool	shade_ch(t_objarr *objarr, t_vecinf *its, t_vecinf *its2lgt, t_allinfs *infs, t_lgtarr *lgtarr)
{
	double		epsiron;
	t_vecinf	itsep;
	t_vecinf	itsep2lgt;

	epsiron = 1 / 512;
	t_mix_vec(&itsep, &its->vec, epsiron, &its2lgt->vec);
	neg_vec(&itsep2lgt, &lgtarr->lgt_v.vec, &itsep.vec);
	return (judge_showditem_2(objarr, &itsep2lgt, infs, its));
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
	R_all = R_all + plane->t_refCoeff.ka * plane->t_refCoeff.Ia;
	while (lgtarr != NULL)
	{
		objarr = infs->fix_vecs->objarr;
		neg_vec(&its2lgt, &lgtarr->lgt_v.vec, &planeits->vec);
		if (shade_ch(objarr, planeits, &its2lgt, infs, lgtarr) == true)
		{
			n_l = map(dot_vec(&plane->n->u_vec, &its2lgt.u_vec), -1, 1, 0, 1);
			if (n_l != 0)
			{
				R_all = R_all + calc_Rsplane(n_l, &its2lgt, plane, &eye2its);
				R_all = R_all + plane->t_refCoeff.kd * plane->t_refCoeff.Ii * n_l;
			}
			
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
		//printf("%f\n", t);
		t_mix_vec(&planeits, &infs->fix_vecs->eye_v->vec, t, &eye2scr->vec);
		return calc_lgtplane(infs, objarr->plane, &planeits);
	}
	return (0);
}