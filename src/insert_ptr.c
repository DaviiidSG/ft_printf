/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:10:06 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/11 20:47:55 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	insert_ptr(t_buff *buff, va_list args)
{
	unsigned long long	address;

	address = (unsigned long long)va_arg(args, void *);
	if (!address)
	{
		buff_join(buff, "(nil)");
		return ;
	}
	buff_join(buff, "0x");
	if (buff->err)
		return ;
	tostr(address, buff, "0123456789abcdef", 16);
}
