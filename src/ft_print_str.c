/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:04:56 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/16 19:56:44 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(va_list args)
{
	char	*str;
	size_t	slen;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	slen = ft_strlen(str);
	return (write(1, str, slen));
}
