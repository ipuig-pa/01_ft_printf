/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:48:12 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/18 12:17:47 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_arg(char specifier, va_list args)
{
	int	printed_char;

	if (specifier == 'c')
		printed_char = ft_putchar(va_arg (args, char));
	else if (specifier == 's')
		printed_char = ft_putstr(va_arg (args, char *));
	else if (specifier == 'p')
		printed_char = ft_putptr(va_arg (args, void *));
	else if (specifier == 'd' || specifier == 'i')
		printed_char = ft_putnbr(va_arg (args, int));
	else if (specifier == 'u')
		printed_char = ft_putun_base((uintptr_t)va_arg (args, unsigned int));
	else if (specifier == 'x')
		printed_char = ft_putun_base((uintptr_t)va_arg (args, unsigned int));
	else if (specifier == 'X')
		printed_char = ft_putun_base((uintptr_t)va_arg (args, unsigned int));
	else if (specifier == '%')
		printed_char = ft_putchar('%');
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
	while (fromat[i])
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
