/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:44:05 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/27 19:45:51 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[DEBUG]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n";
}

void Harl::warning(void)
{   
    std::cout << "[WARNING]\n";
    std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years, whereas you started working here just last month.\n";
}

void Harl::error(void)
{
    std::cout << "[ERROR]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::info(void)
{
    std::cout << "[INFO]\n";
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!\n";
}

int getIndex(std::string level)
{
    std::string array[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (array[i] == level)
            return (i + 1);
    }
    return (0);
}

void Harl::complain(std::string level)
{
    int n = getIndex(level);

    switch (n)
    {
        case 1:
            this->debug();

        case 2:
            this->info();

        case 3:
            this->warning();

        case 4:
            this->error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
}