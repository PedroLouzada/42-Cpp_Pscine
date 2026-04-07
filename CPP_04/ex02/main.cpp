/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:11:53 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/07 19:30:04 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "---------------------------- Constructor Tests ---------------------------------\n";

    // const Animal* meta = new Animal();
    // std::cout << std::endl;
    
    const Animal* dog = new Dog();
    std::cout << std::endl;

    const Animal* cat = new Cat();
    std::cout << std::endl;

    Dog ndog;
    std::cout << std::endl;

    Cat ncat;
    std::cout << std::endl;

    WrongAnimal a;
    std::cout << std::endl;

    WrongCat c;
    std::cout << std::endl;
    
    Brain b;
    std::cout << std::endl;

    const WrongAnimal* wmeta = new WrongAnimal();
    std::cout << std::endl;
    
    const WrongAnimal* wcat= new WrongCat();
    std::cout << std::endl;

    std::cout << "---------------------------- Copy Constructor Tests ----------------------------\n";

    Dog n2dog(ndog);
    Dog n3dog;
    n3dog = n2dog;
    std::cout << std::endl;

    Cat n2Cat(ncat);
    Cat n3Cat;
    n3Cat = n2Cat;
    std::cout << std::endl;

    WrongAnimal a2(a);
    WrongAnimal a3;
    a3 = a2;
    std::cout << std::endl;

    WrongCat c2(c);
    WrongCat c3;
    c3 = c2;
    std::cout << std::endl;

    Brain b2(b);
    Brain b3;
    b3 = b2;
    std::cout << std::endl;
    
    std::cout << "\n---------------------------- Getters Tests -------------------------------------\n";

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << wmeta->getType() << " " << std::endl;
    std::cout << wcat->getType() << " " << std::endl;

    std::cout << "\n---------------------------- Sound Tests -------------------------------------\n";
    
    cat->makeSound();
    dog->makeSound();
    wmeta->makeSound();
    wcat->makeSound();

    std::cout << "\n---------------------------- Destructor Tests ---------------------------------\n";
    
    delete(dog);
    std::cout << std::endl;

    delete(cat);
    std::cout << std::endl;

    delete(wmeta);
    std::cout << std::endl;

    delete(wcat);
    std::cout << std::endl;
}