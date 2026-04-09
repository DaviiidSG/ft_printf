/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_buff.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:09:08 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/09 20:14:33 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_BUFF_H
# define INTERNAL_BUFF_H
# include "../ft_printf.h"

typedef struct s_buff
{
	char	*data;
	size_t	data_len;
}	t_buff;

int		create_buff(t_buff *buff);
int		add_buff(char chr, t_buff *buff);
int		addstr_buff(t_buff *buff, char const *str);
int		flush_buff(t_buff *buff);

#endif
