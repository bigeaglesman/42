/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:58:12 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/17 22:15:04 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack()
		{
			std::cout<<"MutantStack default constructor called"<<std::endl;
		}

		~MutantStack()
		{
			std::cout<<"MutantStack destructor called"<<std::endl;
		}

		MutantStack& operator=(const MutantStack& original)
		{
			std::cout<<"MutantStack copy assignmnet operator called"<<std::endl;
			if (this != &original)
				std::stack<T>::operator=(original);
			return (*this);
		}

		MutantStack(const MutantStack& original)
		{
			std::cout<<"MutantStack copy constructor called"<<std::endl;
			*this = original;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin()
		{
			return (std::stack<T>::c.begin());
		}
		 
		iterator end()
		{
			return (std::stack<T>::c.end());
		}

		const_iterator begin() const
		{
			return (std::stack<T>::c.begin());
		}

		const_iterator end() const
		{
			return (std::stack<T>::c.end());
		}

		reverse_iterator rbegin()
		{
			return (std::stack<T>::c.rbegin());
		}

		reverse_iterator rend()
		{
			return (std::stack<T>::c.rend());
		}

		const_reverse_iterator rbegin() const
		{
			return (std::stack<T>::c.rbegin());
		}
		const_reverse_iterator rend() const
		{
			return (std::stack<T>::c.rend());
		}
};

#endif