/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:56:18 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/04 16:11:20 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_digits(long long n, int blen)
{
	size_t	size;

	size = 0;
	if (n == 0)
		++size;
	while (n)
	{
		n /= blen;
		size++;
	}
	return (size);
}

static char	*conv(long long n, char *base)
{
	char	*s;
	size_t	size;
	int		blen;

	blen = ft_strlen(base);
	size = ft_digits(n, blen) + 1;
	s = (char *)ft_calloc(size, sizeof(char));
	if (!s)
		return (NULL);
	*s = '0';
	while (n)
	{
		s[--size - 1] = base[n % blen];
		n /= blen;
	}
	return (s);
}

char	*ft_itoa_base(long long n, char *base)
{
	if (n < 0)
		n = -n;
	return (conv(n, base));
}
