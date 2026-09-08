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

        std::string key = line.substr(0, pos - 1);
        std::string value = line.substr(pos + 2);
        if (pos == std::string::npos)
            value = "\2";

        this->insert(std::make_pair(key, value));
    }
}

void BitcoinExchange::initDatabase(std::ifstream& file)
{
    std::string line;

    while (std::getline(file, line))
    {
        size_t pos = line.find(",");

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        _data.insert(std::make_pair(key, value));
    }
}

bool BitcoinExchange::parseFile(const std::string& fileName)
{
    std::ifstream inputFile(fileName.c_str());
    if (!inputFile.is_open())
        return errorMsg("could not open the input file.");

    std::ifstream dataFile("data.csv");
    if (!dataFile.is_open())
        return errorMsg("Could not open data file");

    std::string line;
    std::getline(inputFile, line);
    if (line.empty() || line != "date | value")
        return errorMsg("expected \"date | value\" in the beginning of the file.");

    this->initMap(inputFile, line);
    this->initDatabase(dataFile);
    
    return 0;
}

void BitcoinExchange::printValue() //debug only
{
    std::map<std::string, std::string>::iterator it;

    for (it = this->begin(); it != this->end(); ++it)
        std::cout << it->first << " | " << it->second << std::endl;
}

static bool isValidDate(std::multimap<std::string, std::string>::iterator& input)
{
    if (input->second == "\2")
        return 0;

    int date[3];
    size_t begin = input->first.find('-');
    size_t final = input->first.find_last_of('-');
    if (begin == std::string::npos || begin != 4 || final != 7)
        return 0;

    date[0] = atoi(input->first.substr(0, begin).c_str());
    date[1] = atoi(input->first.substr(begin + 1, input->first.size() - final - 1).c_str());
    date[2] = atoi(input->first.substr(final + 1, input->first.size() - 1).c_str());

    return 1;
}

bool BitcoinExchange::convertCoin(std::multimap<std::string, std::string>::iterator& input)
{
    if (!isValidDate(input))
        return errorMsg("bad input => ");
    
    std::map<std::string, std::string>::iterator it;
    it = _data.lower_bound(input->first);

    if (it == _data.end() || it->first != input->first)
    {
        if (it == _data.begin())
            return errorMsg("no previous date found");

        --it;
    }
    
    double value = std::atof(input->second.c_str());

    if (value > 1000)
        return errorMsg("too large number.");
    if (value < 0)
        return errorMsg("not a positive number.");

    std::cout << input->first <<  std::endl;

    return 0;
}

