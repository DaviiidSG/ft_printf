/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:10:06 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/17 18:09:30 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(va_list args)
{
	void				*num;
	unsigned long long	mem_address;
	int					res;

	num = va_arg(args, void *);
	if (!num)
		return (write(1, "(nil)", 5));
	mem_address = (unsigned long long)num;
	res = write(1, "0x", 2);
	if (-1 == res)
		return (res);
	res += ft_putnbr_base(mem_address, "0123456789abcdef", 16, 0);
	return (res);
}
