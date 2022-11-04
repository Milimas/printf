/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:47:48 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/04 17:54:10 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char	padding;
	char	*prefix;

	str = get_x_base(arg->type, num, &prefix);
	slen = (int)ft_strlen(str);
	if (arg->dot && slen < arg->precision)
		arg->width = arg->precision;
	padding = ' ';
	if (arg->zero || arg->dot)
	{
		padding = '0';
		if (arg->hash && num != 0)
			arg->size += write(1, prefix, 2);
	}
	arg->size += print_seq(padding, arg->width - slen - !!arg->hash);
	if (!arg->zero && arg->hash && num != 0)
		arg->size += write(1, prefix, 2);
	arg->size += write(1, str, slen);
	free(str);
	arg->size += print_seq(padding, -arg->width - slen - !!arg->hash);
	return (arg->size);
}
