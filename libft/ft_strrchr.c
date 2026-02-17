/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:24:02 by dserrano          #+#    #+#             */
/*   Updated: 2026/01/18 00:27:53 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			s_len;
	unsigned char	chr;

	s_len = ft_strlen(s);
	chr = (unsigned char)c;
	while (s_len > 0 && s[s_len] != chr)
		s_len--;
	if (s[s_len] == chr)
		return ((char *)(s + s_len));
	return (NULL);
}
