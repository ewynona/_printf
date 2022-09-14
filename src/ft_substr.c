/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:27:04 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/05 11:44:01 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	size = (ft_strlen(s) <= len) ? ft_strlen(s) - start : len;
	if (ft_strlen(s) <= start)
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	if (!(str = malloc(size + 1)))
		return (NULL);
	ft_strlcpy(str, &s[start], size + 1);
	return (str);
}
