/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:01:41 by pbongiov          #+#    #+#             */
/*   Updated: 2026/09/28 18:29:17 by pbongiov         ###   ########.fr       */
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
        return false;

    const std::string& s = input->first;
    if (s.size() != 10 || s[4] != '-' || s[7] != '-')
        return false;

    for (size_t i = 0; i < s.size(); ++i)
        if (i != 4 && i != 7 && (s[i] < '0' || s[i] > '9'))
            return false;

    int year  = std::atoi(s.substr(0, 4).c_str());
    int month = std::atoi(s.substr(5, 2).c_str());
    int day   = std::atoi(s.substr(8, 2).c_str());

    if (year == 0 || month < 1 || month > 12 || day < 1)
        return false;

    const int daysInMonth[] = {31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31};
    int maxDay = daysInMonth[month - 1];
    if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        ++maxDay;

    return (day <= maxDay);
}


bool BitcoinExchange::convertCoin(std::multimap<std::string, std::string>::iterator& input)
{
    if (!isValidDate(input))
        return errorMsg("bad input => " + input->first);
    
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

    double currency = std::atof(it->second.c_str());
    std::cout << input->first << " => " << value << " = " << value * currency << std::endl;

    return 0;
}

