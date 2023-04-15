/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itsch_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:12:44 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/15 15:19:23 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../miniRT.h"

double	ray2plane_itsch(t_vecinf *eye2scr, t_allinfs *infs, t_plane *plane)
{
	t_vecinf	plane2eye;
	double		s_n;
	double		d_n;

	neg_vec(&plane2eye, &infs->fix_vecs->eye_v->vec, &plane->point->vec);
	s_n = dot_vec(&plane2eye.vec, &plane->n->vec);
	d_n = dot_vec(&eye2scr->vec, &plane->n->vec);
	return ((-1 * s_n) / d_n);
}
