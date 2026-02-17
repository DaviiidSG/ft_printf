/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:34:17 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/01 19:08:36 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt_node;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		nxt_node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nxt_node;
	}
	*lst = NULL;
}
