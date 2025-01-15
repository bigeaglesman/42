/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:12:32 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/15 22:31:16 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

class	HumanA
{
	private:
		std::string _name;
	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA();
}

#endif