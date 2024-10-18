/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:03:10 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/18 16:44:29 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	char_counter;

	char_counter = write(1, &c, 1);
	return (char_counter);
}

int	ft_putstr(char *s)
{
	int	char_counter;

	if (!s)
		char_counter = write(1, "(null)", 6);
	else
		char_counter = write(1, s, ft_strlen(s));
	return (char_counter);
}

int	ft_putptr(void *p)
{
	int			char_counter;
	uintptr_t	ptr;

	if (!p)
		return (ft_putstr("0x0"));
	ptr = (uintptr_t)p;
	char_counter = ft_putstr("0x") + ft_putun_base(ptr, "0123456789abcdef");
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
		printed_char = write(1, "-", 1);
		n_c = -n_c;
	}
	if (n_c >= 10)
	{
		printed_char = printed_char + ft_putnbr(n_c / 10);
	}
	printed_char = printed_char + ft_putchar('0' + n_c % 10);
	return (printed_char);
}
