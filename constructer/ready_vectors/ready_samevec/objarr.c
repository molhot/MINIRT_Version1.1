/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objarr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:25:53 by user              #+#    #+#             */
/*   Updated: 2023/04/29 16:16:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../miniRT.h"

static  void    refCoeff(t_refCoeff *refcoeff)
{
    refcoeff->ka = 0.01;
	refcoeff->kd = 0.69;
	refcoeff->ks = 0.3;
	refcoeff->alpha = 8.0;
	refcoeff->Ia = 0.1;
	refcoeff->Ii = 1.0;
}

static  void    refCoeff2(t_refCoeff *refcoeff)
{
    refcoeff->ka = 0;
	refcoeff->kd = 0;
	refcoeff->ks = 0;
	refcoeff->alpha = 0;
	refcoeff->Ia = 0;
	refcoeff->Ii = 0;
}

static  void    ready_plane(t_plane *plane)
{
    plane->n = malloc(sizeof(t_vecinf) * 1);
    set_vec(plane->n, 0.0, 1.0, 0.0);
    plane->point = malloc(sizeof(t_vecinf) * 1);
    set_vec(plane->point, 0.0, -1.0, 0.0);
    refCoeff(&plane->t_refCoeff);
    plane->has_specmir = false;
    plane->spec_mir = 0.0;
}

static  void    ready_ball(t_ball *ball, int pos)
{
    ball->center_v = malloc(sizeof(t_vecinf) * 1);
    if (pos == 1)
        set_vec(ball->center_v, 0, 0, 5);
    else if (pos == 2)
        set_vec(ball->center_v, -2, 3, 10);
    else if (pos == 3)
    {
        set_vec(ball->center_v, -2, 0, 10);
        ball->rad = 1;
        refCoeff2(&ball->t_refCoeff);
        ball->has_specmir = true;
        ball->spec_mir = 1;
        return ;
    }
    ball->rad = 2.0;
    refCoeff(&ball->t_refCoeff);
    ball->has_specmir = false;
    ball->spec_mir = 0;
}

static void    ready_cylinder(t_cylinder	*cylinder)
{
    cylinder->center_v = malloc(sizeof(t_vecinf) * 1);
    set_vec(cylinder->center_v, 0.0, 0.0, 0.0);
    cylinder->center_n_v = malloc(sizeof(t_vecinf) * 1);
    set_vec(cylinder->center_n_v, 0.0, 1.0, 0.0);
    refCoeff(&cylinder->t_refCoeff);
    cylinder->rad = 0.5;
    cylinder->height = 0.5;
}

void    ready_object(t_objarr *objarr, double type, int pos)
{
    if (type == BALL)
    {
        objarr->ball = malloc(sizeof(t_ball) * 1);
        ready_ball(objarr->ball, pos);
        objarr->plane = NULL;
        objarr->cylinder = NULL;
    }
    else if (type == PLANE)
    {
        objarr->plane = malloc(sizeof(t_plane) * 1);
        ready_plane(objarr->plane);
        objarr->ball = NULL;
        objarr->cylinder = NULL;
    }
    else if (type == CYLINDER)
    {
        objarr->cylinder = malloc(sizeof(t_cylinder) * 1);
        ready_cylinder(objarr->cylinder);
        objarr->ball = NULL;
        objarr->plane = NULL;
    }
}

void    ready_objarr(t_fvec *fvecs)
{
	t_objarr	*tmp_obj;

	fvecs->objarr = malloc(sizeof(t_objarr) * 1);
	tmp_obj = fvecs->objarr;
	ready_object(tmp_obj, CYLINDER, 2);
    // /*ここを足していけば試せる*/
	// // tmp_obj->next_obj = malloc(sizeof(t_objarr) * 1);
    // // tmp_obj = tmp_obj->next_obj;
    // // ready_object(tmp_obj, BALL, 1);
    // /**/
    // tmp_obj->next_obj = malloc(sizeof(t_objarr) * 1);
    // tmp_obj = tmp_obj->next_obj;
    // ready_object(tmp_obj, PLANE, 1);

    // tmp_obj->next_obj = malloc(sizeof(t_objarr) * 1);
    // tmp_obj = tmp_obj->next_obj;
    // ready_object(tmp_obj, BALL, 3);

    tmp_obj->next_obj = NULL;
    //fvecs->objarr = NULL;
}