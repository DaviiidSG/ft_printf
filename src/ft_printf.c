/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:55:43 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/18 16:16:50 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	t_buff	buffer;

	if (!str)
		return (-1);
	buff_init(&buffer);
	va_start(args, str);
	parse_str(str, &buffer, args);
	va_end(args);
	if (buffer.index)
	{
		if (-1 == write(1, buffer.data, buffer.index))
			return (-1);
	}
	if (buffer.err)
		return (-1);
	return (buffer.total_len);
}
