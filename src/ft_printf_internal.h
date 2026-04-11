/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:23:33 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/11 21:03:07 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H
# define BUFF_SIZE 1

# include "ft_printf.h"

typedef struct s_buff
{
	char	data[BUFF_SIZE];
	size_t	index;
	size_t	total_len;
	int		err;
}	t_buff;

void	parse_str(const char *str, t_buff *buff, va_list args);
void	buff_init(t_buff *buff);
void	buff_insert(t_buff *buff, int chr);
void	buff_join(t_buff *buff, char *temp_buff);
void	insert_char(t_buff *buff, va_list args);
void	insert_str(t_buff *buff, va_list args);
void	insert_ptr(t_buff *buff, va_list args);
void	insert_int(t_buff *buff, va_list args);
void	insert_uint(t_buff *buff, va_list args);
void	insert_hex(t_buff *buff, va_list args, char chr);
void	tostr(unsigned long long n, t_buff *buff,
			char *base_template, unsigned int base);

#endif
