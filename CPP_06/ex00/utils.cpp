/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:47:11 by pbongiov          #+#    #+#             */
/*   Updated: 2026/07/30 16:15:15 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

void convertFloat(char& c, int& i, float& f, double& d, const std::string& arg)
{
    d = std::atof(arg.c_str());
    i = static_cast<int>(d);
    c = static_cast<char>(d);
    f = static_cast<float>(d);
}

bool isChar(const std::string& arg)
{
    if (arg.size() == 1 && !std::isdigit(arg[0]))
        return true;
    return false;
}

bool isInt(const std::string& arg)
{
    for (size_t i = 0; i < arg.size(); ++i)
    {
        if (i == 0 && (arg[0] == '+' || arg[0] == '-'))
            ++i;
        if (!std::isdigit(arg[i]))
            return false;
    }
    
    return true;
}

static bool checkDecimal(const std::string& arg)
{
    bool flag = false;
    size_t i = -1;
    size_t size = arg.size();

    if (arg[0] == '+' || arg[0] == '-')
        ++i;
        
    while (++i < size - 1)
    {
        if (arg[i] == '.')
        {
            if (!flag)
                flag = !flag;
            else
                return false;

            continue;
        }
        if (!std::isdigit(arg[i]))
            return false;
    }

    return true;
}

bool isFloat(const std::string& arg)
{

    if (!checkDecimal(arg) || arg[arg.size() - 1] != 'f')
        return false;
        
    return true;
}

bool isDouble(const std::string& arg)
{
    if (!checkDecimal(arg) || !std::isdigit(arg[arg.size() - 1]))
        return false;

    return true;
}

void printDoubleException(const std::string& arg) { std::cout << "char: impossible\nint: impossible\nfloat: " << arg << "f\ndouble: " <<  arg << std::endl; }

void printFloatException(const std::string& arg)
{
    std::string temp(arg);

    std::cout << "char: impossible\nint: impossible\nfloat: " << temp << "\ndouble: " << temp.erase(temp.size() - 1)  << std::endl;
}
