/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 05:23:08 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/17 17:53:51 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long num, char *base_template,
		unsigned int base, unsigned int sign)
{
	int	total_bytes;
	int	byte;
	int	digit;

	total_bytes = 0;
	if (sign)
	{
		byte = write(1, "-", 1);
		if (-1 == byte)
			return (byte);
		total_bytes += byte;
	}
	if (num >= base)
	{
		byte = ft_putnbr_base(num / base, base_template, base, 0);
		if (-1 == byte)
			return (byte);
		total_bytes += byte;
	}
	digit = num % base;
	byte = write(1, base_template + digit, 1);
	if (-1 == byte)
		return (byte);
	total_bytes += byte;
	return (total_bytes);
}
