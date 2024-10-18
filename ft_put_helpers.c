/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:03:10 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/18 12:06:38 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char_counter = char_counter + ft_putnbr_base_n(ptr, "0123456789ABCDEF");
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
		ft_putnbr_fd(n_c / 10);
	}
	printed_char = printed_char + ft_putchar('0' + n_c % 10);
	return (printed_char);
}