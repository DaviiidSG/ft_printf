/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:31:22 by dserrano          #+#    #+#             */
/*   Updated: 2026/01/23 16:46:27 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;

	if (!src && !dest)
		return (NULL);
	temp_dest = (unsigned char *)dest;
	temp_src = (const unsigned char *)src;
	if (temp_dest < temp_src)
	{
		while (n--)
		{
			*temp_dest++ = *temp_src++;
		}
	}
	else
	{
		while (n--)
		{
			temp_dest[n] = temp_src[n];
		}
	}
	return (dest);
}
