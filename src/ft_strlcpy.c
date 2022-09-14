/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:54:17 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/06 13:54:20 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = (char *)dst;
	s2 = (char *)src;
	if (!src)
		return (0);
	if (dstsize != 0)
	{
		while (dstsize-- > 1 && s2[i] != '\0')
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
	}
	return (ft_strlen(src));
}
