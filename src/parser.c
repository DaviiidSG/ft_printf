/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:58:52 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/11 20:49:20 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	parse_specifier(char specifier, t_buff *buff, va_list args)
{
	if ('c' == specifier)
		insert_char(buff, args);
	else if ('s' == specifier)
		insert_str(buff, args);
	else if ('p' == specifier)
		insert_ptr(buff, args);
	else if ('d' == specifier || 'i' == specifier)
		insert_int(buff, args);
	else if ('u' == specifier)
		insert_uint(buff, args);
	else if ('x' == specifier || 'X' == specifier)
		insert_hex(buff, args, specifier);
	else if ('%' == specifier)
		buff_insert(buff, specifier);
	else
	{
		buff_insert(buff, '%');
		if (buff->err)
			return ;
		buff_insert(buff, specifier);
	}
}

void	parse_str(const char *str, t_buff *buff, va_list args)
{
	while (*str)
	{
		if ('%' == *str)
		{
			str++;
			if ('\0' == *str)
			{
				buff->err = 1;
				return ;
			}
			parse_specifier(*str, buff, args);
			if (buff->err)
				return ;
		}
		else
		{
			buff_insert(buff, *str);
			if (buff->err)
				return ;
		}
		str++;
	}
	return ;
}

void	tostr(unsigned long long n, t_buff *buff,
		char *base_template, unsigned int base)
{
	unsigned long long	num;

	if (n >= base)
	{
		tostr(n / base, buff, base_template, base);
		if (buff->err)
			return ;
	}
	num = n % base;
	buff_insert(buff, base_template[num]);
}
