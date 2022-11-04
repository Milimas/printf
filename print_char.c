/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:44:03 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/04 04:59:53 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_args *arg, int c)
{
	char	padding;

	padding = ' ';
	if (arg->zero)
		padding = '0';
	while (arg->width - 1 > 0 && arg->width--)
		arg->size += write(1, &padding, 1);
	arg->size += write(1, &c, 1);
	while (arg->width + 1 < 0 && arg->width++)
		arg->size += write(1, " ", 1);
	return (arg->size);
}
