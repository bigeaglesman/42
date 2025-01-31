/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:04:50 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/30 23:30:49 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
	{
		contact_list[getOldestContact()] =
		Contact(first_name, last_name, nick_name,
		phone_num, secret);
	}
	else
	{
		contact_list[add_index] =
		Contact(first_name, last_name, nick_name,
		phone_num, secret);
		_num_contact++;
	}

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
	printText("FIRSTNAME",false);
	printText("LASTNAME", false);
	printText("NICKNAME", true);
}

void		PhoneBook::searchContact()
{
	int index;

	printTitles();
	for (int i = 0; i < _num_contact; i++)
	{
		std::cout<<std::setfill(' ')<<std::setw(10)<<i+1<<"|";
		printText(contact_list[i].getFirstName(), false);
		printText(contact_list[i].getLastName(), false);
		printText(contact_list[i].getNickName(), true);
	}
	while (true)
	{
		index = atoi(getInput("Input Index: ").c_str());
		if (index >= 1 && index <= getNumContact())
			break ;
		else
			std::cout<<"Invalid Index"<<std::endl;
	}
	index--;
	std::cout<<"FirstName: "<<contact_list[index].getFirstName()<<std::endl;
	std::cout<<"LastName: "<<contact_list[index].getLastName()<<std::endl;
	std::cout<<"NickName: "<<contact_list[index].getNickName()<<std::endl;
	std::cout<<"PhoneName: "<<contact_list[index].getPhoneNum()<<std::endl;
	std::cout<<"Secret: "<<contact_list[index].getSecret()<<std::endl;
}