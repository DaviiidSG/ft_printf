/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:26:18 by dserrano          #+#    #+#             */
/*   Updated: 2026/01/21 17:36:11 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	dest = malloc((s_len + 1) * sizeof(*dest));
	if (!dest)
		return (NULL);
	i = 0;
	while (i <= s_len)
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}
