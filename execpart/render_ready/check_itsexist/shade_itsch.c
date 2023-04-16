/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_itsch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:28:24 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/16 14:56:41 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../miniRT.h"

static double	d_coeffi_shade(t_vecinf *itsep2lgt, t_vecinf *ballmid2eye, double r)
{
	double coefficient_A;
	double coefficient_B;
	double coefficient_C;

	coefficient_A = pow(itsep2lgt->size, 2);
	coefficient_B = 2 * (dot_vec(&ballmid2eye->vec, &itsep2lgt->vec));
	coefficient_C = pow(ballmid2eye->size, 2) - pow(r, 2);
	return (pow(coefficient_B, 2) - 4 * coefficient_A * coefficient_C);
}

double    itsray2otherball_itsch(t_vecinf *itsep2lgt, t_ball *ball, t_vecinf *its)
{
    t_vecinf	ballmid2its;

	neg_vec(&ballmid2its, &its->vec, &ball->center_v->vec);
	if (d_coeffi_shade(itsep2lgt, &ballmid2its, ball->rad) >= 0)
		return (1);
	return (-1);
}