/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:45:06 by ycho2             #+#    #+#             */
/*   Updated: 2023/10/13 13:13:09 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int val)
{
	int				i;
	unsigned char	temp_val;

	i = 0;
	while (str[i])
	{
		if (str[i] == temp_val)
			return (str + i);
		i++;
	}
	return (0);
}
