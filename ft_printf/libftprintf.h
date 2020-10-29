/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:57:02 by rmarguri          #+#    #+#             */
/*   Updated: 2020/08/01 16:07:31 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_flag
{
	int		minus_f;
	int		zero_f;
	int		width_f;
	int		accur_f;
	char	*tspec;
	int		tspec_f;
}				t_flag;

int				ft_printf(const char *f, ...);
int				ft_assemble(const char *f, int i, va_list *args);
int				ft_putstr(char *str, int n);
int				ft_putchar(char c);
int				ft_strlen(char *str);
int				ft_nbrlen(int n, int base);
int				ft_unbrlen(unsigned int n, int base);
int				ft_abs(int n);
int				ft_itoa_base(int n, int base, char	*digits);
int				ft_uitoa_base(unsigned int n, int base, char *digits);
int				output_char(va_list *args, t_flag flag);
int				output_str(va_list *args, t_flag flag);
int				output_int(va_list *args, t_flag flag);
int				output_uint(va_list *args, t_flag flag);
int				output_bhex(va_list *args, t_flag flag);
int				output_shex(va_list *args, t_flag flag);
int				output_p(va_list *args, t_flag flag);
int				output_pe(va_list *args, t_flag flag);
void			struct_init(t_flag *flag);
void			funcs_init(int	(*out_func[])(va_list*, t_flag));
int				accuracy(t_flag *flag, const char *f, int i, va_list *args);
int				width(t_flag *flag, const char *f, int i);
int				checkflag(t_flag *flag, const char *f, int i, va_list *args);
int				width(t_flag *flag, const char *f, int i);
int				accuracy(t_flag *flag, const char *f, int i, va_list *args);
int				tspec(t_flag *flag, const char *f, int k);
int				max(int a, int b);
int				min(int a, int b);
int				smash(int n);
int				spam(int l, char c);

#endif
