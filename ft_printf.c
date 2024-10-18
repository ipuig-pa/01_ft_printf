/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:48:12 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/18 14:30:32 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

//#include "ft_printf.h"



static int	ft_putun_base_n(uintptr_t nb, int n, char *base)
{
	char	arr[32];
	int		j;
	int		printed_char;

	j = 0;
	printed_char = 0;
	if (nb == 0)
	{
		write(1, &base[0], 1);
		return (1);
	}
	while (nb != 0)
	{
		arr[j] = base[nb % n];
		nb = nb / n;
		j++;
	}
	printed_char = printed_char + j;
	j--;
	while (j >= 0)
	{
		write(1, &arr[j], 1);
		j--;
	}
	return (printed_char);
}

static int	is_valid_base(char *base, int n)
{
	int	actual_pos;
	int	other_previous_pos;

	actual_pos = 0;
	if (n <= 1)
		return (0);
	while (actual_pos < n)
	{
		if (base[actual_pos] == '-' || base[actual_pos] == '+')
			return (0);
		other_previous_pos = 0;
		while (other_previous_pos < actual_pos)
		{
			if (base[actual_pos] == base[other_previous_pos])
				return (0);
			other_previous_pos++;
		}
		actual_pos++;
	}
	return (1);
}

//using unitptr_t so can be used for all range of pointers int, non depending of the system (32- or 64-bits)
int	ft_putun_base(uintptr_t nbr, char *base)
{
	int	n;

	n = 0;
	if (!base)
		return (0);
	while (base[n] != '\0')
		n++;
	if (is_valid_base(base, n))
		return (ft_putun_base_n(nbr, n, base));
	return (0);
}



int	ft_putchar(char c)
{
	int	char_counter;

	write(1, &c, 1);
	char_counter = 1;
	return (char_counter);
}

int	ft_putstr(char *s)
{
	int	char_counter;

	if (!s)
		return (0);
	char_counter = ft_strlen(s);
	write(1, s, char_counter);
	return (char_counter);
}

int	ft_putptr(void *p)
{
	int			char_counter;
	uintptr_t	ptr;

	if (!p)
		return (ft_putstr("0x0"));
	ptr = (uintptr_t)p;
	char_counter = ft_putstr("0x");
	char_counter = char_counter + ft_putun_base(ptr, "0123456789abcdef");
	return (char_counter);
}

int	ft_putnbr(int n)
{
	long	n_c;
	int		printed_char;

	n_c = n;
	printed_char = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n_c = -n_c;
		printed_char = 1;
	}
	if (n_c >= 10)
	{
		printed_char = printed_char + ft_putnbr(n_c / 10);
	}
	printed_char++;
	ft_putchar('0' + n_c % 10);
	return (printed_char);
}


static int	write_arg(char specifier, va_list args)
{
	int	printed_char;

	if (specifier == 'c')
		printed_char = ft_putchar((char)va_arg (args, int));
	else if (specifier == 's')
		printed_char = ft_putstr(va_arg (args, char *));
	else if (specifier == 'p')
		printed_char = ft_putptr(va_arg (args, void *));
	else if (specifier == 'd' || specifier == 'i')
		printed_char = ft_putnbr(va_arg (args, int));
	else if (specifier == 'u')
		printed_char = ft_putun_base((uintptr_t)va_arg (args, unsigned int), "0123456789");
	else if (specifier == 'x')
		printed_char = ft_putun_base((uintptr_t)va_arg (args, unsigned int), "0123456789abcdef");
	else if (specifier == 'X')
		printed_char = ft_putun_base((uintptr_t)va_arg (args, unsigned int), "0123456789ABCDEF");
	else if (specifier == '%')
		printed_char = ft_putchar('%');
	else 
		printed_char = 0;
	return (printed_char);
}

//incloure on retornar error!

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_list	args_copy;
	int		i;
	int		printed_char;

	va_start(args, format);
	va_copy(args_copy, args);
	i = 0;
	printed_char = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed_char = printed_char + write_arg(format[i], args);
		}
		else
			printed_char = printed_char + ft_putchar(format[i]);
		i++;
	}
	va_end (args_copy);
	va_end (args);
	return (printed_char);
}

#include <stdio.h>

int	main(void)
{
	char				c = 'r';
	char				s[4] = "Hey";
	int					i = 32465442;
	unsigned int		u = 32465442;
	void				*p = (void *)s;

	printf("count: %i\n", printf("PRINTF:: c: %c, s: %s, p: %p, d: %d, i: %i, u: %u, x: %x, X: %X, %%,", c, s, p, i, i, u, u, u));
	ft_printf("count: %i\n", ft_printf("PRINTF:: c: %c, s: %s, p: %p, d: %d, i: %i, u: %u, x: %x, X: %X, %%,", c, s, p, i, i, u, u, u));
	return (0);
}
