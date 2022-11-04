/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:38:37 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/04 04:42:34 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_args	*parse_arg(char *format)
{
	t_args	*arg;

	arg = create_arg();
	while (*(++format) && ft_strchr("-+0 #", *(format)))
		if (*format == '-')
			arg->minus = -1;
	else if (*format == '+')
		arg->plus = 1;
	else if (*format == ' ')
		arg->space = 1;
	else if (*format == '0')
		arg->zero = 1;
	else if (*format == '#')
		arg->hash = 1;
	if (ft_isdigit(*format))
		arg->width = ft_atoi(format++) * arg->minus;
	while (ft_isdigit(*format))
		format++;
	if (*format == '.')
	{
		arg->dot = 1;
		arg->precision = ft_atoi(++format);
	}
	while (ft_isdigit(*format))
		format++;
	if (ft_strchr("cspdiuxX%", *format))
		arg->type = *format;
	arg->format = format + (*format != 0);
	return (arg);
}
