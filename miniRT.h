/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:06:09 by user              #+#    #+#             */
/*   Updated: 2023/04/08 14:27:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//include
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "minilibx-linux/mlx.h"

//judge shape by magic number
# define CIRCLE 1
# define PLANE 2
# define CORN 3

// simple vector
typedef	struct s_vector
{
	double	x;
	double	y;
	double	z;
} t_vector;

// contain vec variable info
typedef struct	s_vecinf
{
	t_vector	vec;
	t_vector	u_vec;
	double		size;
} t_vecinf;

// fixpoint vector
// from here, all vectors name is [_v]
//if name not contain [2], it means that vector is from (0,0,0) to the only point

//lightsource is only or not ,so i have the lightinfo as list
typedef	struct	s_lgtarr t_lgtarr;

typedef	struct	s_lgtarr
{
	t_vecinf	lgt_v;
	t_lgtarr	*next_lgt;
};

//there are lot of objs, under infs are objs infs
//obj's type is [ball, plane, corn](i will add any other shape)
//depend on obj's type, obj's lgt reflect coefficient are different
//so objct has those infos

//refrect coefficient info
typedef struct s_refCoeff {
	double	ka;
	double	kd;
	double	ks;
	double	alpha;
	double	Ia;
	double	Ii;
	double	n_l;
	double	v_r;
	double	Rs;
}t_refCoeff;

typedef	struct s_plane{
	t_vector	n;
	t_vector	point;
	t_refCoeff	t_refCoeff;
	bool		has_specmir;
	double		spec_mir;
}t_plane;

typedef	struct s_ball{
	t_vecinf	center_v;
	double		rad;
	t_refCoeff	t_refCoeff;
	bool		has_specmir;
	double		spec_mir;
} t_ball;

//item amount is one or more, so have the inf of objs as list
typedef	struct	s_objarr t_objarr;

typedef struct	s_objarr
{
	t_plane		*plane;
	t_ball		*ball;
	t_objarr	*next_obj;
};

//above, shape infos

//any fixed vec(ex: item inf, eye point...) contains t_fvec(=fixedpointvec)
typedef	struct	s_fvec
{
	t_vecinf	eye_v;
	t_vecinf	scr_v;
	t_lgtarr	*lgtarr;
	t_objarr	*objarr;
} t_fvec;

//minilibx needs any drawinfo, above is all needs infos
typedef struct s_drawinf
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*mlx_win;
	size_t		width;
	size_t		height;
}t_drawinf;

//allinfo put togather to above struct
typedef struct s_allinfs
{
	t_drawinf	*drawinf;
	t_fvec		*fix_vecs;
}t_allinfs;

# endif