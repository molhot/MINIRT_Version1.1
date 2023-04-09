/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obtain_shapetype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:58:28 by user              #+#    #+#             */
/*   Updated: 2023/04/09 18:10:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

int obtain_shapetype(t_objarr *sub)
{
    if (sub->ball != NULL)
        return (BALL);
    else if (sub->plane != NULL)
        return (PLANE);
    else
        return (-1);
}