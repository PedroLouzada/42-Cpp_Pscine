/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:11:53 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/16 21:14:08 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "------------------------ Construct Array ---------------------\n\n";

    Animal *array[10];

    for(int i = 0; i < 10; i++)
    {
        if (i % 2)
            array[i] = new Dog();
        else
            array[i] = new Cat();
        std::cout << "\n";
    }

    for(int i = 0; i < 10; i++)
        std::cout << "Index " << i << ": " << array[i]->getType() << std::endl;

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
    for (int i = 0; i < 10; i++)
    {
        delete(array[i]);
        std::cout << std::endl;
    }
}