/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 08:31:44 by mzane             #+#    #+#             */
/*   Updated: 2015/06/03 08:32:31 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lowstr(char *str)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		tmp[i] = ft_tolower(str[i]);
		i++;
	}
	return (tmp);
}
