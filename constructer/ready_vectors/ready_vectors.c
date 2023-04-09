/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_vectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:47:09 by user              #+#    #+#             */
/*   Updated: 2023/04/09 14:07:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

void    ready_vectors(t_fvec *fvecs)
{
    ready_o2eyeVec(fvecs->eye_v);
    ready_lgtarr(fvecs->lgtarr);
    ready_objarr(fvecs->objarr);
    fvecs->scr_v = malloc(sizeof(t_vecinf) * 1);
}