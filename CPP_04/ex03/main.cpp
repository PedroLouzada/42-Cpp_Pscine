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

    ICharacter* pedro = new Character("Pedro");
    std::cout << std::endl;

    ICharacter* bob = new Character("Bob");
    std::cout << std::endl;

    std::cout << "--------------------- MateriaSource learn tests ---------------------\n\n";

    AMateria* m1 = new Ice();
    std::cout << std::endl;

    AMateria* m2 = new Cure();
    std::cout << std::endl;

    AMateria* m3 = new Ice();
    std::cout << std::endl;

    AMateria* m4 = new Cure();
    std::cout << std::endl;

    AMateria* m5 = new Ice();
    std::cout << std::endl;

    mSource->learnMateria(m1);
    std::cout << std::endl;

    mSource->learnMateria(m2);
    std::cout << std::endl;

    mSource->learnMateria(m3);
    std::cout << std::endl;

    mSource->learnMateria(m4);
    std::cout << std::endl;

    mSource->learnMateria(m5);
    std::cout << std::endl;

    std::cout << "--------------------- MateriaSource create tests ---------------------\n\n";

    AMateria* tmp1 = mSource->createMateria("ice");
    std::cout << std::endl;

    AMateria* tmp2 = mSource->createMateria("cure");
    std::cout << std::endl;

    AMateria* tmp3 = mSource->createMateria("ice");
    std::cout << std::endl;

    AMateria* tmp4 = mSource->createMateria("cure");
    std::cout << std::endl;

    std::cout << "--------------------- Equip tests ---------------------\n\n";

    pedro->equip(tmp1);
    std::cout << std::endl;

    pedro->equip(tmp2);
    std::cout << std::endl;

    pedro->equip(tmp3);
    std::cout << std::endl;

    pedro->equip(tmp4);
    std::cout << std::endl;

    std::cout << "--------------------- Use tests ---------------------\n\n";

    pedro->use(0, *bob);
    std::cout << std::endl;

    pedro->use(1, *bob);
    std::cout << std::endl;

    pedro->use(2, *bob);
    std::cout << std::endl;

    pedro->use(3, *bob);
    std::cout << std::endl;

    pedro->use(4, *bob);
    std::cout << std::endl;

    pedro->use(-1, *bob);
    std::cout << std::endl;

    std::cout << "--------------------- Unequip tests ---------------------\n\n";

    pedro->unequip(0);
    std::cout << std::endl;

    pedro->unequip(1);
    std::cout << std::endl;

    pedro->unequip(4);
    std::cout << std::endl;

    pedro->unequip(-1);
    std::cout << std::endl;

    pedro->unequip(0);
    std::cout << std::endl;

    std::cout << "--------------------- Deep copy tests ---------------------\n\n";

    ICharacter* pedroCopy = new Character(*static_cast<Character*>(pedro));
    std::cout << std::endl;

    pedroCopy->use(2, *bob);
    pedroCopy->use(3, *bob);
    std::cout << std::endl;

    pedro->unequip(2);
    std::cout << std::endl;

    pedroCopy->use(2, *bob);
    std::cout << std::endl;

    std::cout << "--------------------- Assignment operator tests ---------------------\n\n";

    ICharacter* bobCopy = new Character("temp");
    std::cout << std::endl;

    *static_cast<Character*>(bobCopy) = *static_cast<Character*>(pedro);
    std::cout << std::endl;

    bobCopy->use(2, *bob);
    bobCopy->use(3, *bob);
    std::cout << std::endl;

    std::cout << "--------------------- Subject main test ---------------------\n\n";

    IMateriaSource* src = new MateriaSource();
    std::cout << std::endl;

    AMateria* si = new Ice();
    AMateria* sc = new Cure();
    std::cout << std::endl;

    src->learnMateria(si);
    src->learnMateria(sc);
    std::cout << std::endl;

    ICharacter* me = new Character("me");
    std::cout << std::endl;

    AMateria* tmp;
    std::cout << std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl;

    ICharacter* bob2 = new Character("bob");
    me->use(0, *bob2);
    me->use(1, *bob2);
    std::cout << std::endl;

    std::cout << "--------------------- Destructor tests ---------------------\n\n";

    delete si;
    std::cout << std::endl;

    delete sc;
    std::cout << std::endl;

    delete m1;
    std::cout << std::endl;

    delete m2;
    std::cout << std::endl;

    delete m3;
    std::cout << std::endl;

    delete m4;
    std::cout << std::endl;

    delete m5;
    std::cout << std::endl;

    delete bob2;
    std::cout << std::endl;
    
    delete me;
    std::cout << std::endl;

    delete src;
    std::cout << std::endl;

    delete mSource;
    std::cout << std::endl;

    std::cout << std::endl;

    delete pedro;
    std::cout << std::endl;

    delete bob;
    std::cout << std::endl;

    delete pedroCopy;
    std::cout << std::endl;

    delete bobCopy;
    std::cout << std::endl;

    return 0;
}