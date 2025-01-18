/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:00:27 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/18 23:10:49 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;
	std::cout<<"DEBUG: ";
	harl.complain("DEBUG");
	std::cout<<"INFO: ";
	harl.complain("INFO");
	std::cout<<"WARNING: ";
	harl.complain("WARNING");
	std::cout<<"ERROR: ";
	harl.complain("ERROR");
}