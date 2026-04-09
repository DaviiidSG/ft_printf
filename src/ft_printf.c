/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:55:43 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/09 18:56:35 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_search_specifier(const char *str, t_buff *buff, va_list args)
{
	while (*str)
	{
		if ('%' == *str)
		{
			if (*(str + 1))
				str++;
			else
			{
				if (-1 == ft_add_buff(*str, buff))
					return (-1);
				return (0);
			}
			if (-1 == ft_parse_specifier(*str, buff, args))
				return (-1);
		}
		else
		{
			if (-1 == ft_add_buff(*str, buff))
				return (-1);
		}
		str++;
	}
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	t_buff	buffer;

	if (!str)
		return (-1);
	va_start(args, str);
	if (-1 == ft_create_buff(&buffer, 64))
	{
		va_end(args);
		return (-1);
	}
	if (-1 == ft_search_specifier(str, &buffer, args))
	{
		va_end(args);
		free(buffer.data);
		return (-1);
	}
	va_end(args);
	write(1, buffer.data, buffer.data_len);
	free(buffer.data);
	return (buffer.data_len);
}
