/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:11:53 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/07 17:39:43 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "---------------------------- Constructor Tests ---------------------------------\n";

    const Animal* meta = new Animal();
    std::cout << std::endl;

    const Animal* dog = new Dog();
    std::cout << std::endl;

    const Animal* cat = new Cat();
    std::cout << std::endl;

    Animal copied;
    std::cout << std::endl;

    const WrongAnimal* wmeta = new WrongAnimal();
    std::cout << std::endl;
    
    const WrongAnimal* wcat= new WrongCat();
    std::cout << std::endl;

    std::cout << "---------------------------- Copy Constructor Tests ----------------------------\n";

    Animal copyAnimal(copied);
    Animal copiedAnimal;
    copiedAnimal = copyAnimal;
    std::cout << std::endl;

    std::cout << "\n---------------------------- Getters Tests -------------------------------------\n";

    std::cout << meta->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << wmeta->getType() << " " << std::endl;
    std::cout << wcat->getType() << " " << std::endl;

    std::cout << "\n---------------------------- Sound Tests -------------------------------------\n";
    
    cat->makeSound();
    dog->makeSound();
    meta->makeSound();
    wmeta->makeSound();
    wcat->makeSound();

    std::cout << "\n---------------------------- Destructor Tests ---------------------------------\n";

    delete(meta);
    std::cout << std::endl;
    
    delete(dog);
    std::cout << std::endl;

    delete(cat);
    std::cout << std::endl;

    delete(wmeta);
    std::cout << std::endl;

    delete(wcat);
}