/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:02:18 by user              #+#    #+#             */
/*   Updated: 2023/04/09 13:04:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

// void	draw_fadecolor(double i, t_data *data, int x, int y, int type)
// {
// 	if (i > 1)
// 		i = 1;
// 	if (type == 1)
// 		my_mlx_pixel_put(data, x, y, ((int)(255 * i) << 16) | ((int)(255 * i) << 8) | (int)(255 * i));
// 	else if (type == 2)
// 		my_mlx_pixel_put(data, x, y, ((int)(255 * i) << 16) | ((int)(5 * i) << 8) | (int)(255 * i));
// }

void	my_mlx_pixel_put(t_drawinf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
