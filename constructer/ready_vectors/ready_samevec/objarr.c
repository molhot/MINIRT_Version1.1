/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objarr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:25:53 by user              #+#    #+#             */
/*   Updated: 2023/04/11 23:04:20 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../miniRT.h"

static  void    refCoeff(t_refCoeff *refcoeff)
{
    refcoeff->ka = 1;
	refcoeff->kd = 2;
	refcoeff->ks = 3;
	refcoeff->alpha = 4;
	refcoeff->Ia = 5;
	refcoeff->Ii = 6;
	refcoeff->n_l = 7;
	refcoeff->v_r = 8;
	refcoeff->Rs = 9;
}

static  void    ready_plane(t_plane *plane)
{
    plane->n = malloc(sizeof(t_vecinf) * 1);
    set_vec(plane->n, 0, 1, 0);
    plane->point = malloc(sizeof(t_vecinf) * 1);
    set_vec(plane->point, 0, -1, 0);
    refCoeff(&plane->t_refCoeff);
    plane->has_specmir = false;
    plane->spec_mir = 0;
}

static  void    ready_ball(t_ball *ball)
{
    ball->center_v = malloc(sizeof(t_vecinf) * 1);
    set_vec(ball->center_v, 0, 0, 5);
    ball->rad = 1;
    refCoeff(&ball->t_refCoeff);
    ball->has_specmir = false;
    ball->spec_mir = 0;
}

void    ready_object(t_objarr *objarr, double type)
{
    if (type == BALL)
    {
        objarr->ball = malloc(sizeof(t_ball) * 1);
        ready_ball(objarr->ball);
        objarr->plane = NULL;
    }
    else if (type == PLANE)
    {
        objarr->plane = malloc(sizeof(t_plane) * 1);
        ready_plane(objarr->plane);
        objarr->ball = NULL;
    }
}

void    ready_objarr(t_fvec *fvecs)
{
	t_objarr	*tmp_obj;

	fvecs->objarr = malloc(sizeof(t_objarr) * 1);
	tmp_obj = fvecs->objarr;
	ready_object(tmp_obj, BALL);
	fvecs->objarr->next_obj = NULL;
}