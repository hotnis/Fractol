/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 01:13:12 by mzane             #+#    #+#             */
/*   Updated: 2015/06/08 01:26:25 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void		color_hook_ju(int keycode, t_env *e)
{
	if (keycode == 0)
		e->col += 0x100000;
	else if (keycode == 2)
		e->col -= 0x100000;
	else if (keycode == 13)
		e->col += 0x001000;
	else if (keycode == 1)
		e->col -= 0x001000;
	else if (keycode == 12)
		e->col += 0x000010;
	else if (keycode == 14)
		e->col -= 0x000010;
}

int			key_hook_ju(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 124)
		e->move_x -= 0.05 / e->zoom;
	else if (keycode == 123)
		e->move_x += 0.05 / e->zoom;
	else if (keycode == 126)
		e->move_y += 0.05 / e->zoom;
	else if (keycode == 125)
		e->move_y -= 0.05 / e->zoom;
	else if (keycode == 69)
		e->zoom *= 1.1;
	else if (keycode == 78)
		e->zoom /= 1.1;
	else if (keycode == 31)
		init_fract(e);
	color_hook_ju(keycode, e);
	return (0);
}

int			mouse_hook_ju(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		e->zoom *= 1.1;
		if (x == 1000)
			e->x = 100;
		else if (y == 1000)
			e->y = 100;
		if ((int)e->zoom % 10 == 0)
			e->iter *= 1.1;
	}
	else if (button == 5)
	{
		e->zoom /= 1.1;
		if ((int)e->zoom % 10 == 0)
			e->iter /= 1.1;
	}
	else if (button == 1)
	{
		(e->ju)->ac = -0.7;
		(e->ju)->bic = 0.27015;
	}
	return (0);
}

int			hook_julia(int x, int y, t_env *e)
{
	if (x > (e->ju)->old_x)
		(e->ju)->ac += 0.005 / e->zoom;
	else
		(e->ju)->ac -= 0.005 / e->zoom;
	if (y > (e->ju)->old_y)
		(e->ju)->bic += 0.005 / e->zoom;
	else
		(e->ju)->bic -= 0.005 / e->zoom;
	(e->ju)->old_x = x;
	(e->ju)->old_y = y;
	return (0);
}
