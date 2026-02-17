/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:24:48 by dserrano          #+#    #+#             */
/*   Updated: 2026/01/29 03:52:27 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static void	*ft_free_arr(char **arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**ft_fill_arr(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			arr[j] = ft_substr(s, start, i - start);
			if (!arr[j])
				return (ft_free_arr(arr, j));
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**words_arr;

	if (!s)
		return (NULL);
	words_arr = malloc((ft_count_words(s, c) + 1) * sizeof(*words_arr));
	if (!words_arr)
		return (NULL);
	return (ft_fill_arr(words_arr, s, c));
}
