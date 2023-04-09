/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   its_ch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:55:31 by user              #+#    #+#             */
/*   Updated: 2023/04/09 23:12:57 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../miniRT.h"

double	d_coeffi(t_vecinf *eye2scr, t_vecinf *eye2ballmid, double r)
{
	double coefficient_A;
	double coefficient_B;
	double coefficient_C;

	coefficient_A = pow(eye2scr->size, 2);
	coefficient_B = 2 * (dot_vec(&eye2scr->vec, &eye2ballmid->vec));
	coefficient_C = pow(eye2ballmid->size, 2) - pow(r, 2);
	return (pow(coefficient_B, 2) - 4 * coefficient_A * coefficient_C);
}

double    ray2ball_itsch(t_vecinf *eye2scr, t_allinfs *infs, t_ball *ball)
{
    t_vecinf	eye2ballmid;

	neg_vec(&eye2ballmid, &ball->center_v->vec, &infs->fix_vecs->eye_v->vec);
	if (d_coeffi(eye2scr, &eye2ballmid, ball->rad) >= 0)
	{
		printf("ch\n");
		return 1;
	}
	return 0;
}
