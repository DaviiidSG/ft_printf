/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helpers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 20:16:58 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/09 20:18:14 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_HELPERS_H
# define PRINTF_HELPERS_H
# include "ft_printf.h"

int		ft_parse_specifier(char specifier, t_buff *buff, va_list args);
int		ft_print_char(t_buff *buff, va_list args);
int		ft_print_str(t_buff *buff, va_list args);
int		ft_print_ptr(t_buff *buff, va_list args);
int		ft_tostr(unsigned long long n, t_buff *buff,
			char *base_template, unsigned int base);
int		ft_print_int(t_buff *buff, va_list args);
int		ft_print_uint(t_buff *buff, va_list args);
int		ft_print_hex(t_buff *buff, va_list args, char chr);

#endif
