/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 01:41:53 by mzane             #+#    #+#             */
/*   Updated: 2015/06/08 16:21:59 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		e->zoom *= 0.9;
		if (x == 1000)
			e->x = 100;
		else if (y == 1000)
			e->y = 100;
	}
	if (button == 5)
		e->zoom /= 0.9;
	return (0);
}

void	check_rexpose(int keycode, t_env *e)
{
	if (keycode == 69)
		e->zoom /= 1.1;
	else if (keycode == 78)
		e->zoom *= 1.1;
	else if (keycode == 31)
		init_fract(e);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 124)
		e->move_x -= 0.05 * e->zoom;
	else if (keycode == 123)
		e->move_x += 0.05 * e->zoom;
	else if (keycode == 126)
		e->move_y -= 0.05 * e->zoom;
	else if (keycode == 125)
		e->move_y += 0.05 * e->zoom;
	else if (keycode == 0)
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
	check_rexpose(keycode, e);
	return (0);
}
