/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 02:09:53 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/24 16:57:47 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_char(t_buff *buff, va_list args)
{
	int		c;

	c = va_arg(args, int);
	if (-1 == ft_add_buff(c, buff))
		return (-1);
	return (buff->data_len);
}
