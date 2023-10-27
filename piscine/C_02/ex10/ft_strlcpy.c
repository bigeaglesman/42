/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:20:05 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/03 13:11:44 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *src);

unsigned	int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*(src + i) && (i + 1) < size)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = 0;
	return (ft_strlen(src));
}

int	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	while (*(src + i))
		i++;
	return (i);
}
