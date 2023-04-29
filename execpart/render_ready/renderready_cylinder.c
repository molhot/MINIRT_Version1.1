/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderready_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:04:03 by user              #+#    #+#             */
/*   Updated: 2023/04/29 16:06:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

static double	formula_forsolution(double A, double B, double D)
{
	double	one_ans;
	double	sec_ans;

	if (D == 0)
		return ((-1 * B) / (2 * A));
	one_ans = ((-1 * B) + sqrt(D)) / (2 * A);
	sec_ans = ((-1 * B) - sqrt(D)) / (2 * A);
	if (one_ans < 0 && sec_ans < 0)
		return (0);
	if (one_ans < 0 && sec_ans > 0)
		return (sec_ans);
	else if (one_ans > 0 && sec_ans < 0)
		return (one_ans);
	if (one_ans > sec_ans)
		return (sec_ans);
	return (one_ans);
}

double  ray2ball_its_ratio(t_vecinf *eye2scr, t_allinfs *infs, t_cylinder *cylinder)
{
    double      discremental_a;
    double      discremental_b;
    double      discremental_c;
    double      discremental_d;
    t_vecinf    cylindermiddle2eye;
    t_vecinf    eye2scr_centern_outpro;
    t_vecinf    cylindermiddle2eye_centern_outpro;

    neg_vec(&cylindermiddle2eye, &infs->fix_vecs->eye_v->vec, &cylinder->center_v->vec);
    calc_outerproduct(&eye2scr_centern_outpro, &eye2scr->vec, &cylinder->center_n_v->vec);
    calc_outerproduct(&cylindermiddle2eye_centern_outpro, &cylindermiddle2eye.vec, &cylinder->center_n_v->vec);
    discremental_a = pow(eye2scr_centern_outpro.size, 2);
    discremental_b = 2 * (dot_vec(&eye2scr_centern_outpro.vec, &cylindermiddle2eye_centern_outpro.vec));
    discremental_c = pow(cylindermiddle2eye_centern_outpro.size, 2) - pow(cylinder->rad, 2);
    discremental_d = pow(discremental_b, 2) - 4 * discremental_a * discremental_c;
    return (formula_forsolution(discremental_a, discremental_b, discremental_d));
}

t_vecinf    *calc_its_nvec(t_vecinf *cylinderits_v, t_cylinder *cylinder)
{
    t_vecinf    middle2its;
    double      ratio;
    t_vecinf    *its_n_vec;

    its_n_vec = malloc(sizeof(t_vecinf) * 1);
    neg_vec(&middle2its, &cylinderits_v->vec, &cylinder->center_v->vec);
    ratio = dot_vec(&middle2its.vec, &cylinder->center_n_v->vec);
    t_neg_vec(its_n_vec, &middle2its.vec, ratio, &cylinder->center_n_v->vec);
    return (its_n_vec);
}

double  calc_lgtcylinder(t_allinfs *infs, t_vecinf *eye2scr, t_cylinder *cylinder, double t, t_vecinf *cylinderits_v)
{
    t_lgtarr    *lgtarr;
    t_vecinf    its2lgt;
    t_vecinf    *its_nvec;
    t_vecinf    reverse_lgtvec;
    t_vecinf    its2eye;
    double      R_all;
    double      n_l;
    double      r_v;

    lgtarr = infs->fix_vecs->lgtarr;
    (void)eye2scr;
    (void)t;
    R_all = 0;
    R_all = R_all + cylinder->t_refCoeff.ka * cylinder->t_refCoeff.Ia;
    its_nvec = calc_its_nvec(cylinderits_v, cylinder);
    if (cylinderits_v->vec.y < cylinder->center_v->vec.y)
        return (-1);
    if (cylinderits_v->vec.y > (cylinder->center_v->vec.y + cylinder->height))
        return (-1);
    while (lgtarr != NULL)
    {
        neg_vec(&its2lgt, &lgtarr->lgt_v.vec, &cylinderits_v->vec);
        n_l = dot_vec(&its_nvec->u_vec, &its2lgt.u_vec);
        if (n_l >= 0)
            R_all = R_all + cylinder->t_refCoeff.kd * cylinder->t_refCoeff.Ii * n_l;
        t_mix_vec_all(&reverse_lgtvec, 2 * n_l, &its_nvec->u_vec, -1, &its2lgt.u_vec);
        neg_vec(&its2eye, &infs->fix_vecs->eye_v->vec, &cylinderits_v->vec);
        r_v = dot_vec(&reverse_lgtvec.u_vec, &its2eye.u_vec);
        if (r_v >= 0)
            R_all = R_all + cylinder->t_refCoeff.ks * cylinder->t_refCoeff.Ii * pow(r_v, cylinder->t_refCoeff.alpha);
        lgtarr = lgtarr->next_lgt;
    }
    return (R_all);
}

double  renderready_cylinder(t_vecinf *eye2scr, t_allinfs *infs, t_cylinder *cylinder)
{
    double      t;
    t_vecinf    cylinderits;

    t = ray2ball_its_ratio(eye2scr, infs, cylinder);
    if (t < 0)
        return (-1);
    t_mix_vec(&cylinderits, &infs->fix_vecs->eye_v->vec, t, &eye2scr->vec);
    return (calc_lgtcylinder(infs, eye2scr, cylinder, t, &cylinderits));
}