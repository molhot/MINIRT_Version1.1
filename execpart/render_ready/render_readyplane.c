/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_readyplane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:28:24 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/15 16:57:44 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

// double	calc_Rsplane(t_vecinf *eye2scr, t_vecinf	*ballmid2lgt, t_vecinf *ballmid2ballits, t_refCoeff *refcoeff_inf, double n_l)
// {
// 	t_vecinf	reflect_vec;
// 	t_vecinf	rev_eye2scr;
// 	double		v_r;

// 	v_r = 0;
// 	t_mix_vec_all(&reflect_vec, 2 * n_l, &ballmid2ballits->u_vec, -1, &ballmid2lgt->u_vec);
// 	setvec_d(&rev_eye2scr, -1 * eye2scr->vec.x, -1 * eye2scr->vec.y, -1 * eye2scr->vec.z);
// 	v_r = map(dot_vec(&reflect_vec.vec, &rev_eye2scr.u_vec), -1, 1, 0, 1);
// 	if (v_r != 0)
// 		return (refcoeff_inf->ks * refcoeff_inf->Ii * pow(v_r, refcoeff_inf->alpha));
// 	return (0);
// }

bool	shade_ch(t_objarr *objarr, t_vecinf *its, t_vecinf *its2lgt, t_allinfs *infs)
{
	double		epsiron;
	t_lgtarr	*lgtarr;
	t_vecinf	itsep;
	t_vecinf	itsep2lgt;

	epsiron = 1 / 512;
	lgtarr = infs->fix_vecs->lgtarr;
	while (lgtarr != NULL)
	{
		t_mix_vec(&itsep, &its->vec, epsiron, &its2lgt->u_vec);
		neg_vec(&itsep2lgt, &lgtarr->lgt_v.vec, &itsep.vec);
		if (judge_showditem(objarr, &itsep2lgt, infs) != -1)
			return (false);
		lgtarr = lgtarr->next_lgt;
	}
	return (true);
}

double	calc_lgtplane(t_allinfs *infs, t_plane *plane, t_vecinf *planeits)
{
	double		n_l;
	//double		R_all;
	t_vecinf	its2lgt;
	t_lgtarr	*lgtarr;
	t_objarr	*objarr;

	lgtarr = infs->fix_vecs->lgtarr;
	objarr = infs->fix_vecs->objarr;
	n_l = 0;
	//R_all = 0;
	while (lgtarr != NULL)
	{
		neg_vec(&its2lgt, &lgtarr->lgt_v.vec, &planeits->vec);
		printf("%d\n", shade_ch(objarr, planeits, &its2lgt, infs));
		if (shade_ch(objarr, planeits, &its2lgt, infs) == false)
			n_l = n_l + 0;
		else
			n_l = n_l + map(dot_vec(&plane->n->u_vec, &its2lgt.u_vec), -1, 1, 0, 1);
		lgtarr = lgtarr->next_lgt;
	}
	return (n_l);
}

double	reanderready_plane(t_vecinf *eye2scr, t_allinfs *infs, t_objarr *objarr)
{
	double		t;
	t_vecinf	planeits;

	t = ray2plane_itsch(eye2scr, infs, objarr->plane);
	if (t > 0)
	{
		t_mix_vec(&planeits, &eye2scr->vec, t, &infs->fix_vecs->eye_v->vec);
		return calc_lgtplane(infs, objarr->plane, &planeits);
	}
	return (0);
}