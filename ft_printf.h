/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:59:37 by fmustin           #+#    #+#             */
/*   Updated: 2021/10/12 12:39:43 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *c, ...);
void	ft_check_conversion(char c, va_list arg, int *len);
void	ft_convert_dec(int n, int *len);
void	ft_convert_udec(unsigned int n, int *len);
int		ft_convert_string(char *s);
void	ft_convert_ptr(unsigned long int n, int *len);
void	ft_convert_hex(unsigned long int n, int a, int *len);

#endif
