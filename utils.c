/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 08:15:30 by mzane             #+#    #+#             */
/*   Updated: 2015/06/08 01:35:35 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void		ft_put_pixel(t_img *img, int x, int y, int col)
{
	if (0 < x && x < WIN_W && 0 < y && y < WIN_H)
		ft_memcpy(&img->data[(y * img->bpp / 8) + (x * (img->bpp / 8) * WIN_W)],
					&col, 4);
}

double		ft_abs_double(double n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int			expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int			burning_ship(int i)
{
	t_env e;

	e.col = 0x000000;
	while (i != 0)
	{
		e.col += 0x000100;
		i--;
	}
	return (e.col);
}

void		ft_put_pixel_to_img(t_img *img, int x, int y, int color)
{
	int			octet;
	int			position;

	octet = img->sizeline / WIN_W;
	if (y > 0)
		y -= 1;
	position = (img->sizeline * y) + (x * octet);
	if (ft_memcmp(img->data + position, &color, octet) != 0)
		ft_memcpy(img->data + position, &color, octet);
}
