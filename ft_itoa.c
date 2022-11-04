/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:56:18 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/04 16:13:31 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_digits(long n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*conv(long n)
{
	char	*s;
	size_t	size;

	size = ft_digits(n) + 1;
	s = (char *)ft_calloc(size, sizeof(char));
	if (!s)
		return (NULL);
	*s = '0';
	while (n)
	{
		s[--size - 1] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(long n)
{
	if (n < 0)
		n = -n;
	return (conv(n));
}
