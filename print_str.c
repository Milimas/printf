/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:45:29 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/04 18:11:24 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(t_args *arg, char *str)
{
	int		slen;
	char	padding;

	if (!str)
		str = "(null)";
	slen = (int)ft_strlen(str);
	if (arg->dot && slen > arg->precision)
		slen = arg->precision;
	padding = ' ';
	if (arg->zero)
		padding = '0';
	while (arg->width - slen > 0 && arg->width--)
		arg->size += write(1, &padding, 1);
	arg->size += write(1, str, slen);
	while (arg->width + slen < 0 && arg->width++)
		arg->size += write(1, " ", 1);
	return (arg->size);
}
