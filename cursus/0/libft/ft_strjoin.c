/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:50:18 by ycho2             #+#    #+#             */
/*   Updated: 2023/11/04 21:57:38 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;
	char	*concat_str;

	len = 0;
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	concat_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!concat_str)
		return (NULL);
	concat_str[0] = 0;
	ft_strlcat(concat_str, (char *)s1, len_s1 + 1);
	ft_strlcat(concat_str, (char *)s2, len_s1 + len_s2 + 1);
	return (concat_str);
}
