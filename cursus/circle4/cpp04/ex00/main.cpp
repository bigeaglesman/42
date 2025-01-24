/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:24:31 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/24 15:08:00 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout<<std::endl<<std::endl;
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << wrongmeta->getType() << " " << std::endl;
	std::cout << wrongcat->getType() << " " << std::endl;
	wrongcat->makeSound();
	wrongmeta->makeSound();

	delete wrongmeta;
	delete wrongcat;

	return 0;
}