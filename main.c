/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:11:03 by mzane             #+#    #+#             */
/*   Updated: 2015/06/08 18:38:41 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_img		*create_new_image(t_env *e, int width, int height)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	if (!(img->img = mlx_new_image(e->mlx, width, height)))
		return (NULL);
	img->width = width;
	img->height = height;
	img->data = mlx_get_data_addr(img->img, &img->bpp,
			&img->sizeline, &img->endian);
	return (img);
}

void		init_fract(t_env *e)
{
	if (e->fract == 1)
		init_mandel(e);
	else if (e->fract == 3)
		init_ark(e);
	else if (e->fract == 2)
		init_julia(e->ju, e);
}

int			is_fractal_name(char *arg)
{
	char *argmin;

	argmin = ft_lowstr(arg);
	if (ft_strcmp(argmin, "mandel") == 0 ||
		ft_strcmp(argmin, "mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(argmin, "julia") == 0)
		return (2);
	else if (ft_strcmp(argmin, "burning_ship") == 0 ||
		ft_strcmp(argmin, "ship") == 0)
		return (3);
	return (0);
}

void		ft_fractol(int fract)
{
	t_env e;

	e.fract = fract;
	if (!(e.mlx = mlx_init()))
	{
		ft_putendl("mlx error");
		exit(-1);
	}
	if (!(e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, "fractol")))
	{
		ft_putendl("mlx_error");
	}
	e.img = NULL;
	e.origin = malloc(sizeof(t_z));
	e.c = malloc(sizeof(t_z));
	e.ju = malloc(sizeof(t_julia));
	if (fract == 1)
		ft_mandel(&e);
	else if (fract == 2)
		ft_julia(&e);
	else if (fract == 3)
		ft_ark(&e);
}

int			main(int ac, char **av)
{
	int	argc;

	if (ac == 2)
		if ((argc = is_fractal_name(av[1])) != 0)
			ft_fractol(argc);
		else
			ft_putendl("Usage : ./fractol [Julia][Mandelbrot][Burning_ship]");
	else
		ft_putendl("Usage : ./fractol [Julia][Mandelbrot][Burning_ship]");
	return (0);
}
