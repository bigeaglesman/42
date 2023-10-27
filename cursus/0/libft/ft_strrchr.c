/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:51:59 by ycho2             #+#    #+#             */
/*   Updated: 2023/10/20 15:11:35 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(char *str);

char	*strrchr(const char *str, int val)
{
	size_t			i;
	unsigned char	temp_val;

	temp_val = (unsigned char)val;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == temp_val)
			return (str + i);
		i--;
	}
	return (0);
}
