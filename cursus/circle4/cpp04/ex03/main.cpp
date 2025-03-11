/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:53:50 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/22 22:04:52 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Debug.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();

	Ice ice;
	Cure cure;
	std::cout<<std::endl<<std::endl;
	src->learnMateria(&ice);
	src->learnMateria(&cure);
	std::cout<<std::endl<<std::endl;

	std::cout<<"Character me created"<<std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	std::cout<<std::endl<<std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout<<std::endl;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout<<std::endl<<std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout<<std::endl;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout<<std::endl<<std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	
	std::cout<<std::endl<<std::endl;

	std::cout<<"Character bob created"<<std::endl;
	ICharacter* bob = new Character("bob");
	std::cout<<std::endl<<std::endl;
	
	std::cout<<"me use Ice to bob"<<std::endl;
	me->use(0, *bob);
	std::cout<<std::endl<<std::endl;
	
	std::cout<<"me use Cure to bob"<<std::endl;
	me->use(1, *bob);
	std::cout<<std::endl<<std::endl;

	std::cout<<"me unequip Cure in inventory 1"<<std::endl;
	me->unequip(1);
	std::cout<<std::endl<<std::endl;

	std::cout<<"me unequip Cure in inventory 1"<<std::endl;
	me->unequip(1);
	std::cout<<std::endl<<std::endl;
	
	std::cout<<"me unequip ice in inventory 0"<<std::endl;
	me->unequip(0);
	std::cout<<std::endl<<std::endl;

	std::cout<<"me unequip Ice in inventory 0"<<std::endl;
	me->unequip(0);
	std::cout<<std::endl<<std::endl;
	
	delete tmp;
	delete bob;
	delete me;
	delete src;
	return 0;
}