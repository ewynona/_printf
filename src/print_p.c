/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 23:06:17 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/26 21:37:55 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		print_p(t_var *pr, long int c)
{
	char	*str;
	int		len;

	if (pr->precision == 0 && c == 0)
		str = NULL;
	else
		str = ft_itoa_base_long(c, 16, 'x');
	len = ft_strlen(str) + 2;
	if (pr->flag == 0)
	{
		putchar_width(pr->width, len, ' ');
		write(1, "0x", 2);
		ft_putstr_fd(str, 1);
	}
	else if (pr->flag == '-')
	{
		write(1, "0x", 2);
		ft_putstr_fd(str, 1);
		putchar_width(pr->width, len, ' ');
	}
	free(str);
	return (pr->width > len) ? pr->width : len;
}
