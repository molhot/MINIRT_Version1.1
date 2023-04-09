/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:06:09 by user              #+#    #+#             */
/*   Updated: 2023/04/09 14:26:31 by user             ###   ########.fr       */
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
# define BALL 1
# define PLANE 2
# define CORN 3

// simple vector
typedef	struct s_vec
{
	double	x;
	double	y;
	double	z;
} t_vec;

// contain vec variable info
typedef struct	s_vecinf
{
	t_vec		vec;
	t_vec		u_vec;
	double		size;
} t_vecinf;

// fixpoint vector
// from here, all vectors name is [_v]
//if name not contain [2], it means that vector is from (0,0,0) to the only point

//lightsource is only or not ,so i have the lightinfo as list
typedef	struct	s_lgtarr t_lgtarr;

struct	s_lgtarr
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
	t_vecinf	*n;
	t_vecinf	*point;
	t_refCoeff	t_refCoeff;
	bool		has_specmir;
	double		spec_mir;
}t_plane;

typedef	struct s_ball{
	t_vecinf	*center_v;
	double		rad;
	t_refCoeff	t_refCoeff;
	bool		has_specmir;
	double		spec_mir;
} t_ball;

//item amount is one or more, so have the inf of objs as list
typedef	struct	s_objarr t_objarr;

struct s_objarr
{
	t_plane		*plane;
	t_ball		*ball;
	t_objarr	*next_obj;
};

//above, shape infos

//any fixed vec(ex: item inf, eye point...) contains t_fvec(=fixedpointvec)
//* scrnvectr is prepared when x and y point is recognized
typedef	struct	s_fvec
{
	t_vecinf	*eye_v;
	t_vecinf	*scr_v;
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

//explain functions flaw

//all flow start from main
int	main();
//main calls three function
void    constructer(t_allinfs *infs);
//exec
//destructer

// constructer => ready_anyinfs like vectors
//first, ready infos of drawinfo
void    ready_drawinf(t_drawinf *draw_inf);
//second, ready fixed vectors
void    ready_vectors(t_fvec *fvecs);
void    ready_o2eyeVec(t_vecinf *eye_v);
void    ready_lgtarr(t_lgtarr *lgtarr);
void    ready_objarr(t_objarr *objarr);

//when ready_vectors, use below funcs
void    set_vec(t_vecinf *vecinf, double x, double y, double z);


// exec
//while x and y are not last, it put pixcel to screen
void    exec(t_allinfs *infs, double x, double y);
//when render start, point of screen is scaled to thirddimention
void	dim2tdim(t_vecinf *dim_vec, double x, double y, double width, double height);
//
void	draw_fadecolor(double i, t_allinfs *infs, int x, int y);
//by shape type, fade color
double  fade_color(double fade);
//while drawfunction is active, above vect set func is called when you set vector(s)
void    setvec_d(t_vecinf *vecinf, double x, double y, double z);

//when put pixcel, use above func
void	my_mlx_pixel_put(t_drawinf *data, int x, int y, int color);

// destructer

# endif