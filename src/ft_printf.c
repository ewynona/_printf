/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:36:49 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/29 17:40:16 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_processing(char var, va_list ap, t_var *pr)
{
	int count;

	if (var == 'c')
		count = print_c(pr, va_arg(ap, int));
	else if (var == 's')
		count = print_s(pr, va_arg(ap, char *));
	else if (var == 'd' || var == 'i' || var == 'x' || var == 'X')
		count = print_di_x(pr, va_arg(ap, int));
	else if (var == 'p')
		count = print_p(pr, va_arg(ap, long int));
	else if (var == 'u')
		count = print_u(pr, va_arg(ap, unsigned int));
	else if (var == '%')
		count = print_procent(pr);
	else
		count = 0;
	free(pr);
	return (count);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	t_var	*pr;
	va_list ap;

	i = -1;
	count = 0;
	va_start(ap, str);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			pr = ft_arg_struct((char *)str, &i, ap);
			if (pr->var == '\0')
				return (count);
			count += ft_processing(pr->var, ap, pr);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
