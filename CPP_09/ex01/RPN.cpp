/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 19:12:43 by pbongiov          #+#    #+#             */
/*   Updated: 2026/09/28 20:20:33 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

Rpn::Rpn() {};

Rpn::Rpn(const Rpn& other) : std::stack<int>(other) {}

Rpn& Rpn::operator=(const Rpn& other)
{
    if (this != &other)
        std::stack<int>::operator=(other);

    return *this;
}

Rpn::~Rpn() {}

bool errorMsg(const std::string& msg)
{
    std::cerr << msg << std::endl;
    return 1;
}

bool isOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }

int operation(int n1, int n2, char c)
{
    switch (c)
    {
        case '+':
            return (n1 + n2);

        case '-':
            return (n1 - n2);
        
        case '*':
            return (n1 * n2);

        case '/':
            return (n1 / n2);
    }

    return (0);
}

bool Rpn::resolve(const std::string& arg)
{
    std::istringstream input(arg);
    std::string token;

    while (input >> token)
    {
        if (token.size() != 1)
        {
            bool digitsOnly = true;
            for (size_t i = 0; i < token.size(); ++i)
            {
                if (!std::isdigit(token[i]))
                    digitsOnly = false;
            }
            if (digitsOnly)
                return errorMsg("Only support numbers between 0 and 9");
            return errorMsg("Wrong expression format");
        }

        if (isOperator(token[0]))
        {
            if (this->size() < 2)
                return errorMsg("Error on expression: Not enought numbers to operation " + token);

            int right = this->top();
            this->pop();
            
            int left = this->top();
            this->pop();

            if (token[0] == '/' && right == 0)
                return errorMsg("Division by zero");

            this->push(operation(left, right, token[0]));
            continue;
        }

        if (std::isdigit(token[0]))
        {
            this->push(token[0] - '0');
            continue;
        }

        return errorMsg("Character type not supported");
    }

    if (this->size() != 1)
        return errorMsg("Wrong expression format");

    std::cout << this->top() << std::endl;
    
    return 0;
}
