/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorArithmetic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:32:59 by user              #+#    #+#             */
/*   Updated: 2023/04/29 15:33:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

void    add_vec(t_vecinf *sub, t_vec *v1, t_vec *v2)
{
	setvec_d(sub, v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
}

void	neg_vec(t_vecinf *sub, t_vec *v1, t_vec *v2)
{
	setvec_d(sub, v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
}

double	dot_vec(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

void	calc_outerproduct(t_vecinf *sub, t_vec *v1, t_vec *v2)
{
	setvec_d(sub,
		v1->y * v2->z - v1->z * v2->y,
		v1->z * v2->x - v1->x * v2->z,
		v1->x * v2->y - v1->y * v2->x
	);
}