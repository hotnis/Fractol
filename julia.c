/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 02:04:50 by mzane             #+#    #+#             */
/*   Updated: 2015/06/08 16:11:49 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int			fractal_julia(t_z *new, t_env *e)
{
	t_z			old;
	int			i;

	i = 0;
	while (i < e->iter)
	{
		old.a = new->a;
		old.bi = new->bi;
		new->a = old.a * old.a - old.bi * old.bi + (e->ju)->ac;
		new->bi = 2 * old.a * old.bi + (e->ju)->bic;
		if ((new->a * new->a + new->bi * new->bi) > 4)
			break ;
		i++;
	}
	return (i);
}

void		ft_draw_julia(t_env *e)
{
	t_z			n;
	int			color;
	int			x;
	int			y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			n.a = 1.5 * (x - WIN_H / 2) / (0.5 * e->zoom * WIN_H) + e->move_y;
			n.bi = (y - WIN_H / 2) / (0.5 * e->zoom * WIN_H) + e->move_x;
			color = (e->col * (fractal_julia(&n, e)));
			ft_put_pixel(e->img, x, y, color);
			x++;
		}
		y++;
	}
}

int			rexpose_hook_ju(t_env *e)
{
	e->img = create_new_image(e, WIN_W, WIN_H);
	ft_draw_julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	return (0);
}

void		init_julia(t_julia *ju, t_env *e)
{
	ju->ac = -0.7;
	ju->bic = 0.27015;
	e->zoom = 1;
	e->move_x = 0;
	e->move_y = 0;
	e->iter = 150;
	e->col = 0x00ef00;
	ju->old_x = 200;
	ju->old_y = 200;
}

void		ft_julia(t_env *e)
{
	t_julia ju;

	init_julia(&ju, e);
	e->ju = &ju;
	rexpose_hook_ju(e);
	mlx_key_hook(e->win, key_hook_ju, e);
	mlx_mouse_hook(e->win, mouse_hook_ju, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 6, (1L << 6), hook_julia, e);
	mlx_loop_hook(e->mlx, rexpose_hook_ju, e);
	mlx_loop(e->mlx);
}
