/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_lgtarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:29:42 by user              #+#    #+#             */
/*   Updated: 2023/04/15 11:49:12 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../miniRT.h"

void    ready_lgtarr(t_fvec *fvecs)
{
    t_lgtarr    *lgtinf;

    fvecs->lgtarr = malloc(sizeof(t_lgtarr) * 1);
    lgtinf = fvecs->lgtarr;
    set_vec(&lgtinf->lgt_v, -5, 5, 0);
    lgtinf->next_lgt = NULL;
}