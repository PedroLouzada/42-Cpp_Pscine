/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 01:17:29 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/28 02:28:05 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
    if (Fixed(10) > Fixed(5.0f))
        std::cout << "a is bigger\n";
    else
        std::cout << "b id bigger\n";
    
    if (Fixed(2.0f) < Fixed(1.0f))
        std::cout << "a is smaller\n";
    else
        std::cout << "b id smaller\n";

    if (Fixed(5.0f) >= Fixed(5))
        std::cout << "a is bigger or equal\n";

    if (Fixed(5.0f) <= Fixed(5))
        std::cout << "a is smaller or equal\n";

    if (Fixed(10) == Fixed(10.0f))
        std::cout << "a is equal to b\n";
        
    if (Fixed(5.0f) != Fixed(5))
        std::cout << "a is different to b\n";

    
    std::cout << Fixed(10.0f) + Fixed(5) << std::endl;
    std::cout << Fixed(10.0f) - Fixed(5) << std::endl;
    std::cout << Fixed(10.0f) * Fixed(5) << std::endl;
    std::cout << Fixed(10.0f) / Fixed(5) << std::endl;

    Fixed a(10);
    Fixed b(10.0f);
    
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    
    std::cout << b-- << std::endl;
    std::cout << b << std::endl;
    std::cout << --b << std::endl;

    const Fixed n1(10);
    const Fixed n2(2.0f);
    
    std::cout << Fixed::min(Fixed(10), Fixed(2)) << std::endl;
    std::cout << Fixed::min(n1, n2) << std::endl;
    std::cout << Fixed::max(Fixed(10), Fixed(2)) << std::endl;
    std::cout << Fixed::max(n1, n2) << std::endl;

}