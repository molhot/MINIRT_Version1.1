/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_readyball.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:26:01 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/24 22:20:07 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

// double    calc_lgtball(t_allinfs *infs, t_vecinf *eye2scr, t_ball *ball, t_vecinf *eye_v, double t)
// {
//     t_vecinf    ballits_v;
//     t_vecinf    ballmid2ballits;
//     t_vecinf    ballmid2lgt;
//     t_lgtarr    *lgtarr;
//     double        n_l;
//     double        R_all;
//     double        recursive;

//     n_l = 0;
//     R_all = 0;
//     t_mix_vec(&ballits_v, &eye_v->vec, t, &eye2scr->vec);
//     neg_vec(&ballmid2ballits, &ballits_v.vec, &ball->center_v->vec);

//     // 完全鏡面反射なら、視点を移動した先の輝度を使用
//     if (ball->has_specmir)
//     {
//         // show_vec(eye2scr);
//         recursive = recursive_ray(&ballits_v, infs, &ballmid2ballits);
//         if (recursive >= 0)
//         {
//             R_all = R_all + recursive;
//             nnnn = 0;
//         }
//         else
//         {
//             set_vec(infs->fix_vecs->eye_v, 0, 0, -5);
// //            nnnn = 0;
//             return (-1); // R_ALL = -1
//         }
//         set_vec(infs->fix_vecs->eye_v, 0, 0, -5);

//         return (R_all);
//     }

//     // 鏡面反射でなければ、R_all = R_ambient + R_diffuse + R_specular
//     //  R_ambientは環境光因なので計算は1度
//     R_all = R_all + ball->t_refCoeff.ka * ball->t_refCoeff.Ia; //まずambientを計算

//     //  R_diffuse, R_specularは光源依存のため、光源に応じて計算
//     lgtarr = infs->fix_vecs->lgtarr;

//     while (lgtarr != NULL)
//     {
//         neg_vec(&ballmid2lgt, &lgtarr->lgt_v.vec, &ball->center_v->vec);
//         n_l = map(dot_vec(&ballmid2ballits.u_vec, &ballmid2lgt.u_vec), -1, 1, 0, 1);
//         if (n_l != 0)
//         {
//             R_all = R_all + calc_Rsball(eye2scr, &ballmid2lgt, &ballmid2ballits, &ball->t_refCoeff, n_l);
//             R_all = R_all + ball->t_refCoeff.kd * ball->t_refCoeff.Ii * n_l;
// //            R_all = R_all + ball->t_refCoeff.ka * ball->t_refCoeff.Ia;
//         }
//         lgtarr = lgtarr -> next_lgt;
//     }
//     return (R_all);
// }

double	recursive_ray(t_vecinf *ballits_v, t_allinfs *infs, t_vecinf *its_n)
{
	t_vecinf	its2eye;
	t_vecinf	recursive_dis;
	double		v_n;
	double		epsiron;
	ssize_t		pos;

	epsiron = 1.0 / 512.0;
	neg_vec(&its2eye, &infs->fix_vecs->eye_v->vec, &ballits_v->vec);
	v_n = dot_vec(&its2eye.u_vec, &its_n->u_vec);
	if (v_n <= 0)
		return (-1);
	t_mix_vec_all(&recursive_dis, 2 * v_n, &its_n->u_vec, -1, &its2eye.u_vec);
	set_vec(
		infs->fix_vecs->eye_v
		, ballits_v->vec.x + epsiron * recursive_dis.vec.x
		, ballits_v->vec.y + epsiron * recursive_dis.vec.y
		, ballits_v->vec.z + epsiron * recursive_dis.vec.z
	);
	pos = grasp_position(&recursive_dis, infs);
	if (pos == -1)
		return (-1);
	else
	{
		double	fade;
		fade = draw_anyobj(pos, &recursive_dis, infs);
		return (fade);
	}
}

double	calc_Rsball(t_vecinf *eye2scr, t_vecinf	*ballmid2lgt, t_vecinf *ballmid2ballits, t_refCoeff *refcoeff_inf, double n_l)
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

double	calc_lgtball(t_allinfs *infs, t_vecinf *eye2scr, t_ball *ball, t_vecinf *eye_v, double t)
{
	t_vecinf	ballits_v;
	t_vecinf	ballmid2ballits;
	t_vecinf	ballmid2lgt;
	t_lgtarr	*lgtarr;
	double		n_l;
	double		R_all;
	double		recursive;

	n_l = 0;
	R_all = 0;
	lgtarr = infs->fix_vecs->lgtarr;
	t_mix_vec(&ballits_v, &eye_v->vec, t, &eye2scr->vec);
	neg_vec(&ballmid2ballits, &ballits_v.vec, &ball->center_v->vec);
	R_all = R_all + ball->t_refCoeff.ka * ball->t_refCoeff.Ia;
	while (lgtarr != NULL)
	{
		neg_vec(&ballmid2lgt, &lgtarr->lgt_v.vec, &ball->center_v->vec);
		n_l = map(dot_vec(&ballmid2ballits.u_vec, &ballmid2lgt.u_vec), -1, 1, 0, 1);
		if (n_l != 0)
		{
			if (ball->has_specmir == false)
			{
				R_all = R_all + ball->t_refCoeff.kd * ball->t_refCoeff.Ii * n_l;
				R_all = R_all + calc_Rsball(eye2scr, &ballmid2lgt, &ballmid2ballits, &ball->t_refCoeff, n_l);
			}
			else if (ball->has_specmir == true)
			{
				recursive = recursive_ray(&ballits_v, infs, &ballmid2ballits);
				set_vec(infs->fix_vecs->eye_v, 0, 0, -5);
				if (recursive >= 0)
					return (recursive);
				else
					return (-1);
			}
		}
		lgtarr = lgtarr -> next_lgt;
	}//各抗原に対して計算
	return (R_all);
}

double	reanderready_ball(t_vecinf *eye2scr, t_allinfs *infs, t_objarr *objarr)
{
	double		t;

	t = ray2ball_itsch(eye2scr, infs, objarr->ball);
	if (t > 0)
		return calc_lgtball(infs, eye2scr, objarr->ball, infs->fix_vecs->eye_v, t);
	return (-1);
}
