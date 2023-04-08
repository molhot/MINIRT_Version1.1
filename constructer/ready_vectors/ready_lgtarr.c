/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_lgtarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:29:42 by user              #+#    #+#             */
/*   Updated: 2023/04/08 17:25:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

void    ready_lgtarr(t_lgtarr *lgtarr)
{
    t_lgtarr    *lgtinf;

    lgtarr = malloc(sizeof(t_lgtarr) * 1);
    lgtinf = lgtarr;
    // when i make readfile func, i refacta this func
    set_vec(&lgtinf->lgt_v, -5, 5, -5);
    lgtinf->next_lgt = NULL;
    //if you want increase light source, add func here
}