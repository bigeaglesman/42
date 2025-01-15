/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:40:22 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/15 14:29:18 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string first_name, std::string last_name,
			std::string nick_name, std::string phone_num,
			std::string secret)
{
	_first_name = first_name;
	_last_name = last_name;
	_nick_name = nick_name;
	_phone_num = phone_num;
	_secret = secret;
	time(&_gen_time);
}

Contact::~Contact()
{

}

std::string	Contact::getFirstName() const
{
	return (_first_name);
}

std::string	Contact::getLastName() const
{
	return (_last_name);
}

std::string	Contact::getNickName() const
{
	return (_nick_name);
}

std::string	Contact::getPhoneNum() const
{
	return (_phone_num);
}

std::string	Contact::getSecret() const
{
	return (_secret);
}

time_t		Contact::getGenTime() const
{
	return (_gen_time);
}