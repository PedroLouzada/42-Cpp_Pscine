/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:17:00 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/18 20:39:23 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "phonebook.hpp"

std::string getInfo(std::string arg)
{
    std::string input;
    
    std::cout << arg << ": " << std::endl;
    if (!std::getline(std::cin, input))
        return ("");

    return (input);
}

std::string reduceStr(std::string str)
{
    if (str.size() > 9)
        return (str.substr(0, 9) + '.');

    return (str);
}

void PhoneBook::searchContact(void)
{
    std::cout << "|     Index|First Name| Last Name|    Number|" << std::endl;

    std::string fname;
    std::string lname;
    std::string num;
    
    for (int i = 0; i < 8; i++)
    {
        fname = reduceStr(this->contact[i].GetFirstName());
        lname = reduceStr(this->contact[i].GetLastName());
        num = reduceStr(this->contact[i].GetNumber());

        if (!fname.empty() || !lname.empty() || !num.empty())
        {
            std::cout << "|" << std::setw(10) << std::right << i << "|"
                             << std::setw(10) << std::right << fname << "|"
                             << std::setw(10) << std::right << lname << "|"
                             << std::setw(10) << std::right << num << "|"
                             << std::endl;    
        }
    }
    
}

void PhoneBook::newContact(int i)
{
    Contact contact;
    
    std::string firstName = getInfo("First Name");
    std::string lastName = getInfo("Last Name");
    std::string nickName = getInfo("NickName");

    contact.SetName(firstName, lastName, nickName);

    std::string number = getInfo("Number");

    contact.SetNumber(number);

    std::string darkestSecret = getInfo("Darkest Secret");

    contact.SetSecret(darkestSecret);

    this->contact[i] = contact;
}