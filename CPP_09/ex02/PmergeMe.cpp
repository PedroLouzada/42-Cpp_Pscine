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

PmergeMe::PmergeMe(const PmergeMe& other) : _values(other._values) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
        _values = other._values;

    return *this;
}

PmergeMe::~PmergeMe() {}

bool errorMsg(const std::string& msg)
{
    std::cerr << msg << std::endl;
    return 1;
}

bool PmergeMe::parse(const std::string& str)
{
    std::istringstream in(str);
    std::string buf;
    std::vector<int> parsed;

    while (in >> buf)
    {
        for (size_t i = 0; i < buf.size(); ++i)
        {
            if (!std::isdigit(buf[i]))
                return errorMsg("Only positive integers supported");
        }

        int value;
        std::istringstream idk(buf);

        if (!(idk >> buf) || value <= 0)
            return errorMsg("Only positive integers supported");

        parsed.push_back(value);
    }

    if (parsed.empty())
        return errorMsg("Error during parsing");

    _values.insert(_values.end(), parsed.begin(), parsed.end());
    return 0;
}

void sortPairs(std::vector<std::pair<int, int>>& pairs, const std::vector<int>& winners)
{
    std::vector<std::pair<int, int>> ordered;
    std::vector<std::pair<int, int>> remain(pairs);

    for(size_t i = 0; i < winners.size(); ++i)
    {
        for(size_t j = 0; j < remain.size(); ++j)
        {
            if(remain[j].second == winners[i])
            {
                ordered.push_back(remain[j]);
                remain.erase(remain.begin() + j);
                break;
            }
        }
    }
    pairs = ordered;
}

void insertLosers(std::vector<int>& sorted, std::vector<std::pair<int, int>>& pairs)
{
    
}

void PmergeMe::fordJhonson(std::vector<int>& values)
{
    if (values.size() <= 1)
        return;

    bool oddSequence = false;
    std::vector<std::pair<int, int>> pairs;
    for(size_t i = 0; i + 1 < values.size(); i += 2)
    {
        if (values[i] > values[i + 1])
            pairs.push_back(std::make_pair(values[i + 1], values[i]));
        else
            pairs.push_back(std::make_pair(values[i], values[i + 1]));
    }
    if (values.size() % 2)
        oddSequence = true;

    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].second);

    fordJhonson(winners);
    sortPairs(pairs, winners);

    std::vector<int> sorted;
    sorted.push_back(pairs[0].first);
    for (size_t i = 0; i < pairs.size(); ++i)
        sorted.push_back(pairs[i].second);

    insertLosers(sorted, pairs);
    
}