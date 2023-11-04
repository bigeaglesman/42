/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:44:42 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/02 16:58:23 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	ret;
	int	i;

	i = 0;
	ret = 1;
	while (*(str + i))
	{
		if (!(*(str + i) >= 'A' && *(str + i) <= 'Z'))
			ret = 0;
		i++;
	}
	return (ret);
}