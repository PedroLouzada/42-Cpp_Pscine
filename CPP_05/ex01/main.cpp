/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:44:43 by pbongiov          #+#    #+#             */
/*   Updated: 2026/07/29 11:44:44 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Form A1("A1", 1, 1);
        std::cout << A1 << std::endl;
        Form A2("A2", 150, 150);
        std::cout << A2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "-------------" << std::endl;

    try
    {
        Form A1("A1", 0, 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "-------------" << std::endl;

    try
    {
        Form A1("A1", 151, 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "-------------" << std::endl;

    try
    {
        Form A1("A1", 10, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "-------------" << std::endl;

    try
    {
        Form A1("A1", 10, 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "-------------" << std::endl;

    Bureaucrat Denise("Denise", 15);

    try
    {
        Form A1("Cheat", 10, 10);

        Denise.signForm(A1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "-------------" << std::endl;

    Form A1("Cheat", 20, 10);

    try
    {
        Denise.signForm(A1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << A1 << std::endl;
        Denise.signForm(A1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "-------------" << std::endl;

    Form A2("A2", 20, 10);
    Denise.signForm(A2);

    Form A3(A2);

    std::cout << A3 << std::endl;

    std::cout << "-------------" << std::endl;
}