/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_itsvect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:40:32 by user              #+#    #+#             */
/*   Updated: 2023/04/10 12:01:16 by user             ###   ########.fr       */
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
	//printf("%f, %f\n", one_ans, sec_ans);
	if (one_ans < 0 && sec_ans < 0)
		return (-1);
	if (one_ans < 0 && sec_ans > 0)
		return (sec_ans);
	else if (one_ans > 0 && sec_ans < 0)
		return (one_ans);
	if (one_ans > sec_ans)
		return (sec_ans);
	return (one_ans);
}

double    ray2ballits(t_vecinf *eye2scr, t_vecinf *eye2ballmid, double rad)
{
    double coefficient_A;
	double coefficient_B;
	double coefficient_D;

	coefficient_A = pow(eye2scr->size, 2);
	coefficient_B = 2 * (dot_vec(&eye2scr->vec, &eye2ballmid->vec));
	coefficient_D = d_coeffi(eye2scr, eye2ballmid, rad);
	return (formula_forsolution(coefficient_A, coefficient_B, coefficient_D));
}