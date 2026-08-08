/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:26:52 by pbongiov          #+#    #+#             */
/*   Updated: 2026/08/08 16:10:35 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {}

Base* Base::generate(void)
{
    std::srand(std::time(NULL));
    
    int num = std::rand() % 3;

    switch (num)
    {
        case 0:
            return (new A);
        
        case 1:
            return (new B);

        case 2:
            return (new C);
    }

    return NULL;
}

void Base::identify(Base* p)
{
    Base* ptr[3] = {dynamic_cast<A*>(p), dynamic_cast<B*>(p), dynamic_cast<C*>(p)};
    int i = -1;
    
    while (++i < 3)
    {
        if (ptr[i] != NULL)
            break;
    }

    switch (i)
    {
        case 0:
            std::cout << "Base class type A" << std::endl;
            return;

        case 1:
            std::cout << "Base class type B" << std::endl;
            return;

        case 2:
            std::cout << "Base class type C" << std::endl;
            return;

        default:
            std::cout << "Type does not match any of the known" << std::endl;
    }
}

void Base::identify(Base& p)
{
    try{
        A a = dynamic_cast<A&>(p);
        std::cout << "Base class type A" << std::endl;
    }
    catch(std::exception& e){}

    try{
        B b = dynamic_cast<B&>(p);
        std::cout << "Base class type B" << std::endl;
    }
    catch(std::exception& e){}

    try{
        C c = dynamic_cast<C&>(p);
        std::cout << "Base class type C" << std::endl;
    }
    catch(std::exception& e){}
}
