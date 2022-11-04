/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:47:07 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/04 18:46:49 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(t_args *arg, int num)
{
	char	*str;
	int		slen;
	char	padding;
	char	sign;

	str = ft_itoa(num);
	if (num == 0 && arg->dot && !arg->precision)
		*str = 0;
	sign = '-';
	if (arg->plus && num >= 0)
		sign = '+';
	slen = (int)ft_strlen(str);
	padding = ' ';
	if (arg->zero || arg->dot)
		padding = '0';
	if ((num < 0 || arg->plus) && (arg->zero || arg->width < arg->precision))
		arg->size += write(1, &sign, 1);
	if (arg->space && num >= 0)
		arg->size += write(1, " ", 1);
	if (arg->dot)
	{
		arg->size += print_seq(' ', arg->width - arg->precision + !!arg->precision - slen - !!arg->space);
		arg->size += print_seq(padding, arg->precision - slen - !!arg->space);
	}
	else
		arg->size += print_seq(padding, arg->width - slen - (num < 0 || arg->plus) - !!arg->space);
	if (!arg->zero && arg->width >= arg->precision && (num < 0 || arg->plus))
		arg->size += write(1, &sign, 1);
	arg->size += write(1, str, slen);
	free(str);
	arg->size += print_seq(padding, -arg->width - slen - (num < 0 || arg->plus) - !!arg->space);
	return (arg->size);
}
