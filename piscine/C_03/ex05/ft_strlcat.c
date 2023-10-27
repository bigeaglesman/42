/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:47:09 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/04 19:07:20 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	i = 0;
	src_len = ft_strlen(src);
	if (dest_len >= size)
		return (src_len + size);
	else
	{
		while (i + dest_len + 1 < size && *(src + i))
		{
			*(dest + dest_len + i) = *(src + i);
			i++;
		}
		*(dest + dest_len + i) = 0;
		return (src_len + dest_len);
	}
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
