/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:13:52 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/24 17:01:47 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_add_buff(char chr, t_buff *buff)
{
	if (buff->data_len + 1 == buff->size)
		if (-1 == ft_increment_buff(buff))
			return (-1);
	buff->data[buff->data_len] = chr;
	buff->data_len++;
	return (buff->data_len);
}
