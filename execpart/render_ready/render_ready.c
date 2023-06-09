/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ready.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:06:43 by user              #+#    #+#             */
/*   Updated: 2023/04/16 22:21:57 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

//鏡面反射の計算でこれを繰り返し呼ぶ予定だがあっている自信はない
//double	render_ready(t_vecinf *eye2scr, t_allinfs *infs)
ssize_t	grasp_position(t_vecinf *eye2scr, t_allinfs *infs)
{
	t_objarr	*objarr;
	ssize_t		position;

	objarr = infs->fix_vecs->objarr;
	position = judge_showditem(objarr, eye2scr, infs);
	return (position);
}
