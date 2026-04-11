/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:02:26 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/11 20:51:02 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	insert_hex(t_buff *buff, va_list args, char chr)
{
	unsigned int	num;

	num = va_arg(args, unsigned);
	if ('x' == chr)
	{
		tostr(num, buff, "0123456789abcdef", 16);
		return ;
	}
	else
	{
		tostr(num, buff, "0123456789ABCDEF", 16);
		return ;
	}
}
