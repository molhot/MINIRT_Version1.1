/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:54:01 by user              #+#    #+#             */
/*   Updated: 2023/04/08 15:01:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

static  void    vecset(t_vec *vec, double x, double y, double z)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
}

static  void    sizeset(double *size, double x, double y, double z)
{
    *size = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

static  void    u_vecset(t_vec *vec, double size, double x, double y, double z)
{
    vecset(vec, x / size, y / size, z / size);
}

void    set_vec(t_vecinf *vecinf, double x, double y, double z)
{
    vecset(&vecinf->vec, x, y, z);
    sizeset(&vecinf->size, x, y, z);
    u_vecset(&vecinf->u_vec, vecinf->size, x, y, z);
}