/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:10:06 by dserrano          #+#    #+#             */
/*   Updated: 2026/03/01 03:32:30 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_ptr(t_buff *buff, va_list args)
{
	unsigned long long	mem_address;

	mem_address = (unsigned long long)va_arg(args, void *);
	if (!mem_address)
	{
		if (-1 == ft_addstr_buff(buff, "(nil)"))
			return (-1);
	}
	else
	{
		if (-1 == ft_addstr_buff(buff, "0x"))
			return (-1);
		if (-1 == ft_tostr(mem_address, buff, "0123456789abcdef", 16))
			return (-1);
	}
	return (0);
}
