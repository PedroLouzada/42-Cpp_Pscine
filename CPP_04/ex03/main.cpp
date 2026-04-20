/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:16:05 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/18 16:30:19 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main(void)
{

    std::cout << "--------------------- Constructor tests ---------------------\n\n";

    IMateriaSource* mSource = new MateriaSource();
    std::cout << std::endl;
    ICharacter* person = new Character("Pedro");
    std::cout << std::endl;
    AMateria* ice = new Ice();
    std::cout << std::endl;
    AMateria* cure = new Cure();
    std::cout << std::endl;

    std::cout << "--------------------- MateriaSource tests ---------------------\n\n";

    AMateria* cMateria = mSource->createMateria("ice");
    mSource->createMateria("aaaaa");
    mSource->learnMateria(ice);

    person->equip(cMateria);
    person->unequip(0);

    std::cout << "--------------------- Destructor tests ---------------------\n\n";
    delete(mSource);
    delete(person);
    delete(ice);
    delete(cure);

}