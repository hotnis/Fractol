/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trijoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 16:05:36 by mzane             #+#    #+#             */
/*   Updated: 2015/05/23 16:15:12 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trijoin(char const *s1, char const *s2, char const *s3)
{
	char	*str;

	if (!s1 || !s2 || !s3)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3));
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	ft_strcat(str, s3);
	return (str);
}
