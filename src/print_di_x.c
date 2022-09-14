/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:20:50 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/27 01:09:15 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*nums_prec(char *nums, int *i, int prec)
{
	char	*str;

	if (nums[0] == '-')
	{
		str = malloc(sizeof(char) * (prec + 2));
		*i += 2;
		ft_memset(str, '0', *i);
		str[*i] = '\0';
		str = ft_strjoin(str, &nums[1]);
		str[0] = '-';
	}
	else
	{
		str = malloc(sizeof(char) * prec + 1);
		ft_memset(str, '0', *i);
		str[*i] = '\0';
		str = ft_strjoin(str, nums);
	}
	return (str);
}

char	*put_prec_d_i(int prec, int num, char var)
{
	char	*str;
	char	*nums;
	int		len;
	int		i;

	i = 0;
	str = NULL;
	if (var == 'd' || var == 'i')
		nums = ft_itoa(num);
	else if (var == 'X' || var == 'x')
		nums = ft_itoa_base(num, 16, var);
	len = ft_strlen(nums);
	if (prec >= len)
	{
		i = prec - len;
		str = nums_prec(nums, &i, prec);
		free(nums);
		return (str);
	}
	return (nums);
}

void	put_nums(t_var *pr, char *nums)
{
	if ((pr->flag == '0' && pr->precision >= 0) || pr->flag == 0)
	{
		putchar_width(pr->width, ft_strlen(nums), ' ');
		ft_putstr_fd(nums, 1);
	}
	else
	{
		if (nums[0] == '-')
		{
			ft_putchar_fd('-', 1);
			putchar_width(pr->width, ft_strlen(nums), '0');
			ft_putstr_fd(&nums[1], 1);
		}
		else
		{
			putchar_width(pr->width, ft_strlen(nums), '0');
			ft_putstr_fd(nums, 1);
		}
	}
}

int		print_di_x(t_var *pr, int i)
{
	char	*nums;
	int		len;

	if (i == 0 && pr->precision == 0)
		nums = NULL;
	else
		nums = put_prec_d_i(pr->precision, i, pr->var);
	len = ft_strlen(nums);
	if (pr->flag == 0 || pr->flag == '0')
	{
		put_nums(pr, nums);
	}
	else if (pr->flag == '-')
	{
		ft_putstr_fd(nums, 1);
		putchar_width(pr->width, len, ' ');
	}
	free(nums);
	return (pr->width > len) ? pr->width : len;
}
