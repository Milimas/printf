/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:07:39 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/06 22:51:35 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include <stdio.h>

typedef struct s_args
{
	unsigned int	minus;
	unsigned int	zero;
	unsigned int	dot;
	unsigned int	hash;
	unsigned int	space;
	unsigned int	plus;
	int				width;
	int				sign;
	int				precision;
	char			type;
	char			*format;
	size_t			size;
}	t_args;

t_args	*create_arg(void);
t_args	*parse_arg(char *format);

void	print_arg(t_args *arg);

int		print_char(t_args *arg, int c);
int		print_str(t_args *arg, char *str);
int		print_add(t_args *arg, long long num);
int		print_num(t_args *arg, int num);
int		print_ux(t_args *arg, unsigned long num);
int		print_seq(char c, int n);

char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
char	*ft_itoa(long n);
char	*ft_itoa_base(long long n, char *base);
char	*ft_utoa_base(unsigned long long n, char *base);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup(const char *s1);

int		ft_printf(const char *format, ...);

#endif
