/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:48:12 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/16 15:47:42 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	write_arg(char	specifier, va_list args)
{
	if (specifier == 'c')
		ft_putchar_fd(va_arg (args, char), 1);
	else if (specifier == 's')
		ft_putstr_fd(va_arg (args, char *, 1));
	else if (specifier == 'p')
		(va_arg (args, void *, 1));
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr_fd(va_arg (args, int, 1));
	else if (specifier == 'u')
	else if (specifier == 'x')
	else if (specifier == 'X')
	else if (specifier == '%')

	va_arg (args, char *);
	va_arg (args, void *);
	va_arg (args, int);
	va_arg (args, int);
	va_arg (args, unsigned int);
	va_arg (args, int);
	va_arg (args, int);
	va_arg (args, char);

}

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
		{
			ft_putchar_fd(format[i], 1);
			printed_char++;
		}
		i++;
	}
	va_end (args_copy);
	va_end (args);
}
