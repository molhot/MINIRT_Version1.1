/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scal_vaccalc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:42:12 by user              #+#    #+#             */
/*   Updated: 2023/04/09 14:48:00 by user             ###   ########.fr       */
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
