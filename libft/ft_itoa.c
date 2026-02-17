/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:32:11 by dserrano          #+#    #+#             */
/*   Updated: 2026/01/29 15:23:51 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	count;

	if (!n)
		return (1);
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_fill_str(char *s, int digits, unsigned int is_negative, int n)
{
	if (is_negative)
	{
		s[digits + 1] = '\0';
		while (digits)
		{
			s[digits] = (n % 10) + '0';
			n /= 10;
			digits--;
		}
		s[0] = '-';
	}
	else
	{
		s[digits] = '\0';
		while (--digits >= 0)
		{
			s[digits] = (n % 10) + '0';
			n /= 10;
		}
	}
}

char	*ft_itoa(int n)
{
	int				digit_count;
	unsigned int	is_negative;
	char			*num_str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digit_count = ft_count_digits(n);
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
		num_str = malloc((digit_count + 2) * sizeof(*num_str));
	}
	else
		num_str = malloc((digit_count + 1) * sizeof(*num_str));
	if (!num_str)
		return (NULL);
	ft_fill_str(num_str, digit_count, is_negative, n);
	return (num_str);
}
