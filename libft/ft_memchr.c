/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:57:28 by dserrano          #+#    #+#             */
/*   Updated: 2026/01/22 15:38:26 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp_s;
	size_t				i;

	temp_s = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (temp_s[i] == (unsigned char)c)
			return ((void *)(temp_s + i));
		i++;
	}
	return (NULL);
}
