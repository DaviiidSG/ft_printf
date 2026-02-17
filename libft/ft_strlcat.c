/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:15:22 by dserrano          #+#    #+#             */
/*   Updated: 2026/01/25 16:13:11 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dst_len;
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dsize == 0)
		return (src_len);
	dst_len = 0;
	while (dst_len < dsize && dst[dst_len])
		dst_len++;
	if (dst_len < dsize)
	{
		i = 0;
		while (i < src_len && dst_len + i < dsize - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	return (src_len + dst_len);
}
