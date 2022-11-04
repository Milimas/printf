/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:29:17 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/04 15:55:31 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*d;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (!slen)
		return (ft_calloc(1, sizeof(char)));
	dup = malloc((slen + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	d = dup;
	while (*s)
		*d++ = *s++;
	*d = 0;
	return (dup);
}
