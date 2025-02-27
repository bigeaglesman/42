/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:08:59 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/28 01:29:17 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
	std::cout<<"##TEST1: Copy constructor test"<<std::endl;


	std::cout<<"##TEST2: ShrubberyCreationForm test"<<std::endl;
	ShrubberyCreationForm shrub("shrub");
	Bureaucrat shrubBureaucrat("shrubBureaucrat", 138);

	shrubBureaucrat.executeForm(shrub);
	std::cout<<std::endl<<std::endl;


}