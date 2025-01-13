/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:40:19 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/13 09:58:45 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <ctime>
# include <string>

class	Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_phone_num;
		std::string _secret;
		time_t		_gen_time;
	public:
		Contact();
		Contact(std::string first_name, std::string last_name,
			std::string nick_name, std::string phone_num,
			std::string secret);
		~Contact();
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNum() const;
		std::string	getSecret() const;
		time_t		getGenTime() const;
};

#endif 