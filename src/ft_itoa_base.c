/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:03:48 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/25 22:54:30 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_not(int r, int rev)
{
	if (r == 'x' && rev == 0)
		return ("0123456789abcdef");
	else if (r == 'X' && rev == 0)
		return ("0123456789ABCDEF");
	else if (r == 'x' && rev == 1)
		return ("fedcba9876543210");
	else
		return ("FEDCBA9876543210");
}

char	*ft_itoa_rev(int value, int base, int r)
{
	int		size;
	int		i;
	char	*notation;
	char	*str;
	int		tmp;

	size = 8;
	i = 1;
	value = value * -1 - 1;
	tmp = value;
	notation = ft_not(r, 1);
	while (tmp /= base)
		i++;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str = ft_memset(str, notation[0], size);
	str[size] = '\0';
	while (size > 8 - i)
	{
		size--;
		str[size] = notation[value % base];
		value /= base;
	}
	return (str);
}

char	*ft_itoa_base(int value, int base, int r)
{
	int		size;
	char	*notation;
	char	*str;
	int		tmp;
	int		sign;

	if (value < 0 && base != 10)
		return (ft_itoa_rev(value, base, r));
	sign = (value < 0 && base == 10) ? 1 : 0;
	size = (value < 0 && base == 10) ? 2 : 1;
	value = (value < 0 && base == 10) ? value * -1 : value;
	tmp = value;
	notation = ft_not(r, 0);
	while (tmp /= base)
		size++;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	str[0] = '-';
	while (size-- > sign)
	{
		str[size] = notation[value % base];
		value /= base;
	}
	return (str);
}

char	*ft_itoa_rev_long(long int value, int base, int r)
{
	int			size;
	int			i;
	char		*notation;
	char		*str;
	long int	tmp;

	size = 16;
	i = 1;
	value = value * -1 - 1;
	tmp = value;
	notation = ft_not(r, 1);
	while (tmp /= base)
		i++;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str = ft_memset(str, notation[0], size);
	str[size] = '\0';
	while (size > 8 - i)
	{
		size--;
		str[size] = notation[value % base];
		value /= base;
	}
	return (str);
}

char	*ft_itoa_base_long(long int value, int base, int r)
{
	int			size;
	char		*notation;
	char		*str;
	long int	tmp;
	int			sign;

	if (value < 0 && base != 10)
		return (ft_itoa_rev_long(value, base, r));
	sign = (value < 0 && base == 10) ? 1 : 0;
	size = (value < 0 && base == 10) ? 2 : 1;
	value = (value < 0 && base == 10) ? value * -1 : value;
	tmp = value;
	notation = ft_not(r, 0);
	while (tmp /= base)
		size++;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	str[0] = '-';
	while (size-- > sign)
	{
		str[size] = notation[value % base];
		value /= base;
	}
	return (str);
}
