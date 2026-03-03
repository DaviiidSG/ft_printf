/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:33:09 by dserrano          #+#    #+#             */
/*   Updated: 2026/03/03 21:40:01 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_buff
{
	char	*data;
	size_t	data_len;
	size_t	size;
}	t_buff;

int		ft_printf(char const *str, ...);
int		ft_create_buff(t_buff *buff, size_t size);
int		ft_add_buff(char chr, t_buff *buff);
int		ft_addstr_buff(t_buff *buff, char const *str);
int		ft_increment_buff(t_buff *buff);
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
