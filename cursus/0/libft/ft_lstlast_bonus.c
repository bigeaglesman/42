/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:19:00 by ycho2             #+#    #+#             */
/*   Updated: 2023/10/31 20:04:12 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp_lst;

	temp_lst = lst;
	if (!temp_lst)
		return (0);
	while (temp_lst->next)
		temp_lst = temp_lst->next;
	return (temp_lst);
}
