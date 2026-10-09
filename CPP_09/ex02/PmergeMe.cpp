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

PmergeMe::PmergeMe() : _oddSequence(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque),
        _oddSequence(other._oddSequence), _straggler(other._straggler) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
        _oddSequence = other._oddSequence;
        _straggler = other._straggler;
    }

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
        std::istringstream str(buf);
        str >> value;

        if (str.fail() || !str.eof() || value <= 0)
            return errorMsg("Only positive integers supported");

        parsed.push_back(value);
    }

    _vector.insert(_vector.end(), parsed.begin(), parsed.end());
    _deque.insert(_deque.end(), parsed.begin(), parsed.end());

    return 0;
}

void sortPairsVector(std::vector<std::pair<int, int> >& pairs, const std::vector<int>& winners)
{
    std::vector<std::pair<int, int> > ordered;
    std::vector<std::pair<int, int> > remain(pairs);

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

std::vector<int> getJacobOrderVector(int size)
{
    std::vector<int> order;
    int prev = 1, curr = 3, bigger, next;

    while (prev < size)
    {
        if (curr < size)
            bigger = curr;
        else
            bigger = size;

        for (int i = bigger; i > prev; --i)
            order.push_back(i);

        next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }

    return (order);
}

void PmergeMe::insertLosersVector(std::vector<int>& sorted, std::vector<std::pair<int, int> >& pairs)
{
    int loserSize = pairs.size();
    if (_oddSequence)
        ++loserSize;

    int winner, loser;
    std::vector<int>::iterator binarySearch, pos; 
    std::vector<int> jacobsthal = getJacobOrderVector(loserSize);

    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        std::size_t bNumber = static_cast<std::size_t>(jacobsthal[i]);
        if (bNumber <= pairs.size())
        {
            loser = pairs[bNumber - 1].first;
            winner = pairs[bNumber - 1].second;

            binarySearch = std::find(sorted.begin(), sorted.end(), winner);
        }
        else
        {
            loser = _straggler;
            binarySearch = sorted.end();
        }

        pos = std::lower_bound(sorted.begin(), binarySearch, loser);
        sorted.insert(pos, loser);
    }
}

std::vector<int> PmergeMe::fordJhonsonVector(std::vector<int>& values)
{
    if (values.size() <= 1)
        return (values);

    std::vector<std::pair<int, int> > pairs;

    for(size_t i = 0; i + 1 < values.size(); i += 2)
    {
        if (values[i] > values[i + 1])
            pairs.push_back(std::make_pair(values[i + 1], values[i]));
        else
            pairs.push_back(std::make_pair(values[i], values[i + 1]));
    }
    if (values.size() % 2)
    {
        _oddSequence = true;
        _straggler = values.back();
    }

    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].second);

    fordJhonsonVector(winners);
    sortPairsVector(pairs, winners);

    std::vector<int> sorted;
    sorted.push_back(pairs[0].first);
    for (size_t i = 0; i < pairs.size(); ++i)
        sorted.push_back(pairs[i].second);

    insertLosersVector(sorted, pairs);
    
    return (sorted);
}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

void sortPairsDeque(std::deque<std::pair<int, int> >& pairs, const std::deque<int>& winners)
{
    std::deque<std::pair<int, int> > ordered;
    std::deque<std::pair<int, int> > remain(pairs);

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

std::deque<int> getJacobOrderDeque(int size)
{
    std::deque<int> order;
    int prev = 1, curr = 3, bigger, next;

    while (prev < size)
    {
        if (curr < size)
            bigger = curr;
        else
            bigger = size;

        for (int i = bigger; i > prev; --i)
            order.push_back(i);

        next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }

    return (order);
}

void PmergeMe::insertLosersDeque(std::deque<int>& sorted, std::deque<std::pair<int, int> >& pairs)
{
    int loserSize = pairs.size();
    if (_oddSequence)
        ++loserSize;

    int winner, loser;
    std::deque<int>::iterator binarySearch, pos; 
    std::deque<int> jacobsthal = getJacobOrderDeque(loserSize);

    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        std::size_t bNumber = static_cast<std::size_t>(jacobsthal[i]);
        if (bNumber <= pairs.size())
        {
            loser = pairs[bNumber - 1].first;
            winner = pairs[bNumber - 1].second;

            binarySearch = std::find(sorted.begin(), sorted.end(), winner);
        }
        else
        {
            loser = _straggler;
            binarySearch = sorted.end();
        }

        pos = std::lower_bound(sorted.begin(), binarySearch, loser);
        sorted.insert(pos, loser);
    }
}

std::deque<int> PmergeMe::fordJhonsonDeque(std::deque<int>& values)
{
    if (values.size() <= 1)
        return (values);

    std::deque<std::pair<int, int> > pairs;

    for(size_t i = 0; i + 1 < values.size(); i += 2)
    {
        if (values[i] > values[i + 1])
            pairs.push_back(std::make_pair(values[i + 1], values[i]));
        else
            pairs.push_back(std::make_pair(values[i], values[i + 1]));
    }
    if (values.size() % 2)
    {
        _oddSequence = true;
        _straggler = values.back();
    }

    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].second);

    fordJhonsonDeque(winners);
    sortPairsDeque(pairs, winners);

    std::deque<int> sorted;
    sorted.push_back(pairs[0].first);
    for (size_t i = 0; i < pairs.size(); ++i)
        sorted.push_back(pairs[i].second);

    insertLosersDeque(sorted, pairs);
    
    return (sorted);
}

const std::vector<int>& PmergeMe::getVector() const { return (_vector); }

const std::deque<int>& PmergeMe::getDeque() const { return (_deque); }
