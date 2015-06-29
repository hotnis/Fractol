/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 14:48:05 by mzane             #+#    #+#             */
/*   Updated: 2015/06/08 16:22:50 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int			fractal_mandelbrot(t_z *p, t_env *e)
{
	int		i;
	t_z		new;
	t_z		old;

	new.a = 0;
	new.bi = 0;
	i = 0;
	while (i < e->iter)
	{
		old.a = new.a;
		old.bi = new.bi;
		new.a = old.a * old.a - old.bi * old.bi + p->a;
		new.bi = 2 * old.a * old.bi + p->bi;
		if ((new.a * new.a + new.bi * new.bi) > 4)
			break ;
		i++;
	}
	if (i == e->iter)
		return (0);
	return (i);
}

void		ft_draw_mandel(t_env *e)
{
	int color;
	int x;
	int y;
	t_z z;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			z.a = z_xtoa(x, e) + e->move_x;
			z.bi = z_ytobi(y, e) + e->move_y;
			color = (e->col * (fractal_mandelbrot(&z, e)));
			ft_put_pixel_to_img(e->img, x, y, color);
			x++;
		}
		y++;
	}
}

int			rexpose_hook_mandel(t_env *e)
{
	e->img = create_new_image(e, WIN_W, WIN_H);
	ft_draw_mandel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	return (0);
}

void		init_mandel(t_env *e)
{
	e->move_y = 0;
	e->move_x = 0;
	e->col = 0x00003F;
	e->zoom = 0.7;
	e->iter = 150;
	e->origin->a = -0.62;
	e->origin->bi = -0.04;
}

void		ft_mandel(t_env *e)
{
	init_mandel(e);
	mlx_expose_hook(e->win, rexpose_hook_mandel, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop_hook(e->mlx, rexpose_hook_mandel, e);
	mlx_loop(e->mlx);
}
