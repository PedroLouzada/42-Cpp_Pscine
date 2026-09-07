/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:01:41 by pbongiov          #+#    #+#             */
/*   Updated: 2026/09/07 17:02:35 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int errorMsg(const std::string& msg);

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        *this = other;

    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::initMap(std::ifstream& file, std::string& line)
{
    while (std::getline(file, line))
    {
        size_t pos = line.find("|");
        if (pos == std::string::npos)
        {
            this->insert(std::make_pair("\2", "\2"));
            continue;
        }

        std::string key = line.substr(0, pos - 1);
        std::string value = line.substr(pos + 2);

        this->insert(std::make_pair(key, value));
    }
}

bool BitcoinExchange::parseFile(const std::string& fileName)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
        return errorMsg("could not open the file.");

    std::string line;
    std::getline(file, line);
    if (line.empty() || line != "date | value")
        return errorMsg("expected \"date | value\" in the beginning of the file.");

    this->initMap(file, line);
    
    return 0;
}

void BitcoinExchange::printValue() //debug only
{
    std::map<std::string, std::string>::iterator it;

    for (it = this->begin(); it != this->end(); ++it)
        std::cout << it->first << " | " << it->second << std::endl;
}

bool BitcoinExchange::convertCoin()
{
    
}