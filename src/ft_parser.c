/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:12:04 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/16 17:17:22 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser(const char *str, int *i, va_list args)
{
	if (*(str + *i) == 'c')
		return (ft_print_char(args));
	else if (*(str + *i) == 's')
		return (ft_print_str(args));
	else if (*(str + *i) == 'p')
		return (ft_print_ptr(args));
	else if (*(str + *i) == 'd' || *(str + *i) == 'i')
		return (1);
	else if (*(str + *i) == 'u')
		return (1);
	else if (*(str + *i) == 'x' || *(str + *i) == 'X')
		return (1);
	else if (*(str + *i) == '%')
		return (1);
	else
	{
		(*i)--;
		return (write(1, str + *i, 1));
	}
}
