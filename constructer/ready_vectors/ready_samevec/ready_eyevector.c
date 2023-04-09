/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_eyevector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:43:41 by user              #+#    #+#             */
/*   Updated: 2023/04/09 17:58:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../miniRT.h"

void    ready_o2eyeVec(t_fvec *fvecs)
{
    t_vecinf    *eye_v;

    eye_v = fvecs->eye_v;
    eye_v = malloc(sizeof(t_vecinf) * 1);
    set_vec(eye_v, 0, 0, -5);
}