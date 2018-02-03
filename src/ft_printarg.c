/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:51:01 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/07 16:51:04 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_printarg(t_flags *ptr, char **f, va_list arg)
{
	int ret;

	ret = 1;
	if (**f == '%')
		ft_putchar('%');
	else if (ft_strchr("pdDioOuUxX", **f))
		ret = ft_printnb(ptr, f, arg);
	else if (ft_strchr("SC", **f) || (ptr->l && ft_strchr("sc", **f)))
		ret = ft_unicode_s(ptr, f, arg);	
	else if (**f == 'c')
		ret = ft_printc(ptr, f, arg);
	else if (**f == 's')
		ret = ft_prints(ptr, f, arg);
	return (ret); //the number of read bytes
}
