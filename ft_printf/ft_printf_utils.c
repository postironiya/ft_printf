/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 19:07:13 by rmarguri          #+#    #+#             */
/*   Updated: 2020/07/31 23:16:38 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	struct_init(t_flag *flag)
{
	flag->minus_f = 0;
	flag->zero_f = 0;
	flag->width_f = 0;
	flag->accur_f = -1;
	flag->tspec_f = -1;
	flag->tspec = "cspdiuxX%";
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *str, int n)
{
	int	i;

	if (n < 0)
		n = ft_strlen(str);
	i = 0;
	while (i < n && str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
