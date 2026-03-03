/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr_buff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:04:22 by dserrano          #+#    #+#             */
/*   Updated: 2026/03/02 14:26:49 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_addstr_buff(t_buff *buff, char const *str)
{
	while (*str)
	{
		if (-1 == ft_add_buff(*str, buff))
			return (-1);
		str++;
	}
	return (0);
}
