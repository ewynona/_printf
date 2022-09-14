/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:24:21 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/26 19:43:45 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchar_width(int width, int len, char c)
{
	while (width > len)
	{
		width--;
		ft_putchar_fd(c, 1);
	}
}
