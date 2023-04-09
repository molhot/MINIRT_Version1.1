/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ready.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:06:43 by user              #+#    #+#             */
/*   Updated: 2023/04/09 15:48:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

void	render_ready(t_vecinf *eye2scr, t_allinfs *infs)
{
	t_objarr	*objarr;

	objarr = infs->fix_vecs->objarr;
	while (objarr != NULL)
	{
        if (obtain_shapetype(objarr) == BALL)
            break ;
        if (obtain_shapetype(objarr) == PLANE)
            break ;
		objarr = objarr->next_obj;
	}
	(void)eye2scr;
}
