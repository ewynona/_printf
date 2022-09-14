/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:48:35 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/27 17:55:11 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct	s_var
{
	int				flag;
	int				width;
	int				precision;
	char			var;
}				t_var;

int				ft_flag(char *str, int *i);
int				ft_width(char *str, int *i, va_list ap);
int				ft_precision(char *str, int *i, va_list ap);
char			ft_var(char *str, int *i);
t_var			*ft_arg_struct(char *str, int *i, va_list ap);
int				print_c(t_var *pr, char c);
char			*str_prec(int prec, char *s);
int				print_s(t_var *pr, char *s);
char			*put_prec_d_i(int prec, int num, char var);
int				print_di_x(t_var *pr, int i);
int				ft_printf(const char *str, ...);
char			*ft_itoa_base(int value, int base, int r);
char			*ft_not(int r, int rev);
char			*ft_itoa_rev(int value, int base, int r);
int				print_p(t_var *pr, long int c);
char			*ft_itoa_u(unsigned int u);
char			*ft_itoa_base_long(long int value, int base, int r);
int				print_u(t_var *pr, unsigned int i);
int				print_procent(t_var *pr);
void			putchar_width(int width, int len, char c);

#endif
