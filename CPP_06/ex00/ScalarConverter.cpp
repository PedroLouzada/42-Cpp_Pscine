/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 14:02:04 by pbongiov          #+#    #+#             */
/*   Updated: 2026/07/29 16:03:31 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){ *this = other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this != & other)
        *this = other;

    return (*this);
}
        
ScalarConverter::~ScalarConverter(){}

static bool isChar(const std::string& arg)
{
    (void)arg;
    return false;
}

static bool isInt(const std::string& arg)
{
    (void)arg;
    return true;
}

static bool isFloat(const std::string& arg)
{
    (void)arg;
    return false;
}

static bool isDouble(const std::string& arg)
{
    (void)arg;
    return true;
}

int checkInput(const std::string& arg)
{
    int types[4] = {CHAR, INT, FLOAT, DOUBLE};
    bool (*func[4])(const std::string&) = {isChar, isInt, isFloat, isDouble};

    for (int i = 0; i < 4; ++i)
    {
        if (func[i](arg))
            return (types[i]);
    }

    return (ERR);
}

void convertChar(char& c, int& i, float& f, double& d, const std::string& arg)
{
    c = arg[0];
    i = static_cast<int>(arg[0]);
    f = static_cast<float>(arg[0]);
    d = static_cast<double>(arg[0]);
}

void convertInt(char& c, int& i, float& f, double& d, const std::string& arg)
{
    i = std::atoi(arg.c_str());
    c = static_cast<char>(i);
    f = static_cast<float>(i);
    d = static_cast<double>(i);
}

void printList(char& c, int& i, float& f, double& d)
{
    std::cout << "char: " << c << "\nint: " << i << "\nfloat: " << f << "\ndouble: " <<  d << std::endl;
}

void convertAll(int type, const std::string& arg)
{
    char c;
    int i;
    float f;
    double d;

    switch (type)
    {
        case CHAR:
            convertChar(c, i, f, d, arg);
            break;
        
        case INT:
            convertInt(c, i, f, d, arg);
    }

    printList(c, i, f, d);
}

void ScalarConverter::convert(const std::string& arg)
{
    int type = checkInput(arg);

    if (type == ERR)
    {
        std::cerr << "Invalid parameter, conversion cannot proceed." << std::endl;
        return ;
    }
    
    convertAll(type, arg);
}