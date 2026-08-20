/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 22:47:56 by pbongiov          #+#    #+#             */
/*   Updated: 2026/08/14 23:05:43 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <string>
#include <cctype>

static void multiplyByTwo(int& n)
{
    n *= 2;
}

static void printInt(int& n)
{
    std::cout << n << " ";
}

static void toUpperFirst(std::string& s)
{
    if (!s.empty())
        s[0] = std::toupper(s[0]);
}

static void printString(std::string& s)
{
    std::cout << s << " ";
}

int main(void)
{
    std::cout << "=== iter with int array ===" << std::endl;
    int intArray[5] = {1, 2, 3, 4, 5};

    std::cout << "before: ";
    ::iter(intArray, 5, printInt);
    std::cout << std::endl;

    ::iter(intArray, 5, multiplyByTwo);

    std::cout << "after multiplyByTwo: ";
    ::iter(intArray, 5, printInt);
    std::cout << std::endl;

    std::cout << std::endl << "=== iter with std::string array ===" << std::endl;
    std::string strArray[3] = {"hello", "world", "42"};

    std::cout << "before: ";
    ::iter(strArray, 3, printString);
    std::cout << std::endl;

    ::iter(strArray, 3, toUpperFirst);

    std::cout << "after toUpperFirst: ";
    ::iter(strArray, 3, printString);
    std::cout << std::endl;

    std::cout << std::endl << "=== iter with len = 0 ===" << std::endl;
    ::iter(intArray, 0, printInt);
    std::cout << "(nothing should be printed above)" << std::endl;

    return 0;
}
