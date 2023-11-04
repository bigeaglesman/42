/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:43:52 by ycho2             #+#    #+#             */
/*   Updated: 2023/08/27 17:33:37 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int*a, int*b)
{
	int	div_a;
	int	div_b;

	div_a = *a;
	div_b = *b;
	*a = div_a / div_b;
	*b = div_a % div_b;
}