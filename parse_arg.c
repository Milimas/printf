/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:38:37 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/06 08:08:04 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_args	*parse_arg(char *format)
{
	t_args	*arg;

	arg = create_arg();
	while (*(++format) && ft_strchr("-+0 #", *(format)))
	{
		arg->minus = 1 * (*format == '-' || arg->minus);
		arg->plus = 1 * (*format == '+' || arg->plus);
		arg->space = 1 * (*format == ' ' || arg->space);
		arg->zero = 1 * (*format == '0' || arg->zero);
		arg->hash = 1 * (*format == '#' || arg->hash);
	}
	arg->width = ft_atoi(format) * !!ft_isdigit(*format) * !(arg->zero && !arg->minus);
	arg->zero = (ft_atoi(format) * !arg->minus * !!ft_isdigit(*format) - arg->space) * arg->zero;
	while (ft_isdigit(*format))
		format++;
	arg->dot = 1 * (*format == '.' && format++);
	arg->precision = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	arg->type = *format * (ft_strchr("cspdiuxX%", *format) != NULL);
	arg->format = format + (*format != 0);
	if (ft_strchr("di", arg->type))
	{
		arg->width = arg->zero * !!arg->dot + arg->width * (!arg->dot || !arg->zero);
		arg->zero = arg->zero * !arg->dot;
	}
	return (arg);
}
