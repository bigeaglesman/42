/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:40:21 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/14 23:48:21 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main( void ) 
{
	int a = 2;
	int b = 3;
	
	ft::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ft::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ft::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	ft::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ft::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ft::max( c, d ) << std::endl;
	return 0;
}