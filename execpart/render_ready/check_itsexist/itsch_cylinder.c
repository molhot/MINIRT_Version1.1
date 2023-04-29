/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itsch_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:09:54 by user              #+#    #+#             */
/*   Updated: 2023/04/29 15:42:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../miniRT.h"

bool  ray2ball_cylinder(t_vecinf *eye2scr, t_allinfs *infs, t_cylinder *cylinder)
{
    double      discremental_a;
    double      discremental_b;
    double      discremental_c;
    t_vecinf    cylindermiddle2eye;
    t_vecinf    eye2scr_centern_outpro;
    t_vecinf    cylindermiddle2eye_centern_outpro;

    neg_vec(&cylindermiddle2eye, &infs->fix_vecs->eye_v->vec, &cylinder->center_v->vec);
    calc_outerproduct(&eye2scr_centern_outpro, &eye2scr->vec, &cylinder->center_n_v->vec);
    calc_outerproduct(&cylindermiddle2eye_centern_outpro, &cylindermiddle2eye.vec, &cylinder->center_n_v->vec);
    discremental_a = pow(eye2scr_centern_outpro.size, 2);
    discremental_b = 2 * (dot_vec(&eye2scr_centern_outpro.vec, &cylindermiddle2eye_centern_outpro.vec));
    discremental_c = pow(cylindermiddle2eye_centern_outpro.size, 2) - pow(cylinder->rad, 2);
    if (pow(discremental_b, 2) - 4 * discremental_a * discremental_c >= 0)
        return (true);
    else
        return (false);
}