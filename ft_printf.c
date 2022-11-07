/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:08:31 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/07 02:33:38 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_ft_printf(va_list ap, t_args *arg)
{
	int	size;

	size = 0;
	if (ft_strchr("c", arg->type))
		size += print_char(arg, va_arg(ap, int));
	if (ft_strchr("s", arg->type))
		size += print_str(arg, va_arg(ap, char *));
	if (ft_strchr("p", arg->type))
		size += print_add(arg, va_arg(ap, long long));
	if (ft_strchr("di", arg->type))
		size += print_num(arg, va_arg(ap, int));
	if (ft_strchr("uxX", arg->type))
		size += print_ux(arg, va_arg(ap, unsigned int));
	if (arg->type == '%')
		size += print_char(arg, '%');
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		size;
	t_args	*arg;
	va_list	ap;	

	va_start(ap, format);
	size = 0;
	while (format && *format)
	{
		if (*format && *format != '%')
			size += write(1, format++, 1);
		else
		{
			arg = parse_arg((char *)format);
			if (!arg)
				return (-1);
			format = arg->format;
			if (arg->type)
				size += _ft_printf(ap, arg);
			free(arg);
		}
	}
	va_end(ap);
	return (size);
}
