/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:29:51 by dserrano          #+#    #+#             */
/*   Updated: 2026/01/25 15:33:43 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const unsigned char	*temp_big;
	const unsigned char	*temp_little;
	size_t				i;
	size_t				j;

	temp_big = (const unsigned char *)big;
	temp_little = (const unsigned char *)little;
	if (!temp_little[0])
		return ((char *)temp_big);
	i = 0;
	while (i < len && temp_big[i])
	{
		if (temp_big[i] == temp_little[0])
		{
			j = 0;
			while (i + j < len && temp_big[i + j] == temp_little[j])
			{
				if (!temp_little[j + 1])
					return ((char *)(temp_big + i));
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
