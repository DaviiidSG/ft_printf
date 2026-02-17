/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:02:26 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/18 00:28:42 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(va_list args, char chr)
{
	unsigned int	num;

	num = va_arg(args, unsigned);
	if ('x' == chr)
		return (ft_putnbr_base(num, "0123456789abcdef", 16, 0));
	else
		return (ft_putnbr_base(num, "0123456789ABCDEF", 16, 0));
}
