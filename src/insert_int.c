/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:36:20 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/11 20:55:44 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	insert_int(t_buff *buff, va_list args)
{
	int		num;

	num = va_arg(args, int);
	if (-2147483648 == num)
	{
		buff_join(buff, "-2147483648");
		return ;
	}
	else if (num < 0)
	{
		num = -num;
		buff_insert(buff, '-');
		if (buff->err)
			return ;
	}
	tostr(num, buff, "0123456789", 10);
}
