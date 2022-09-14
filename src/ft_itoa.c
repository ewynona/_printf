/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:20:48 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/05 18:54:51 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_count(int n)
{
	int	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char		*str;
	int			i;

	i = (n < 0) ? size_count(n) + 1 : size_count(n);
	if (!(str = ft_calloc(sizeof(char), (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		while (i > 0)
		{
			str[i] = '0' - (n % 10);
			i--;
			n /= 10;
		}
		str[i] = '-';
	}
	else
		while (i >= 0)
		{
			str[i] = n % 10 + '0';
			i--;
			n /= 10;
		}
	return (str);
}
