/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:11:53 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/16 21:19:56 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "------------------------ Construct test ---------------------\n\n";

    // Animal b;
    // Animal* a = new Animal;
    
    Animal* animal = new Dog;

    std::cout << "\n\n------------------------ Deep copy test ---------------------\n\n";
    
    Dog* dogA = new Dog();
    std::cout << "\n";
    Dog* dogB = new Dog();
    std::cout << "\n";

    *dogA = *dogB;
    std::cout << "\n";
    delete(dogB);
    std::cout << "\n";

    std::cout << dogA->getIdea(5) << std::endl;

    std::cout << "\n\n------------------------ Destructor test ---------------------\n\n";

    delete(dogA);
    std::cout << std::endl;
    delete(animal);
}