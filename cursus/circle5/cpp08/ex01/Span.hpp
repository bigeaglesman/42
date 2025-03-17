/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:06:18 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/17 15:45:10 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>

class Span
{
	private:
		std::vector<int> _arr;
		unsigned int _arr_len;
		Span();
	public:
		~Span();
		Span(const Span& original);
		Span& operator=(const Span& original);
	
		std::vector<int> getArr() const;
		unsigned int getArrLen() const;
		Span(const unsigned int& len);
		void addNumber(int n);
		void addNumber(const std::vector<int>::iterator begin, const std::vector<int>::iterator end);
		int shortestSpan() const;
		int longestSpan() const;

		class arrOverException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class arrShortException : public std::exception
		{
			public:
				const char* what() const throw();
		};
}; 

#endif