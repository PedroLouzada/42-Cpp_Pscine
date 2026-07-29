/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:44:28 by pbongiov          #+#    #+#             */
/*   Updated: 2026/07/29 12:32:53 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try {
        Bureaucrat inRange("In Range", 100);
        std::cout << inRange << std::endl;
        
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat highRange("High Range", 0);
        std::cout << highRange << std::endl;

    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat lowRange("Low Range", 151);
        std::cout << lowRange << std::endl;

    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    Bureaucrat inRange("In Range", 100);

    std::cout << inRange << std::endl;
    inRange.incrementGrade(10);
    std::cout << inRange << std::endl;
    inRange.decrementGrade(20);
    std::cout << inRange << std::endl;

    try{
        inRange.decrementGrade(100);
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << inRange << std::endl;

}