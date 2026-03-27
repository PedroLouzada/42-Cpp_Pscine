/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:44:13 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/27 19:44:14 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do! (DEBUG)\n";
}

void Harl::warning(void)
{   
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month. (WARNING)\n";
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now. (ERROR)\n";
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more! (INFO)\n";
}

void Harl::complain(std::string level)
{
    std::string array[4] = {"DEBUG", "WARNING", "ERROR", "INFO"};
    void (Harl::*_funcPointer[4])(void) = {&Harl::debug, &Harl::warning, &Harl::error, &Harl::info};

    for (int i = 0; i < 4; i++)
    {
        if (!array[i].compare(level))
            (this->*_funcPointer[i])();
    }
}