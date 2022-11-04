/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:46:02 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/04 16:02:20 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_add(t_args *arg, long long num)
{
	char	*str;
	int		slen;
	char	padding;

	str = ft_utoa_base(num, "0123456789abcdef");
	slen = (int)ft_strlen(str);
	padding = ' ';
	if (arg->zero)
	{
		padding = '0';
		arg->size += write(1, "0x", 2);
	}
	while (arg->width - slen - 2 > 0 && arg->width--)
		arg->size += write(1, &padding, 1);
	if (!arg->zero)
		arg->size += write(1, "0x", 2);
	arg->size += write(1, str, slen);
	free(str);
	while (arg->width + slen + 2 < 0 && arg->width++)
		arg->size += write(1, " ", 1);
	return (arg->size);
}
