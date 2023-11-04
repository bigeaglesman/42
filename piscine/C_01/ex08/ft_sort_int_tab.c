/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:45:05 by ycho2             #+#    #+#             */
/*   Updated: 2023/08/27 15:50:52 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	swp;

	while (size > 1)
	{
		i = 0;
		while (i + 1 < size)
		{
			if (tab[i] >= tab[i + 1])
			{
				swp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swp;
			}
		i++;
		}
	size--;
	}
}