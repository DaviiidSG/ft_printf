/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 02:09:53 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/11 19:42:19 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	insert_char(t_buff *buff, va_list args)
{
	int	c;

	c = va_arg(args, int);
	buff_insert(buff, c);
}
