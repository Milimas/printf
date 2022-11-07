/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:20:11 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/07 02:55:36 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	mainw()
{
	ssize_t	printsize;

	char	format[] = "%   ";
	char	*arg = "%d %s%";
	printsize = ft_printf (format, arg, 0);
	printf("==> %zd", printsize);
	printf("\n");
	printsize = printf (format, arg, 0);
	printf("==> %zd", printsize);
	(void)arg;
	(void)format;
	return (0);
}
int main(void)
{
	mainw();
}
/*
 *
 * tested s c d i width width and minus and zero
 */
