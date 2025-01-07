/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umsesiz <umsesiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:50:32 by umsesiz           #+#    #+#             */
/*   Updated: 2024/12/30 14:50:33 by umsesiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static  int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int ft_format(va_list *args, char c)
{
    if (c == 'u')
        return (ft_is_unsigned(va_arg((*args), unsigned int)));
    else if (c == 'c')
        return (ft_putchar(va_arg((*args), int)));
    else if (c == 'i' || c == 'd')
        return (ft_is_int(va_arg((*args), int)));
    else if (c == 'x' || c == 'X')
        return (ft_is_hex(va_arg((*args), unsigned int), c));
    else if (c == 'p')
        return (ft_is_pointer(va_arg((*args), unsigned long), 1));
    else if (c == 's')
        return (ft_is_str(va_arg((*args), char *)));
    else if (c == '%')
        return (ft_putchar('%'));
    return (0);
}

int ft_printf(const char *input, ...)
{
    va_list args;
    int i;
    int len;

    i = 0;
    len = 0;
    va_start(args, input);
    
    while (input[i])
    {
        if (input[i] == '%')
        {
            len += ft_format(&args, input[i + 1]);
            i++;
        }
        else
            len += ft_putchar(input[i]);
        i++;
    }
    va_end(args);
    return (len);
}