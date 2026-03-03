/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:53:42 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/26 18:09:28 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_uint(t_buff *buff, va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned);
	return (ft_tostr(num, buff, "0123456789", 10));
}
