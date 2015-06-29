/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 05:06:33 by mzane             #+#    #+#             */
/*   Updated: 2015/06/08 00:52:28 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int			fractal_ark(t_z *p, t_env *e)
{
	int		i;
	double	cp;
	t_z		z;

	z.a = ft_abs_double(p->a);
	z.bi = ft_abs_double(p->bi);
	i = 0;
	while ((z.a * z.a + z.bi * z.bi) < 10 && i < e->iter)
	{
		cp = z.a;
		z.a = ft_abs_double(z.a) * ft_abs_double(z.a)
			- ft_abs_double(z.bi) * ft_abs_double(z.bi) + p->a;
		z.bi = 2 * ft_abs_double(cp) * ft_abs_double(z.bi) + p->bi;
		i++;
	}
	if (i == e->iter)
		return (0);
	return (i);
}

void		ft_draw_ark(t_env *e)
{
	int x;
	int y;
	t_z z;
	int i;

	i = 0;
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			z.a = z_xtoa(x, e) + e->move_x;
			z.bi = z_ytobi(y, e) * -1 + e->move_y;
			i = fractal_ark(&z, e);
			e->col = burning_ship(i * 2);
			ft_put_pixel_to_img(e->img, x, y, e->col);
			x++;
		}
		y++;
	}
}

int			rexpose_hook_ark(t_env *e)
{
	e->img = create_new_image(e, WIN_W, WIN_H);
	ft_draw_ark(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	return (0);
}

void		init_ark(t_env *e)
{
	e->move_y = 0;
	e->move_x = 0;
	e->col = 0x000000;
	e->zoom = 0.1;
	e->iter = 150;
	e->origin->a = -1.624331;
	e->origin->bi = 0.017875;
}

void		ft_ark(t_env *e)
{
	init_ark(e);
	mlx_expose_hook(e->win, rexpose_hook_ark, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop_hook(e->mlx, rexpose_hook_ark, e);
	mlx_loop(e->mlx);
}
