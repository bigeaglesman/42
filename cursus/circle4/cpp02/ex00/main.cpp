/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:39:34 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/14 15:01:01 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
  std::cout<<"default constructor called"<<std::endl;
  Fixed a;
  std::cout<<"copy constructor cadlled"<<std::endl;
  Fixed b( a );
  Fixed c;

  std::cout<<"getRawBits a called"<<std::endl;
  std::cout << a.getRawBits() << std::endl;
  std::cout<<"setRawBits b called"<<std::endl;
  b.setRawBits(10);
  std::cout << b.getRawBits() << std::endl;
  std::cout<<"copy assignment c = b operator called"<<std::endl;
  c = b;
  std::cout<<"getRawBits c called"<<std::endl;
  std::cout << c.getRawBits() << std::endl;

  return 0;
}