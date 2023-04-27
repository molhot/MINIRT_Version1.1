/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_vectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:47:09 by user              #+#    #+#             */
/*   Updated: 2023/04/27 22:45:51 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

void    ready_vectors(t_fvec *fvecs)
{
    ready_o2eyeVec(fvecs);
    ready_lgtarr(fvecs);
    ready_objarr(fvecs);
}