/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 01:44:09 by mzane             #+#    #+#             */
/*   Updated: 2015/06/08 16:21:00 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include "libft.h"
# define WIN_W	400
# define WIN_H	400
# define MAX_ITER 150

typedef struct	s_julia
{
	double		ac;
	double		bic;
	int			old_x;
	int			old_y;
}				t_julia;

typedef struct	s_img
{
	void		*img;
	int			width;
	int			height;
	char		*data;
	int			bpp;
	int			endian;
	int			sizeline;
}				t_img;

typedef struct	s_z
{
	double		a;
	double		bi;
}				t_z;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	int			fract;
	double		zoom;
	t_z			*c;
	t_z			*origin;
	int			col;
	double		move_y;
	double		move_x;
	int			x;
	int			y;
	int			iter;
	t_julia		*ju;
}				t_env;

int				mouse_hook_ju(int button, int x, int y, t_env *e);
int				hook_julia(int x, int y, t_env *e);
int				key_hook_ju(int keycode, t_env *e);
int				fractal_julia(t_z *new, t_env *e);
void			init_julia(t_julia *ju, t_env *e);
void			init_fract(t_env *e);
void			init_ark(t_env *e);
void			ft_put_pixel_to_img(t_img *img, int x, int y, int color);
int				burning_ship(int i);
int				hook(int x, int y, t_env *e);
int				mouse_hook_julia(int button, int x, int y, t_env *e);
int				rexpose_hook_ark(t_env *e);
void			ft_ark(t_env *e);
double			ft_abs_double(double n);
void			ft_put_pixel_to_img(t_img *img, int x, int y, int color);
t_img			*create_new_image(t_env *e, int width, int height);
void			ft_julia(t_env *e);
void			ft_put_pixel(t_img *img, int x, int y, int col);
void			ft_mandel(t_env *e);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				key_press(int keycode, t_env *e);
int				rexpose_hook_mandel(t_env *e);
int				rexpose_hook_ju(t_env *e);
void			ft_draw_mandel(t_env *e);
void			mlx_handler(t_env *e);
t_env			*init_env(char *fract);
void			init_mandel(t_env *e);
int				fractal_mandelbrot(t_z *p, t_env *e);
double			z_ytobi(int y, t_env *e);
double			z_xtoa(int x, t_env *e);

#endif
