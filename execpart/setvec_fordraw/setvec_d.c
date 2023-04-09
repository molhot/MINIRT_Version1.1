/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setvec_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:11:16 by user              #+#    #+#             */
/*   Updated: 2023/04/09 14:25:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

static  void    vecset_d(t_vec *vec, double x, double y, double z)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
}

static  void    sizeset_d(double *size, double x, double y, double z)
{
    *size = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

static  void    uvecset_d(t_vec *vec, double size, double x, double y, double z)
{
    vecset_d(vec, x / size, y / size, z / size);
}

void    setvec_d(t_vecinf *vecinf, double x, double y, double z)
{
    vecset_d(&vecinf->vec, x, y, z);
    sizeset_d(&vecinf->size, x, y, z);
    uvecset_d(&vecinf->u_vec, vecinf->size, x, y, z);
}

void	dim2tdim(t_vecinf *dim_vec, double x, double y, double width, double height)
{
	double	tdim_x;
	double	tdim_y;

	tdim_x = (2 * x / (width - 1)) - 1;
	tdim_y = (-2 * y / (height - 1)) + 1;
	setvec_d(dim_vec, tdim_x, tdim_y, 0);
}
