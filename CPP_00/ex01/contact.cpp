/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:35:13 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/18 20:39:35 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string Contact::GetFirstName(void)
{
    return (this->firstName);
}

std::string Contact::GetLastName(void)
{
    return (this->lastName);
}

std::string Contact::GetNumber(void)
{
    return (this->number);
}

void Contact::SetName(std::string firstName, std::string lastName, std::string nickname)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
}

void Contact::SetNumber(std::string number)
{
    this->number = number;
}

void Contact::SetSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
}