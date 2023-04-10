/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ready.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:06:43 by user              #+#    #+#             */
/*   Updated: 2023/04/10 10:53:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

//鏡面反射の計算でこれを繰り返し呼ぶ予定だがあっている自信はない
double	render_ready(t_vecinf *eye2scr, t_allinfs *infs)
{
	t_objarr	*objarr;

	//check用
	double		check;
	//

	objarr = infs->fix_vecs->objarr;
	check = 0;
	while (objarr != NULL)
	{
		if (obtain_shapetype(objarr) == BALL)
			check = ray2ball_itsch(eye2scr, infs, objarr->ball);
		objarr = objarr->next_obj;
	}
	return (check);
}
