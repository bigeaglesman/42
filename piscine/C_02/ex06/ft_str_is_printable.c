/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:22:54 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/02 14:50:34 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	ret;
	int	i;

	i = 0;
	ret = 1;
	while (*(str + i))
	{
		if (!(*(str + i) >= 32 && *(str + i) <= 126))
			ret = 0;
		i++;
	}
	return (ret);
}