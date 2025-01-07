/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umsesiz <umsesiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:50:37 by umsesiz           #+#    #+#             */
/*   Updated: 2024/12/30 14:50:38 by umsesiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *input, ...);
int	ft_format(va_list *args, char c);
int	ft_is_str(char *str);
int	ft_is_int(int x);
int	ft_is_unsigned(unsigned int x);
int	ft_is_hex(unsigned int x, char c);
int	ft_is_pointer(unsigned long x, int sign);

#endif