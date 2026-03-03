/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:02:26 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/26 18:09:34 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hex(t_buff *buff, va_list args, char chr)
{
	unsigned int	num;

	num = va_arg(args, unsigned);
	if ('x' == chr)
		return (ft_tostr(num, buff, "0123456789abcdef", 16));
	else
		return (ft_tostr(num, buff, "0123456789ABCDEF", 16));
}
