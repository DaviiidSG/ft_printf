/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:36:20 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/17 18:46:53 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list args)
{
	int	num;
	int	sign;

	num = va_arg(args, int);
	if (-2147483648 == num)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		num = -num;
		sign = 1;
	}
	return (ft_putnbr_base(num, "0123456789", 10, sign));
}
