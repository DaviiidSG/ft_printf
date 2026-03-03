/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_buff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:34:27 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/25 13:23:12 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_create_buff(t_buff *buff, size_t size)
{
	buff->data = ft_calloc(size, sizeof(*(buff->data)));
	if (!(buff->data))
		return (-1);
	buff->size = size;
	buff->data_len = 0;
	return (buff->size);
}
