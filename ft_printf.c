/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:06:35 by fmustin           #+#    #+#             */
/*   Updated: 2021/10/12 16:55:57 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_conversion(char c, va_list arg, int *len)
{
	char	ch;

	if (c == 'c')
	{
		ch = (char) va_arg(arg, int);
		write(1, &ch, 1);
		*len += 1;
	}
	else if (c == 's')
		*len += ft_convert_string(va_arg(arg, char *));
	else if (c == 'p')
		ft_convert_ptr((unsigned long int)va_arg(arg, void *), len);
	else if (c == 'd' || c == 'i')
		ft_convert_dec(va_arg(arg, int), len);
	else if (c == 'u')
		ft_convert_udec(va_arg(arg, unsigned int), len);
	else if (c == 'x')
		ft_convert_hex(va_arg(arg, unsigned int), 32, len);
	else if (c == 'X')
		ft_convert_hex(va_arg(arg, unsigned int), 0, len);
	else if (c == '%')
	{
		write(1, "%", 1);
		*len += 1;
	}
}

int	ft_printf(const char *c, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, c);
	while (c[i])
	{
		if (c[i] == '%')
		{
			i++;
			ft_check_conversion((char) c[i], arg, &len);
		}
		else
		{
			write(1, &c[i], 1);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
