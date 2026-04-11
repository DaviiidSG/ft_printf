/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:55:43 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/11 13:35:33 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

//! Cuando encuentra una conversión inválida o incompleta como "%t" ó "%" retorna error
//! Si falla un write retornar error inmediatamente

int	ft_printf(char const *str, ...)
{
	va_list	args;
	t_buff	buffer;

	if (!str)
		return (-1);
	buff_reset(&buffer);
	va_start(args, str);
	parse_str(str, &buffer, args);
	va_end(args);
	if (buffer.err)
		return (-1);
	write(1, buffer.data, buffer.index);
	return (buffer.total_len);
}
