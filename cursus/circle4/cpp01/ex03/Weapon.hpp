/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:07:02 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/10 15:22:00 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
private:
	std::string	_type;
public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	const std::string &getType() const;
	void setType(std::string type);
};
#endif