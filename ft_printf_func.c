/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umsesiz <umsesiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:50:27 by umsesiz           #+#    #+#             */
/*   Updated: 2024/12/30 14:50:28 by umsesiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_is_str(char *str)
{
    int i;

    i = 0;
    if(!str)
        return (write(1, "(null)", 6));
    while(str[i])
        write(1, &str[i++], 1);
    return (i);
}

int ft_is_int(int x)
{
    int res;
    char digit;
    
    res = 0;
    if (x == 0)
        return (write(1, "0", 1));
    if (x == -2147483648)
        return (write (1, "-2147483648", 11));
    if (x < 0)
    {
        res += write(1, "-", 1);
        x = -x;
    }
    if (x >= 10)
        res += ft_is_int(x / 10);
    
    digit = "0123456789"[x % 10];
    res += write(1, &digit, 1);
    return (res);
}

int ft_is_unsigned(unsigned int x)
{
    int res;
    char digit;

    res = 0;
    if (x >= 10)
        res += ft_is_unsigned(x / 10);
    digit = "0123456789"[x % 10];
    res += write(1, &digit, 1);
    return (res);
}

int	ft_is_hex(unsigned int x, char c)
{
	int	res;
	char digit;

	res = 0;
	if (x >= 16)
		res += ft_is_hex(x / 16, c);
	if (c == 'x')
	{
		digit = "0123456789abcdef"[x % 16];
		res += write(1, &digit, 1);
	}
	else if (c == 'X')
	{
		digit = "0123456789ABCDEF"[x % 16];
		res += write(1, &digit, 1);
	}
	return (res);
}

int	ft_is_pointer(unsigned long x, int sign)
{
	int	res;
	char digit;

	res = 0;
	if (!x)
		return (write(1, "(nil)", 5));
	if (sign == 1)
		res += write(1, "0x", 2);
	if (x >= 16)
		res += ft_is_pointer(x / 16, 0);
	digit = "0123456789abcdef"[x % 16];
	res += write(1, &digit, 1);
	return (res);
}