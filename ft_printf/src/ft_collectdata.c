/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectdata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:52:09 by rmarguri          #+#    #+#             */
/*   Updated: 2020/07/31 23:27:11 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		checkflag(t_flag *flag, const char *f, int i, va_list *args)
{
	while (f[i] == '0' || f[i] == '-' || f[i] == '*')
	{
		if (f[i] == '0')
			flag->zero_f = 1;
		if (f[i] == '-')
			flag->minus_f = 1;
		if (f[i] == '*')
			flag->width_f = va_arg(*args, int);
		i++;
	}
	return (i);
}

int		width(t_flag *flag, const char *f, int i)
{
	if (f[i] >= '0' && f[i] <= '9')
		flag->width_f = 0;
	while (f[i] >= '0' && f[i] <= '9')
	{
		flag->width_f *= 10;
		flag->width_f += f[i] - 48;
		i++;
	}
	if (f[i] == '\0')
		flag->width_f = 0;
	return (i);
}

int		accuracy(t_flag *flag, const char *f, int i, va_list *args)
{
	if (f[i] == '.' && f[i + 1] != '\0')
	{
		if (f[i + 1] == '*')
		{
			flag->accur_f = va_arg(*args, int);
			return (i + 2);
		}
		while (f[i] == '.')
		{
			flag->accur_f = 0;
			i++;
		}
		while (f[i] >= '0' && f[i] <= '9')
		{
			flag->accur_f *= 10;
			flag->accur_f += f[i] - 48;
			i++;
		}
	}
	return (i);
}

int		tspec(t_flag *flag, const char *f, int k)
{
	int i;

	i = 0;
	if (f[k] == '\0')
		return (k);
	while (flag->tspec[i] != '\0')
	{
		if (flag->tspec[i] == f[k])
			flag->tspec_f = i;
		i++;
	}
	return (k + 1);
}

void	funcs_init(int (*out_func[])(va_list*, t_flag))
{
	out_func[0] = output_char;
	out_func[1] = output_str;
	out_func[2] = output_p;
	out_func[3] = output_int;
	out_func[4] = output_int;
	out_func[5] = output_uint;
	out_func[6] = output_shex;
	out_func[7] = output_bhex;
	out_func[8] = output_pe;
}
