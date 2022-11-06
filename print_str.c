/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:45:29 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/06 11:19:49 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_arg(t_args *arg, char *str)
{
	int	slen;

	slen = ft_strlen(str);
	if (arg->dot && arg->precision < slen)
		slen = arg->precision;
	arg->width = (arg->width - slen) * (slen <= arg->width);
	arg->width *= arg->width >= 0;
	if (arg->minus)
		arg->width = -arg->width;
}

int	print_str(t_args *arg, char *str)
{
	int		slen;

	if (!str)
		str = "(null)";
	slen = (int)ft_strlen(str);
	if (arg->dot && arg->precision < slen)
		slen = arg->precision;
	process_arg(arg, str);
	arg->size += print_seq(' ', arg->width);
	arg->size += write(1, str, slen);
	arg->size += print_seq(' ', -arg->width);
	return (arg->size);
}
