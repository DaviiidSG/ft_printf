/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:55:43 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/16 16:27:17 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		res;

	va_start(args, str);
	res = ft_search_specifier(str, args);
	va_end(args);
	return (res);
}
