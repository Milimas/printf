/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:40:28 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/04 04:36:02 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(t_args	*arg)
{
	if (!arg)
		return ;
	printf("=====================\nplus: %d\nminus: %d\nzero: %d\nspace: %d\nwidth: %d\ndot: %d\nprecision: %d\nhash: %d\ntype: %c\nsize: %zd\nformat: %s\n=====================\n",
			arg->plus,
			arg->minus,
			arg->zero,
			arg->space,
			arg->width,
			arg->dot,
			arg->precision,
			arg->hash,
			arg->type,
			arg->size,
			arg->format);
}
