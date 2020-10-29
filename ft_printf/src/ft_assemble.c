/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 15:47:34 by rmarguri          #+#    #+#             */
/*   Updated: 2020/08/01 18:49:55 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	ft_movei(int i, t_flag *flag, va_list *args, const char *f)
{
	i = checkflag(flag, f, i + 1, args);
	i = width(flag, f, i);
	i = accuracy(flag, f, i, args);
	i = tspec(flag, f, i);
	return (i);
}

static int	ft_normis(const char *f, int *i)
{
	write(1, &f[*i], 1);
	*i = *i + 1;
	return (1);
}

static int	ft_unikalich(va_list *args, t_flag flag)
{
	int		c;
	int		(*out_func[9])(va_list*, t_flag);

	c = 0;
	funcs_init(out_func);
	if (flag.tspec_f != -1)
		c = out_func[flag.tspec_f](args, flag);
	return (c);
}

int			ft_assemble(const char *f, int i, va_list *args)
{
	t_flag	flag;
	int		c;

	c = 0;
	while (f[i] != '\0')
	{
		struct_init(&flag);
		if (f[i] == '%' && f[i + 1] != '\0')
		{
			i = ft_movei(i, &flag, args, f);
			c += ft_unikalich(args, flag);
		}
		else
			c += ft_normis(f, &i);
	}
	return (c);
}
