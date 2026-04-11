/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:23:33 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/11 13:35:26 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H
# define BUFF_SIZE 1024

# include "ft_printf.h"

typedef struct s_buff
{
	char	data[BUFF_SIZE];
	size_t	index;
	size_t	total_len;
	int		err;
}	t_buff;

void	parse_str(const char *str, t_buff *buff, va_list args);
void	buff_reset(t_buff *buff);
void	buff_join(t_buff *buff, char *temp_buff);
void	buff_addchr(t_buff *buff, char chr);
void	buff_join(t_buff *buff, char *temp_buff);

#endif
