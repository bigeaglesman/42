/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:08:30 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/15 00:26:47 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T* _arr;
		unsigned int _size;
	public:
		Array()
		:_arr(NULL), _size(0)
		{
			std::cout<<"Array default constructor called"<<std::endl;
		}

		Array(unsigned int n)
		:_size(n)
		{
			std::cout<<"Array size constructor called"<<std::endl;
			if (n == 0)
				_arr = NULL;
			else
				_arr = new T[n];
		}

		Array(const Array<T> &original)
		{
			std::cout<<"Array copy constructor called"<<std::endl;
			*this = original;
		}

		Array<T>& operator=(const Array<T>& original)
		{
			std::cout<<"Array copy assignment operator called"<<std::endl;
			if (this != &original)
			{
				if (this ->_size != 0)
					delete[] (this->_arr);
				this -> _size = original.size();
				if (this -> _size == 0)
					_arr = NULL;
				else
				{
					this -> _arr = new T[this->_size];
					for (unsigned int i = 0; i < this->_size; i++)
						this->_arr[i] = original[i];
				}
			}
			return (*this);
		}

		T& operator[](unsigned int i)
		{
			if (i >= this->_size)
				throw InvalidIndexException();
			else
				return (this->_arr[i]);
		}

		const T& operator[](unsigned int i) const
		{
			if (i >= this->_size)
				throw InvalidIndexException();
			else
				return (this->_arr[i]);
		}

		~Array()
		{
			std::cout<<"Array default destructor called"<<std::endl;
			delete[] (this->_arr);
		}

		unsigned int size() const
		{
			return (this->_size);
		}
		
		class InvalidIndexException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

template<typename T>
const char* Array<T>::InvalidIndexException::what() const throw()
{
	return("Invalid Index");
}

#endif
