/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:37:32 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/15 03:06:59 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

class cantFindException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return("no occurence is found");
		}
};

template<typename T>
typename T::const_iterator easyfind(const T& container, const int a)
{
	typename T::const_iterator iter;
	iter = std::find(container.begin(), container.end(), a);
	if (iter == container.end())
		throw cantFindException();
	else
		return (iter);
}

template<typename T>
typename T::iterator easyfind(T& container, const int a)
{
	typename T::iterator iter;
	iter = std::find(container.begin(), container.end(), a);
	if (iter == container.end())
		throw cantFindException();
	else
		return (iter);
}


#endif