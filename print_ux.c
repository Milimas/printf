/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:47:48 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/06 08:33:26 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_arg(t_args *arg, char *str)
{
	int	slen;

	slen = ft_strlen(str);
	arg->precision -= slen;
	arg->width =
		(arg->width - slen - arg->precision * (arg->precision > 0)
		- (2 * arg->hash * (arg->type != 'u'))) 
		* (slen <= arg->width);
	arg->width *= arg->width >= 0;
	if (arg->minus)
		arg->width = -arg->width;
	arg->zero = arg->zero - slen * !(!arg->dot && arg->precision > 0);
}

static char*	get_x_base(char type, unsigned long num,char **prefix)
{
	char	*str;

	*prefix = "0x";
	str = NULL;
	if (type == 'u')
		str = ft_itoa_base(num, "0123456789");
	else if (type == 'x')
		str = ft_itoa_base(num, "0123456789abcdef");
	else if (type == 'X')
	{
		str = ft_itoa_base(num, "0123456789ABCDEF");
		*prefix = "0X";
	}
	return (str);
}

int	print_ux(t_args *arg, unsigned long num)
{
	char	*str;
	int		slen;
	char	*prefix;

	str = get_x_base(arg->type, num, &prefix);
	slen = (int)ft_strlen(str);
	if (num == 0 && arg->dot && !arg->precision)
		*str = 0;
	process_arg(arg, str);
	arg->size += print_seq(' ', arg->width);
	arg->size += write(1, prefix, 2 * !!num * arg->hash * (arg->type != 'u'));
	arg->size += print_seq('0', arg->zero);
	arg->size += print_seq('0', arg->precision);
	arg->size += write(1, str, slen * !!(*str));
	free(str);
	arg->size += print_seq(' ', -arg->width);
	return (arg->size);
}
