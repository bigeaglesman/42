/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 03:40:57 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/15 06:09:32 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	desc;
	int	asc;

	i = 0;
	desc = 0;
	asc = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			asc++;
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			desc++;
		i++;
	}
	if (desc == i || asc == i)
		return (1);
	else
		return (0);
}
