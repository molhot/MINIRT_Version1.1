/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:23:52 by user              #+#    #+#             */
/*   Updated: 2023/04/08 14:46:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void    constructer(t_allinfs *infs)
{
    infs->drawinf = malloc(sizeof(t_drawinf) * 1);
    ready_drawinf(infs->drawinf);
    infs->fix_vecs = malloc(sizeof(t_fvec) * 1);
    ready_vectors(infs->fix_vecs);
}