/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:09:45 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/26 17:54:32 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_tostr(unsigned long long n, t_buff *buff,
		char *base_template, unsigned int base)
{
	unsigned long long	num;

	if (n >= base)
	{
		if (-1 == ft_tostr(n / base, buff, base_template, base))
			return (-1);
	}
	num = n % base;
	if (-1 == ft_add_buff(base_template[num], buff))
		return (-1);
	return (0);
}
