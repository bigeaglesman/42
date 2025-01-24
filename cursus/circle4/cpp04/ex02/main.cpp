/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:24:31 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/24 22:30:20 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	// 기본 생성자 테스트
	std::cout<<"Test default constructor"<<std::endl;
	Dog* dog = new Dog();
	Cat* cat = new Cat();
	std::cout<<std::endl<<std::endl;

	std::cout<<dog->getType()<<std::endl;
	dog->makeSound();
	std::cout<<cat->getType()<<std::endl;
	cat->makeSound();
	std::cout<<std::endl<<std::endl;

	dog->setIdea(0, "hello");
	dog->setIdea(1, "hi");
	dog->setIdea(2, "bye");
	std::cout<<"Dog idea 0: "<<dog->getIdea(0)<<std::endl;
	std::cout<<"Dog idea 1: "<<dog->getIdea(1)<<std::endl;
	std::cout<<"Dog idea 2: "<<dog->getIdea(2)<<std::endl;
	cat->setIdea(0, "hello");
	cat->setIdea(1, "hi");
	cat->setIdea(2, "bye");
	std::cout<<"Cat idea 0: "<<cat->getIdea(0)<<std::endl;
	std::cout<<"Cat idea 1: "<<cat->getIdea(1)<<std::endl;
	std::cout<<"Cat idea 2: "<<cat->getIdea(2)<<std::endl;
	std::cout<<std::endl<<std::endl;

	// 복사 생성자 테스트
	std::cout<<"Test copy constructor"<<std::endl;
	std::cout<<"copy dog"<<std::endl;
	Dog* dog_copy = new Dog(*dog);
	std::cout<<"cpoy cat"<<std::endl;
	Cat* cat_copy = new Cat(*cat);
	std::cout<<std::endl<<std::endl;

	// deep copy 테스트
	std::cout<<"Test deep copy"<<std::endl;
	std::cout<<dog_copy->getType()<<std::endl;
	dog_copy->makeSound();
	std::cout<<cat_copy->getType()<<std::endl;
	cat_copy->makeSound();
	std::cout<<std::endl<<std::endl;

	dog->setIdea(0, "hello");
	dog->setIdea(1, "hi");
	dog->setIdea(2, "bye");
	dog_copy->setIdea(0, "hello copy");
	dog_copy->setIdea(1, "hi copy");
	dog_copy->setIdea(2, "bye copy");
	cat->setIdea(0, "hello");
	cat->setIdea(1, "hi");
	cat->setIdea(2, "bye");
	cat_copy->setIdea(0, "hello copy");
	cat_copy->setIdea(1, "hi copy");
	cat_copy->setIdea(2, "bye copy");

	std::cout<<"Print original ideas"<<std::endl;
	std::cout<<"Dog idea 0: "<<dog->getIdea(0)<<std::endl;
	std::cout<<"Dog idea 1: "<<dog->getIdea(1)<<std::endl;
	std::cout<<"Dog idea 2: "<<dog->getIdea(2)<<std::endl;
	std::cout<<"Cat idea 0: "<<cat->getIdea(0)<<std::endl;
	std::cout<<"Cat idea 1: "<<cat->getIdea(1)<<std::endl;
	std::cout<<"Cat idea 2: "<<cat->getIdea(2)<<std::endl;
	std::cout<<std::endl<<std::endl;

	std::cout<<"Print copy ideas"<<std::endl;
	std::cout<<"Dog_copy idea 0: "<<dog_copy->getIdea(0)<<std::endl;
	std::cout<<"Dog_copy idea 1: "<<dog_copy->getIdea(1)<<std::endl;
	std::cout<<"Dog_copy idea 2: "<<dog_copy->getIdea(2)<<std::endl;
	std::cout<<"Cat_copy idea 0: "<<cat_copy->getIdea(0)<<std::endl;
	std::cout<<"Cat_copy idea 1: "<<cat_copy->getIdea(1)<<std::endl;
	std::cout<<"Cat_copy idea 2: "<<cat_copy->getIdea(2)<<std::endl;
	std::cout<<std::endl<<std::endl;


	std::cout<<std::endl<<std::endl;


	// 소멸자 테스트
	std::cout<<"Test destructor"<<std::endl;
	std::cout<<"delete dog"<<std::endl;
	delete dog;
	std::cout<<"delete cat"<<std::endl;
	delete cat;
	std::cout<<"delete dog copy"<<std::endl;
	delete dog_copy;
	std::cout<<"delete cat copy"<<std::endl;
	delete cat_copy;
	return 0;
}