/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:23:52 by user              #+#    #+#             */
/*   Updated: 2023/04/27 22:45:30 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	constructer(t_allinfs *infs)
{
	infs->drawinf = malloc(sizeof(t_drawinf) * 1);
	ready_drawinf(infs->drawinf);
	infs->fix_vecs = malloc(sizeof(t_fvec) * 1);
	infs->fix_vecs->scr_v = malloc(sizeof(t_vecinf) * 1);
	ready_vectors(infs->fix_vecs);
}
