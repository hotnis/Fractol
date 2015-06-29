/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 10:00:07 by mzane             #+#    #+#             */
/*   Updated: 2014/11/14 10:03:40 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	int		max;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	max = len;
	len = ft_strlen(s) - (len + i);
	str = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (i <= max)
		str[len++] = s[i++];
	str[len] = '\0';
	return (str);
}
