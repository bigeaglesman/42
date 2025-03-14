/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:16:35 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/14 23:47:50 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

namespace ft
{
	template <typename T>
	void swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <typename T>
	T min(const T& a, const T& b)
	{
		if (a < b)
			return (a);
		else
			return (b);
	}

	template <typename T>
	T max(const T& a, const T& b)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
}

#endif