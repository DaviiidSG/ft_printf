/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:53:42 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/18 00:29:01 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned);
	return (ft_putnbr_base(num, "0123456789", 10, 0));
}
