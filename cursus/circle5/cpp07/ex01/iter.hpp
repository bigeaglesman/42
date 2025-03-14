/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:55:06 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/14 16:48:42 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *arr, int arr_len, void (*func)(T&))
{
	for (int i = 0; i < arr_len; i++)
		func(arr[i]);
}


#endif