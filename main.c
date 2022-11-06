/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:20:11 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/06 07:00:58 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	ssize_t	printsize;

	(void)argc;
	(void)argv;
	char	format[] = "%48.12d";
	char	*arg = "asdfas";
	printsize = ft_printf (format, 0);
	printf("==> %zd", printsize);
	printf("\n");
	printsize = printf (format, 0);
	printf("==> %zd", printsize);
	(void)arg;
	(void)format;
	return (0);
}
/*
 * tested s c d i width width and minus and zero
 */
