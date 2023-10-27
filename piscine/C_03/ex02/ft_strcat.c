/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:59:35 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/04 16:42:03 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	i = 0;
	dest_len = ft_strlen(dest);
	while (*(src + i))
	{
		*(dest + (dest_len + i)) = *(src + i);
		i++;
	}
	*(dest + (dest_len + i)) = 0;
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str [i] != '\0')
		i++;
	return (i);
}
