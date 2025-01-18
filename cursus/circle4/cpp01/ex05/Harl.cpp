/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:13:02 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/18 23:11:22 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::_debug(void)
{
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!"<<std::endl;
}

void Harl::_info(void)
{
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}

void Harl::_warning(void)
{
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."<<std::endl;
}

void Harl::_error(void)
{
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

Harl::Harl()
{

}

Harl::~Harl()
{
	
}

void Harl::complain(std::string level)
{

	void (Harl::*fun_ptr[4])() = {
		&Harl::_debug,
		&Harl::_warning,
		&Harl::_info,
		&Harl::_error
		};
	std::string fun_str[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
		};
	for (int i = 0; i < 4; i++)
	{
		if (level == fun_str[i])
		{
			(this->*fun_ptr[i])();
			break ;
		}
	}
}