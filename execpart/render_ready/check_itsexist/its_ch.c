/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   its_ch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:55:31 by user              #+#    #+#             */
/*   Updated: 2023/04/15 11:04:28 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../miniRT.h"

double	d_coeffi(t_vecinf *eye2scr, t_vecinf *ballmid2eye, double r)
{
	double coefficient_A;
	double coefficient_B;
	double coefficient_C;

	coefficient_A = pow(eye2scr->size, 2);
	coefficient_B = 2 * (dot_vec(&ballmid2eye->vec, &eye2scr->vec));
	coefficient_C = pow(ballmid2eye->size, 2) - pow(r, 2);
	return (pow(coefficient_B, 2) - 4 * coefficient_A * coefficient_C);
}

double    ray2ball_itsch(t_vecinf *eye2scr, t_allinfs *infs, t_ball *ball)
{
    t_vecinf	ballmid2eye;

	neg_vec(&ballmid2eye, &infs->fix_vecs->eye_v->vec, &ball->center_v->vec);
	if (d_coeffi(eye2scr, &ballmid2eye, ball->rad) >= 0)
	{
		return (ray2ballits(eye2scr, &ballmid2eye, ball->rad));
	}
	return (0);
}
