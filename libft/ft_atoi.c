/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:59:11 by dserrano          #+#    #+#             */
/*   Updated: 2026/01/26 20:03:53 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	unsigned int	res_num;
	int				is_negative;
	size_t			i;

	res_num = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	is_negative = 0;
	if (nptr[i] == '-')
	{
		is_negative = 1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		res_num = res_num * 10 + (nptr[i] - '0');
		i++;
	}
	if (is_negative)
		res_num = -res_num;
	return ((int)res_num);
}
