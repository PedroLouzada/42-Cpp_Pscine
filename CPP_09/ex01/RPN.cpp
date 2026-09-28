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
    int res = 0;
    bool flag = false;
    
    for (size_t i = 0; i < arg.size(); ++i)
    {
        if (isOperator(arg[i]))
        {
            if (this->size() < 2)
                return errorMsg("Error on expression: Not enought numbers to operation " + std::string(1, arg[i]));

            int n1 = this->top();
            this->pop();
            
            int n2 = this->top();
            this->pop();
            
            if (arg[i] == '/' && n2 == 0)
                return errorMsg("Could not make a division by 0");

            res += operation(n1, n2, arg[i]);
            flag = false;
            continue;
        }

        if (std::isdigit(arg[i]))
        {
            if (this->size() >= 2)
                return errorMsg("Only support numbers between 0 and 9");
                
            this->push(arg[i] - '0');
            flag = false;
            continue;
        }

        if (arg[i] == ' ')
        {
            if (flag == true)
                return ("Wrong format of expression. Should have one space between numbers");

            flag = true;
            continue;
        }

        return errorMsg("Character type not supported");
    }

    std::cout << res << std::endl;
    
    return 0;
}
