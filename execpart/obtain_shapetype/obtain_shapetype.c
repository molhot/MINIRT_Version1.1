/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obtain_shapetype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:58:28 by user              #+#    #+#             */
/*   Updated: 2023/04/09 15:00:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

int obtain_shapetype(t_objarr *sub)
{
    if (sub->ball == NULL)
        return (PLANE);
    if (sub->plane == NULL)
        return (BALL);
    return (0);
}