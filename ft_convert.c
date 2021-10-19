/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:09:16 by fmustin           #+#    #+#             */
/*   Updated: 2021/10/12 12:44:53 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}

void	ft_convert_dec(int n, int *len)
{
	char			nb;
	unsigned int	un;

	if (n < 0)
	{
		un = (unsigned int)(n * -1);
		write(1, "-", 1);
		*len += 1;
	}
	else
		un = (unsigned int) n;
	if (un < 10)
	{
		nb = un + '0';
		write(1, &nb, 1);
		*len += 1;
	}
	else
	{
		ft_convert_dec(un / 10, len);
		nb = (un % 10) + '0';
		write(1, &nb, 1);
		*len += 1;
	}
}

void	ft_convert_udec(unsigned int n, int *len)
{
	char	nb;

	if (n < 10)
	{
		nb = n + '0';
		write(1, &nb, 1);
		*len += 1;
	}
	else
	{
		ft_convert_udec(n / 10, len);
		nb = (n % 10) + '0';
		write(1, &nb, 1);
		*len += 1;
	}
}

void	ft_convert_ptr(unsigned long int n, int *len)
{
	write(1, "0x", 2);
	*len += 2;
	ft_convert_hex(n, 32, len);
}

void	ft_convert_hex(unsigned long int n, int a, int *len)
{
	char	nb;

	if (n >= 16)
	{
		ft_convert_hex(n / 16, a, len);
		ft_convert_hex(n % 16, a, len);
	}
	else if (n < 10)
	{
		nb = n + '0';
		write(1, &nb, 1);
		*len += 1;
	}
	else
	{
		nb = n + '0' + 7 + a;
		write(1, &nb, 1);
		*len += 1;
	}
}
