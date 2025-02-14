/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:30:56 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/14 14:14:28 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _value;
		static const int _1bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& original);
		Fixed& operator=(const Fixed& oringal);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif