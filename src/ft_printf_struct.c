/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:48:41 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/26 20:25:43 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag(char *str, int *i)
{
	int c;

	c = 0;
	while (str[*i] != '\0' && (str[*i] == '-' || str[*i] == '0'))
	{
		if (*i > 0)
			if (str[*i] != str[*i - 1] && (str[*i - 1] == '-' ||
				str[*i - 1] == '0'))
				return (-1);
		*i += 1;
	}
	if (str[*i - 1] == '-' || str[*i - 1] == '0')
		c = str[*i - 1];
	return (c);
}

int		ft_width(char *str, int *i, va_list ap)
{
	char	*numbers;
	int		start;
	int		n;

	start = *i;
	while (str[*i] != '\0' && str[*i] >= '0' && str[*i] <= '9')
		*i += 1;
	if (str[*i] == '*')
	{
		n = va_arg(ap, int);
		*i += 1;
	}
	else
	{
		numbers = ft_substr(str, start, *i - start);
		n = ft_atoi(numbers);
		free(numbers);
	}
	return (n);
}

int		ft_precision(char *str, int *i, va_list ap)
{
	char	*numbers;
	int		start;
	int		n;

	if (str[*i] != '.')
		return (-1);
	*i += 1;
	start = *i;
	while (str[*i] >= '0' && str[*i] <= '9' && str[*i] != '\0')
		*i += 1;
	if (str[*i] == '*')
	{
		n = va_arg(ap, int);
		*i += 1;
	}
	else
	{
		if (!(numbers = ft_substr(str, start, *i - start)))
			return (-1);
		n = ft_atoi(numbers);
		free(numbers);
	}
	return (n);
}

char	ft_var(char *str, int *i)
{
	if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' || str[*i] == 'd' ||
		str[*i] == 'u' || str[*i] == 'i' || str[*i] == 'x' || str[*i] == 'X' ||
		str[*i] == '%')
		return (str[*i]);
	return (0);
}

t_var	*ft_arg_struct(char *str, int *i, va_list ap)
{
	t_var	*input;

	if (!(input = malloc(sizeof(t_var))))
		return (NULL);
	*i += 1;
	input->flag = ft_flag(str, i);
	input->width = ft_width(str, i, ap);
	if (input->width < 0 && input->flag != -1)
	{
		input->flag = '-';
		input->width *= -1;
	}
	input->precision = ft_precision(str, i, ap);
	input->var = ft_var(str, i);
	return (input);
}
