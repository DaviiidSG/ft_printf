/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:13:52 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/18 16:34:24 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	buff_init(t_buff *buff)
{
	buff->index = 0;
	buff->total_len = 0;
	buff->err = 0;
}

static void	flush(t_buff *buff)
{
	if (-1 == write(1, buff->data, buff->index))
	{
		buff->err = 1;
		return ;
	}
	buff->index = 0;
}

void	buff_insert(t_buff *buff, int chr)
{
	if (BUFF_SIZE == buff->index)
	{
		flush(buff);
		if (buff->err)
			return ;
	}
	buff->data[buff->index] = chr;
	buff->index++;
	buff->total_len++;
}

void	buff_join(t_buff *buff, char *temp_buff)
{
	while (*temp_buff)
	{
		buff_insert(buff, *temp_buff);
		if (buff->err)
			return ;
		temp_buff++;
	}
}
