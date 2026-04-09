/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_buff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:34:27 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/09 20:14:13 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	create_buff(t_buff *buff)
{
	buff->data = ft_calloc(256, sizeof(*(buff->data)));
	if (!(buff->data))
		return (-1);
	buff->data_len = 0;
	return (0);
}

int	flush_buff(t_buff *buff)
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

int	ft_add_buff(char chr, t_buff *buff)
{
	if (buff->data_len + 1 == buff->size)
		if (-1 == ft_increment_buff(buff))
			return (-1);
	buff->data[buff->data_len] = chr;
	buff->data_len++;
	return (buff->data_len);
}

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
