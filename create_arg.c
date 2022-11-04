/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:36:46 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/04 04:33:13 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_args	*create_arg(void)
{
	t_args	*arg;

	arg = malloc(sizeof(t_args));
	arg->minus = 1;
	arg->zero = 0;
	arg->dot = 0;
	arg->hash = 0;
	arg->space = 0;
	arg->plus = 0;
	arg->width = 0;
	arg->precision = -1;
	arg->type = 0;
	arg->format = NULL;
	arg->size = 0;
	return (arg);
}
