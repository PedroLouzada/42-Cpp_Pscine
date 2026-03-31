/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:35:13 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/24 16:37:36 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::Get_firstname(void)
{
    return (this->_firstname);
}

std::string Contact::Get_lastname(void)
{
    return (this->_lastname);
}

std::string Contact::Get_number(void)
{
    return (this->_number);
}

std::string Contact::Get_nickname(void)
{
    return (this->_nickname);
}

std::string Contact::GetSecret(void)
{
    return (this->_darkestSecret);
}

void Contact::SetName(std::string firstname, std::string lastname, std::string nickname)
{
    this->_firstname = firstname;
    this->_lastname = lastname;
    this->_nickname = nickname;
}

void Contact::Set_number(std::string number)
{
    this->_number = number;
}

void Contact::SetSecret(std::string darkestSecret)
{
    this->_darkestSecret = darkestSecret;
}