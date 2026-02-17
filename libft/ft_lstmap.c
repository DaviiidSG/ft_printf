/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:06:00 by dserrano          #+#    #+#             */
/*   Updated: 2026/02/02 19:31:51 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;
	void	*node_content;

	head = NULL;
	while (lst)
	{
		node_content = (*f)(lst->content);
		if (!node_content)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new_node = ft_lstnew(node_content);
		if (!new_node)
		{
			(*del)(node_content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
		lst = lst->next;
	}
	return (head);
}
