/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 04:21:25 by dserrano          #+#    #+#             */
/*   Updated: 2026/03/03 20:58:57 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_parse_specifier(char specifier, t_buff *buff, va_list args)
{
	if ('c' == specifier)
		return (ft_print_char(buff, args));
	if ('s' == specifier)
		return (ft_print_str(buff, args));
	if ('p' == specifier)
		return (ft_print_ptr(buff, args));
	if ('d' == specifier || 'i' == specifier)
		return (ft_print_int(buff, args));
	if ('u' == specifier)
		return (ft_print_uint(buff, args));
	if ('x' == specifier || 'X' == specifier)
		return (ft_print_hex(buff, args, specifier));
	if ('%' == specifier)
	{
		if (-1 == ft_add_buff(specifier, buff))
			return (-1);
		return (0);
	}
	else
	{
		if (-1 == ft_add_buff('%', buff) || -1 == ft_add_buff(specifier, buff))
			return (-1);
		return (0);
	}
}
