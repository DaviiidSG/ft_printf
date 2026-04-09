/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increment_buff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:41:55 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/09 18:37:46 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_increment_buff(t_buff *buff)
{
	char	*new_data;

	new_data = ft_calloc(buff->size * 2, sizeof(*(buff->data)));
	if (!new_data)
		return (-1);
	ft_memcpy(new_data, buff->data, buff->size);
	buff->size *= 2;
	free(buff->data);
	buff->data = new_data;
	return (buff->size);
}
