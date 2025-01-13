/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:04:50 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/13 11:49:22 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	_num_contact = 0;
}

PhoneBook::~PhoneBook()
{

}

std::string	PhoneBook::getInput(std::string inputMsg)
{
	std::string	input = "";

	while (input.length() == 0)
	{
		std::cout<<inputMsg;
		std::getline(std::cin, input);
	}
	return (input);
}

int			PhoneBook::getNumContact()
{
	return (_num_contact);
}

int			PhoneBook::getOldestContact()
{
	int			oldest = 0;

	for(int i = 1; i < 8; i++)
	{
		if (contact_list[i].getGenTime() < contact_list[oldest].getGenTime())
			oldest = i;
	}
	return (oldest);
}

void		PhoneBook::addContact()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_num;
	std::string secret;
	int			add_index;

	first_name = getInput("Input first name: ");
	last_name = getInput("Input last name: ");
	nick_name = getInput("Input nick name: ");
	phone_num = getInput("Input phone num: ");
	secret = getInput("Input secret: ");
	if ((add_index = getNumContact()) == MAX_CONTACT)
		add_index = getOldestContact();
	contact_list[add_index] =
		Contact(first_name, last_name, nick_name,
		phone_num, secret);
	_num_contact++;
}

void		PhoneBook::printText(std::string text, bool newline)
{
	if (text.length() >= 10)
	{

		text.resize(9);
		text.push_back('.');
	}
	std::cout<<std::setfill(' ')<<std::setw(10)<<text;
	if (newline)
		std::cout<<std::endl;
	else
		std::cout<<"|";
}

void		PhoneBook::printTitles()
{
	printText("INDEX", false);
	printText("FIRST NAME",false);
	printText("LAST NAME", false);
	printText("NICKNAME", true);
}

void		PhoneBook::searchContact()
{
	printTitles();
	for (int i = 0; i < _num_contact; i++)
	{
		std::cout<<std::setfill(' ')<<std::setw(10)<<i+1<<"|";
		printText(contact_list[i].getFirstName(), false);
		printText(contact_list[i].getLastName(), false);
		printText(contact_list[i].getNickName(), true);
	}
}