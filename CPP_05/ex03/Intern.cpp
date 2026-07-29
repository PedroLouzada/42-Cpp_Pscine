/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:44:13 by pbongiov          #+#    #+#             */
/*   Updated: 2026/07/29 12:28:10 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void){}

Intern::Intern(const Intern& other) { *this = other; }

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
        *this = other;

    return (*this);
}

Intern::~Intern(void){}

const char* Intern::ParseErrorException::what() const throw() { return("Form Type does not match any of the options"); }

int    parseType(const std::string& type)
{
    std::string array[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; ++i)
    {
        if (array[i] == type)
            return i;
    }
    
    return -1;
}

AForm* Intern::makeForm(const std::string& type, const std::string& target)
{
    int res = parseType(type);
    
    switch (res)
    {       
        case 0:
            std::cout << "Intern creates Shrubbery Creation Form" << std::endl;
            return (new ShrubberyCreationForm(target));
        
        case 1:
            std::cout << "Intern creates Robotomy Request Form" << std::endl;
            return (new RobotomyRequestForm(target));

        case 2:
            std::cout << "Intern creates Presidential Pardon Form" << std::endl;
            return (new PresidentialPardonForm(target));

        default:
            throw ParseErrorException();
    }
        
    return (NULL);
}