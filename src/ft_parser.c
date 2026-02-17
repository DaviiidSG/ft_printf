/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:12:04 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/18 00:11:21 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser(const char *str, int *i, va_list args)
{
	if ('c' == *(str + *i))
		return (ft_print_char(args));
	else if ('s' == *(str + *i))
		return (ft_print_str(args));
	else if ('p' == *(str + *i))
		return (ft_print_ptr(args));
	else if ('d' == *(str + *i) || 'i' == *(str + *i))
		return (ft_print_int(args));
	else if ('u' == *(str + *i))
		return (ft_print_uint(args));
	else if ('x' == *(str + *i) || 'X' == *(str + *i))
		return (ft_print_hex(args, *(str + *i)));
	else if ('%' == *(str + *i))
		return (1);
	else
	{
		(*i)--;
		return (write(1, str + *i, 1));
	}
}
