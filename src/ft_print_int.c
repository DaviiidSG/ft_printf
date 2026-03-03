/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:36:20 by dserrano          #+#    #+#             */
/*   Updated: 2026/03/03 21:34:43 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_int(t_buff *buff, va_list args)
{
	int		num;

	num = va_arg(args, int);
	if (-2147483648 == num)
	{
		if (-1 == ft_addstr_buff(buff, "-2147483648"))
			return (-1);
		return (0);
	}
	else if (num < 0)
	{
		num = -num;
		if (-1 == ft_add_buff('-', buff))
			return (-1);
	}
	if (-1 == ft_tostr(num, buff, "0123456789", 10))
		return (-1);
	return (0);
}
