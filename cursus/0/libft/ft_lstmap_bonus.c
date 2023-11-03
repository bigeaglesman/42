/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:10:41 by ycho2             #+#    #+#             */
/*   Updated: 2023/11/03 17:35:09 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**head;
	t_list	*temp_node;
	void	*temp_content;

	head = (t_list **)malloc(sizeof(t_list *));
	temp_node = NULL;
	*head = temp_node;
	while (lst)
	{
		temp_content = f(lst->content);
		temp_node = ft_lstnew(temp_content);
		if (temp_node == 0)
		{
			free(temp_content);
			ft_lstclear(head, del);
			return (0);
		}
		ft_lstadd_back(head, temp_node);
		lst = lst->next;
	}
	return (*head);
}
