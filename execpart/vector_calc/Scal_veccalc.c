/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scal_veccalc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:42:12 by user              #+#    #+#             */
/*   Updated: 2023/04/12 08:59:10 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

void    t_mix_vec(t_vecinf *sub, t_vec *v1, double t, t_vec *v2)
{
    setvec_d(
        sub, \
        v1->x + t * v2->x, \
        v1->y + t * v2->y, \
        v1->z + t * v2->z
    );
}

void    t_neg_vec(t_vecinf *sub, t_vec *v1, double t, t_vec *v2)
{
    setvec_d(
        sub, \
        v1->x - t * v2->x, \
        v1->y - t * v2->y, \
        v1->z - t * v2->z
    );
}

void    t_mix_vec_all(t_vecinf *sub, double t1, t_vec *v1, double t2, t_vec *v2)
{
    setvec_d(
        sub, \
        t1 * v1->x + t2 * v2->x, \
        t1 * v1->y + t2 * v2->y, \
        t1 * v1->z + t2 * v2->z
    );
}
