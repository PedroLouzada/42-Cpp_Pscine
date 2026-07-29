/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:46:16 by pbongiov          #+#    #+#             */
/*   Updated: 2026/07/29 11:46:17 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other._target, 145, 137), _target(other._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        _target = other._target;

    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::poliExecute(void) const
{
    std::string name(_target + "_shrubbery");

    std::ofstream file(name.c_str());
    if (!file.is_open())
    {
        std::cerr << "Could not create the file" << std::endl;
        return;
    }

    file << "               ,@@@@@@@,\n       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
    file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
    file << "   `&%\\ ` /%&'    |.|        \\ '|8'\n       |o|        | |         | |\n";
    file << "       |.|        | |         | |\n    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_";

    file.close();
}