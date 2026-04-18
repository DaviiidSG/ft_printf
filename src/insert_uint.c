/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:53:42 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/11 19:17:22 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	insert_uint(t_buff *buff, va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned);
	tostr(num, buff, "0123456789", 10);
}
