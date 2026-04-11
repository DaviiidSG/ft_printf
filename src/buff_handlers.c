/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:13:52 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/11 13:35:47 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	buff_reset(t_buff *buff)
{
	buff->index = 0;
	buff->total_len = 0;
	buff->err = 0;
}

void	flush(t_buff *buff)
{
	ssize_t	bytes;

	bytes = write(1, buff->data, buff->index);
	if (-1 == bytes)
	{
		buff->err = 1;
		return;
	}
	buff_reset(buff);
}

void	buff_addchr(t_buff *buff, char chr)
{
	if (BUFF_SIZE == buff->index)
	{
		flush(buff);
		if (buff->err)
			return;
	}
	buff->data[buff->index] = chr;
	buff->index++;
	buff->total_len++;
}

void	buff_join(t_buff *buff, char *temp_buff)
{
	while (*temp_buff)
	{
		buff_addchr(buff, *temp_buff);
		if (buff->err)
			return;
		temp_buff++;
	}
	
}
