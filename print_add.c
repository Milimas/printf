/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:46:02 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/06 03:05:00 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_arg(t_args *arg, char *str)
{
	int	slen;

	slen = ft_strlen(str);
	if (arg->dot && arg->precision < slen)
		slen = arg->precision;
	arg->width =
		(arg->width - slen - 2) * (slen <= arg->width);
	arg->width *= arg->width >= 0;
	if (arg->minus)
		arg->width = -arg->width;
	arg->zero = arg->zero - slen * !(!arg->dot && arg->precision);
}

int	print_add(t_args *arg, long long num)
{
	char	*str;
	int		slen;

	str = ft_utoa_base(num, "0123456789abcdef");
	slen = (int)ft_strlen(str);
	process_arg(arg, str);
	arg->size += print_seq(' ', arg->width);
	arg->size += write(1, "0x", 2);
	print_seq('0', arg->zero);
	arg->size += write(1, str, slen);
	free(str);
	arg->size += print_seq(' ', -arg->width);
	return (arg->size);
}
