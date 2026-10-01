/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 19:36:43 by pbongiov          #+#    #+#             */
/*   Updated: 2026/10/01 20:27:47 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _list(other._list), _deque(other._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _list = other._list;
        _deque = other._deque;
    }

    return *this;
}

PmergeMe::~PmergeMe() {}

bool isOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }

std::vector<std::string>& split(std::string& args, std::string sep)
{
    std::vector<std::string> res;
    size_t pos;

    while ((pos = args.find(sep)) != std::string::npos)
    {
        if (pos)
            res.push_back(args.substr(0, pos));
        args.erase(0, pos + sep.length());
    }
    
    if(!args.empty())
        res.push_back(args);

    return (res);
    
}

bool PmergeMe::parse(std::string& str)
{
    std::vector<std::string> args = split(str, " ");
    std::vector<std::string>::iterator it;
    
    for (it = args.begin(); it != args.end(); ++it)
    {
        int i = 0;
        while (it)
        {
            
        }
    }
}