/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_eyevector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:43:41 by user              #+#    #+#             */
/*   Updated: 2023/04/09 22:33:55 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../miniRT.h"

void    ready_o2eyeVec(t_fvec *fvecs)
{
	fvecs->eye_v = malloc(sizeof(t_vecinf) * 1);
	set_vec(fvecs->eye_v, 0, 0, -5);
}