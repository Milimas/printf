/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:47:07 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/06 11:18:40 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_arg(t_args *arg, char *str)
{
	int	slen;

	slen = ft_strlen(str);
	arg->precision -= slen;
	arg->width = (arg->width - arg->precision * (arg->precision > 0)
			- (arg->space || arg->sign || arg->plus) - slen)
		* (slen <= arg->width)
		* (arg->width > arg->precision);
	arg->width *= (arg->width >= 0);
	if (arg->minus)
		arg->width = -arg->width;
	arg->zero = arg->zero - slen
		* !(!arg->dot && arg->precision > 0)
		- (arg->space || arg->sign || arg->plus);
}

int	print_num(t_args *arg, int num)
{
	char	*str;
	int		slen;

	str = ft_itoa(num);
	slen = (int)ft_strlen(str);
	if (num == 0 && arg->dot && !arg->precision)
		*str = 0;
	arg->sign = (num < 0);
	process_arg(arg, str);
	arg->size += print_seq(' ', arg->width);
	arg->size += write(1, "-", !!arg->sign);
	arg->size += write(1, "+", !arg->sign * arg->plus);
	arg->size += write(1, " ", (arg->space && !arg->plus && !arg->sign));
	arg->size += print_seq('0', arg->precision);
	arg->size += print_seq('0', arg->zero);
	arg->size += write(1, str, slen * !!(*str));
	arg->size += print_seq(' ', -arg->width);
	free(str);
	return (arg->size);
}
