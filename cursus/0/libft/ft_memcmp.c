/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:25:38 by ycho2             #+#    #+#             */
/*   Updated: 2023/10/13 13:43:06 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*temp_ptr1;
	const unsigned char	*temp_ptr2;
	size_t				i;

	i == 0;
	temp_ptr1 = (const unsigned char *)ptr1;
	temp_ptr2 = (const unsigned char *)ptr2;
	while (num > i)
	{
		if (temp_ptr1[i] != temp_ptr2[i])
		{
			if (temp_ptr1[i] > temp_ptr2[i])
				return (temp_ptr1[i] - temp_ptr2[i]);
		}
		else
			return (temp_ptr2[i] - temp_ptr1[i]);
		i++;
	}
	return (0);
}
