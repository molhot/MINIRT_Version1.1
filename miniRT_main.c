/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:03:26 by user              #+#    #+#             */
/*   Updated: 2023/04/09 23:07:11 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	show_vec(t_vecinf *vecinf)
{
    printf("~~\n");
	printf("vector are %f, %f, %f\n", vecinf->vec.x, vecinf->vec.y, vecinf->vec.z);
	printf("unitvector are %f, %f, %f\n", vecinf->u_vec.x, vecinf->u_vec.y, vecinf->u_vec.z);
	printf("size is %f\n", vecinf->size);
}

int main()
{
    t_allinfs   allinfs;

    constructer(&allinfs);
    exec(&allinfs);
    //destructer();
}
