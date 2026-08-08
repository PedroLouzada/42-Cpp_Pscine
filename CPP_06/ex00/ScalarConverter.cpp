/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 14:02:04 by pbongiov          #+#    #+#             */
/*   Updated: 2026/08/08 16:40:46 by pbongiov         ###   ########.fr       */
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

void printList(char& c, int& i, float& f, double& d)
{
    std::string temp = '\'' + std::string(1, c) + '\'';
    
    if (!std::isprint(c))
        temp = "Non displayable";
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "char: " << temp << "\nint: " << i << "\nfloat: " << f << "f\ndouble: " <<  d << std::endl;
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
            break;

        default:
            convertFloat(c, i, f, d, arg);
    }

    printList(c, i, f, d);
}

bool checkExceptions(const std::string& arg)
{
    if (arg == "+inf" || arg == "-inf" || arg == "nan")
    {
        printDoubleException(arg);
        return true;
    }
    else if (arg == "+inff" || arg == "-inff" || arg == "nanf")
    {
        printFloatException(arg);
        return true;
    }

    return false;
}

void ScalarConverter::convert(const std::string& arg)
{
    if (checkExceptions(arg))
        return ;
    
    int type = checkInput(arg);

    if (type == ERR)
    {
        std::cerr << "Invalid parameter, conversion cannot proceed." << std::endl;
        return ;
    }
    
    convertAll(type, arg);
}