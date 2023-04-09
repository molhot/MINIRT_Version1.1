/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objarr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:25:53 by user              #+#    #+#             */
/*   Updated: 2023/04/09 14:57:18 by user             ###   ########.fr       */
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
    plane = malloc(sizeof(t_plane) * 1);
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
    ball = malloc(sizeof(t_ball) * 1);
    ball->center_v = malloc(sizeof(t_vecinf) * 1);
    set_vec(ball->center_v, 1, 0, -1);
    ball->rad = 1;
    refCoeff(&ball->t_refCoeff);
    ball->has_specmir = false;
    ball->spec_mir = 0;
}

void    ready_object(t_objarr *objarr, double type)
{
    if (type == BALL)
    {
        ready_ball(objarr->ball);
        objarr->plane = NULL;
    }
    else if (type == PLANE)
    {
        ready_plane(objarr->plane);
        objarr->ball = NULL;
    }
}

void    ready_objarr(t_objarr *objarr)
{
    objarr = malloc(sizeof(objarr) * 1);
    ready_object(objarr, BALL);
    objarr->next_obj = malloc(sizeof(objarr) * 1);
    objarr = objarr->next_obj;
    ready_object(objarr, PLANE);
    objarr->next_obj = NULL;
}