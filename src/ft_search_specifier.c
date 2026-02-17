/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:09:19 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/17 18:08:50 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_specifier(const char *str, va_list args)
{
	int	i;
	int	bytes;
	int	total_bytes;

	i = 0;
	total_bytes = 0;
	while (str[i])
	{
		if ('%' == str[i])
		{
			i++;
			bytes = ft_parser(str, &i, args);
		}
		else
			bytes = write(1, str + i, 1);
		if (-1 == bytes)
			return (bytes);
		total_bytes += bytes;
		i++;
	}
	return (total_bytes);
}
