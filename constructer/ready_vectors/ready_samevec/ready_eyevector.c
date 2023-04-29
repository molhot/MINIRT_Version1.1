/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_eyevector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:43:41 by user              #+#    #+#             */
/*   Updated: 2023/04/29 16:14:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../miniRT.h"

void    ready_o2eyeVec(t_fvec *fvecs)
{
	fvecs->eye_v = malloc(sizeof(t_vecinf) * 1);
	set_vec(fvecs->eye_v, 0.0, 0.0, -5.0);
}