/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:20:04 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/08 11:37:53 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& input)
{
	double val;
	char *ptr = NULL;
	try
	{
		val = std::strtod(input.c_str(), &ptr);
		if ()
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	

}