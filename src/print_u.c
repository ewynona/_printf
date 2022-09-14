/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 00:42:02 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/27 02:20:14 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_count(unsigned int n)
{
	int	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa_u(unsigned int n)
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

char		*put_prec_u(int prec, unsigned int num)
{
	char	*str;
	char	*nums;
	int		len;
	int		i;

	i = 0;
	nums = ft_itoa_u(num);
	len = ft_strlen(nums);
	if (prec > len)
	{
		i = prec - len;
		str = malloc(sizeof(char) * prec);
		ft_memset(str, '0', i);
		str[i] = '\0';
		str = ft_strjoin(str, nums);
		free(nums);
		return (str);
	}
	return (nums);
}

int			print_u(t_var *pr, unsigned int i)
{
	char	*nums;
	int		len;

	if (i == 0 && pr->precision == 0)
		nums = NULL;
	else
		nums = put_prec_u(pr->precision, i);
	len = ft_strlen(nums);
	if (pr->flag == 0 || pr->flag == '0')
	{
		if ((pr->flag == '0' && pr->precision >= 0) || pr->flag == 0)
			putchar_width(pr->width, len, ' ');
		else
			putchar_width(pr->width, len, '0');
		ft_putstr_fd(nums, 1);
	}
	else if (pr->flag == '-')
	{
		ft_putstr_fd(nums, 1);
		putchar_width(pr->width, len, ' ');
	}
	free(nums);
	return (pr->width > len) ? pr->width : len;
}

int			print_procent(t_var *pr)
{
	if (pr->flag == -1 || pr->flag == '-')
	{
		ft_putchar_fd('%', 1);
		putchar_width(pr->width, 1, ' ');
	}
	else if (pr->flag == '0')
	{
		putchar_width(pr->width, 1, '0');
		ft_putchar_fd('%', 1);
	}
	else
	{
		putchar_width(pr->width, 1, ' ');
		ft_putchar_fd('%', 1);
	}
	return (pr->width > 1) ? pr->width : 1;
}
