/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complexe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 15:27:49 by mzane             #+#    #+#             */
/*   Updated: 2015/06/05 18:35:24 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

double		z_xtoa(int x, t_env *e)
{
	double	size;

	if (e->fract == 1 || e->fract == 3)
	{
		size = 4. / WIN_W * e->zoom;
		return ((double)x * size - (WIN_W / 2) * size + e->origin->a);
	}
	else if (e->fract == 2)
	{
		size = 4. / WIN_W * e->zoom;
		return ((double)x * size - (WIN_W / 2) * size + (e->ju)->ac);
	}
	return (0);
}

double		z_ytobi(int y, t_env *e)
{
	double	size;

	if (e->fract == 1 || e->fract == 3)
	{
		size = 4. / WIN_W * e->zoom;
		return ((WIN_H / 2) * size - (double)y * size + e->origin->bi);
	}
	else if (e->fract == 2)
	{
		size = 4. / WIN_W * e->zoom;
		return ((WIN_H / 2) * size - (double)y * size + (e->ju)->bic);
	}
	return (0);
}
