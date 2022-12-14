/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:38:37 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/07 02:45:20 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_args	*pre_parse_arg(t_args *arg, char *format)
{
	while (*(++format) && ft_strchr("-+0 #", *(format)))
	{
		arg->minus = 1 * (*format == '-' || arg->minus);
		arg->plus = 1 * (*format == '+' || arg->plus);
		arg->space = 1 * (*format == ' ' || arg->space);
		arg->zero = 1 * (*format == '0' || arg->zero);
		arg->hash = 1 * (*format == '#' || arg->hash);
	}
	arg->width = ft_atoi(format) * !!ft_isdigit(*format)
		* !(arg->zero && !arg->minus);
	arg->zero = (ft_atoi(format) * !arg->minus
			* !!ft_isdigit(*format)) * arg->zero;
	while (ft_isdigit(*format))
		format++;
	arg->format = format;
	return (arg);
}

t_args	*parse_arg(char *format)
{
	t_args	*arg;

	arg = create_arg();
	if (!arg)
		return (NULL);
	arg = pre_parse_arg(arg, format);
	format = arg->format;
	arg->dot = 1 * (*format == '.' && format++);
	arg->precision = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	while (*format && !arg->type && (*(format - 1) != ' '
			|| (ft_strchr("cspdiuxX%", *format) != NULL)))
	{
		arg->type = *format * (ft_strchr("cspdiuxX%", *format) != NULL);
		format++;
	}
	arg->format = format;
	if (ft_strchr("diuxX", arg->type))
	{
		arg->width = arg->zero * !!arg->dot + arg->width
			* (!arg->dot || !arg->zero);
		arg->zero = arg->zero * !arg->dot;
	}
	return (arg);
}
