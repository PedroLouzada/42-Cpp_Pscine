/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:49:49 by pbongiov          #+#    #+#             */
/*   Updated: 2026/08/08 16:11:41 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{   
    Base base;
    Base* ptr = base.generate();
    Base& ref = *ptr;

    base.identify(ptr);
    std::cout << "----------------------------------------" << std::endl;
    
    base.identify(ref);
    std::cout << "----------------------------------------" << std::endl;
    
    base.identify(NULL);
    std::cout << "----------------------------------------" << std::endl;

    delete(ptr);
}