/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:33:09 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/17 16:12:19 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_search_specifier(const char *str, va_list args);
int	ft_parser(const char *str, int *i, va_list args);
int	ft_print_char(va_list args);
int	ft_print_str(va_list args);
int	ft_print_ptr(va_list args);
int	ft_putnbr_base(unsigned long long num, char *base_template,
		unsigned int base, unsigned int sign);

#endif
