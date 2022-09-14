/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 01:53:19 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/27 02:51:12 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c(t_var *pr, char c)
{
	int w;

	w = pr->width;
	if (pr->flag == '0' || pr->flag == -1)
		return (-1);
	if (pr->flag == 0)
	{
		putchar_width(pr->width, 1, ' ');
		ft_putchar_fd(c, 1);
	}
	else if (pr->flag == '-')
	{
		ft_putchar_fd(c, 1);
		putchar_width(pr->width, 1, ' ');
	}
	if (pr->width == 0)
		return (1);
	return (pr->width);
}

char	*str_prec(int prec, char *s)
{
	char	*str;

	if (!s)
		s = "(null)";
	if (ft_strlen(s) > (size_t)prec)
		str = ft_substr(s, 0, prec);
	else
		str = ft_substr(s, 0, ft_strlen(s));
	return (str);
}

int		print_s(t_var *pr, char *s)
{
	int		w;
	int		len;
	char	*str;

	w = pr->width;
	if (pr->flag == '0' || pr->var != 's' || pr->flag == -1)
		return (-1);
	str = str_prec(pr->precision, s);
	len = ft_strlen(str);
	if (pr->flag == 0)
	{
		putchar_width(pr->width, len, ' ');
		ft_putstr_fd(str, 1);
	}
	else if (pr->flag == '-')
	{
		ft_putstr_fd(str, 1);
		putchar_width(pr->width, len, ' ');
	}
	free(str);
	return (pr->width > len) ? pr->width : len;
}
