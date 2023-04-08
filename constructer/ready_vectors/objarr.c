/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objarr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:25:53 by user              #+#    #+#             */
/*   Updated: 2023/04/08 18:16:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

static  void    ready_plane(t_plane *plane)
{
    plane = malloc(sizeof(t_plane) * 1);
    plane->n = malloc(sizeof(t_vecinf) * 1);
    set_vec(plane->n, 0, 1, 0);
    plane->point = malloc(sizeof(t_vecinf) * 1);
    set_vec(plane->point, 0, -1, 0);
    plane->has_specmir = false;
    plane->spec_mir = 0;
}

static  void    ready_ball(t_ball *ball)
{
    ball = malloc(sizeof(t_ball) * 1);
    ball->center_v = malloc(sizeof(t_vecinf) * 1);
    set_vec(ball->center_v, 1, 0, -1);
    ball->rad = 1;
    ball->has_specmir = false;
    ball->spec_mir = 0;
}

void    ready_object(t_objarr *objarr, double type)
{
    if (type == BALL)
        ready_ball(&objarr->ball);
    else if (type == PLANE)
        ready_plane(objarr->plane);
}

void    ready_objarr(t_objarr *objarr)
{
    t_objarr objinf;

    objarr = malloc(sizeof(objarr) * 1);
    ready_object(objarr, BALL);
    objarr->next_obj = malloc(sizeof(objarr) * 1);
    objarr = objarr->next_obj;
    ready_object(objarr, PLANE);
    objarr->next_obj = NULL;
}