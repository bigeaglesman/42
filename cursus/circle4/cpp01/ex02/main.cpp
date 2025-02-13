/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:47:54 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/31 01:37:13 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;
	
	std::cout<<"string address:		"<<&str<<std::endl;
	std::cout<<"stringPTR address:	"<<stringPTR<<std::endl;
	std::cout<<"stringREF address:	"<<&stringREF<<std::endl;
	std::cout<<std::endl;
	std::cout<<"string value:		"<<str<<std::endl;
	std::cout<<"stringPTR value:	"<<*stringPTR<<std::endl;
	std::cout<<"stringREF value:	"<<stringREF<<std::endl;
}